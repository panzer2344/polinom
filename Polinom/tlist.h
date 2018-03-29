#pragma once
#include <iostream>
//#include "stdafx.h"

template<class T>
struct TLink {
	T value;
	TLink *pNext;
};

template<class T>
class TList {
protected:
	TLink<T> *pFirst, *pPrev, *pCurrent, *pStop, *pLast;
	int size, pos;

public:
	
	TList(){
		pFirst = pPrev = pCurrent = pStop = pLast = NULL;
		size = 0; pos = -1;
	}
	
	void InsertFirst(const T& element);
	void InsertLast(const T& element);
	void InsertCurrent(const T& element);
	void Reset();
	void GoNext();
	bool IsEnd();
	bool IsEmpty();
	void DelFirst();
	void DelLast();
	void DelCurrent();

	T GetCurrent();
	T GetFirst();
	T GetLast();

	T operator[](int index);
	void Sort();
	void SortInput(T element);
};

template<class T>
void TList<T>::InsertFirst(const T& element) {
	TLink<T> *tmp = new TLink<T>;
	tmp->value = element;
	tmp->pNext = pFirst;
	if (size == 0) {
		pFirst = pLast = pCurrent = tmp;
		pos = 0;
	}
	else {
		pFirst = tmp;
		pos++;
	}
	size++;
}

template<class T>
void TList<T>::InsertLast(const T& element) {
	TLink<T> *tmp = new TLink<T>;
	tmp->value = element;
	tmp->pNext = pStop;
	if (pFirst == pStop) {
		pFirst = pPrev = pLast = pCurrent = tmp;
		pos = 0;
	}
	else {
		pLast->pNext = tmp;
		pLast = tmp;
	}
	size++;
}

template<class T>
void TList<T>::InsertCurrent(const T& element) {
	//if (size == 0 || pCurrent->pNext == pFirst) {
	if(size == 0){
		InsertFirst(element);
	}
	else {
		TLink<T> *tmp = new TLink<T>;

		//tmp->value = element;
		//tmp->pNext = pCurrent;

		tmp->value = element;
		tmp->pNext = pCurrent;

		if (pPrev != pStop) {
			pPrev->pNext = tmp;
		}
		else {
			pFirst = tmp;
		}

		if (pCurrent == pStop) pLast = tmp;
		if (pCurrent == pFirst) pFirst = tmp;
		pCurrent = tmp;
		size++;
	}
}

template<class T>
void TList<T>::Reset() {
	pCurrent = pPrev = pFirst;
	pos = 0;
}

template<class T>
void TList<T>::GoNext() {
	pPrev = pCurrent;
	pCurrent = pCurrent->pNext;
	pos++;
}

template<class T>
bool TList<T>::IsEnd() {
	return pCurrent == pStop;
}

template<class T>
bool TList<T>::IsEmpty() {
	return pFirst == pStop;
}

template<class T>
void TList<T>::DelFirst() {
	if (size == 1) {
		delete pFirst;
		pFirst = pCurrent = pLast = pPrev = pStop;
	}
	else {
		TLink<T> *pOld = pFirst;
		pFirst = pOld->pNext;
		delete pOld;
		size--;
	}
	if (pos > 0) pos--; 
}

template<class T>
void TList<T>::DelLast() {
	Reset();
	while (pCurrent->pNext != pStop) GoNext();
	delete pCurrent;
	pLast = pCurrent = pPrev;
	size--;
	Reset();
}

template<class T>
void TList<T>::DelCurrent() {
	if (pCurrent == pFirst) {
		DelFirst();
		pCurrent = pFirst;
	}
	else
	{
		pPrev->pNext = pCurrent->pNext;
		delete pCurrent;
		pCurrent = pPrev->pNext;
		size--;
	}
}

template<class T>
T TList<T>::GetCurrent() {
	if (IsEmpty()) throw "cant get element from empty list";
	return pCurrent->value;
}

template<class T>
T TList<T>::GetFirst() {
	if (IsEmpty()) throw "cant get element from empty list";
	return pFirst->value;
}

template<class T>
T TList<T>::GetLast() {
	if (IsEmpty()) throw "cant get element from empty list";
	return pLast->value;
}

template<class T>
T TList<T>::operator[](int index) {
	Reset();
	while(!IsEnd()){
		if (pos == index - 1)
			return pCurr->val;
		goNext();
	}
}

template<class T>
void TList<T>::SortInput(T element) {
	if (pFirst == pStop || element < pFirst->value) {
		InsertFirst(element);
		return;
	}
	if (element > pLast->value) {
		InsertLast(element);
		return;
	}
	
	Reset();
	while(!IsEnd()){
		if (pCurrent->value > element) { 
			InsertCurrent(element);
			return; 
		}
		GoNext();
	}
}

template<class T>
void TList<T>::Sort() {
	T tmp;

	for (int i = 0; i < size - 1; i++) {
		Reset();
		for (int j = 0; j < size - 1 - i; j++) {
			GoNext();
			if (pPrev->value > pCurrent->value) {
				tmp = pCurrent->value;
				pCurrent->value = pPrev->value;
				pPrev->value = tmp;
			}
		}
	}
}