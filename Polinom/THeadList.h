#pragma once
#include "tlist.h"

template<class T>
class THeadList : public TList<T> {
protected:
	TLink<T> *pHead;
public:
	THeadList() : TList() {
		pHead = new TLink<T>;
		pStop = pHead;
		pHead->pNext = pHead;
		pCurrent = pPrev = pLast = pFirst = pStop;
	}
	
	~THeadList() {
		TList<T>::~TList();
		delete pHead;
	}

	void InsertFirst(T element) {
		TList<T>::InsertFirst(element);
		pHead->pNext = pFirst;
	}

	void DelFirst() {
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}

	void InsertLast(T element) {
		TList<T>::InsertLast(element);
		pLast->pNext = pHead;
	}

	void DelLast() {
		TList<T>::DelFirst();
		pLast->pNext = pHead;
	}
};
