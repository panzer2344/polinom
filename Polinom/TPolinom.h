#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <iostream>
#include <string>
#include <regex>



class TPolinom : public THeadList<TMonom> {
public:
	TPolinom();
	TPolinom(TMonom *tm, int size);
	TPolinom(TPolinom& tm);
	TPolinom(std::string str);

	void ClearTPolinom();

	TPolinom& operator=(TPolinom& P);

	void InsertByOrder(TMonom& tm);
	void FromString(std::string str);
	
	TPolinom& operator*(const double c);
	TPolinom& operator*(TMonom &tm);

	TPolinom& operator+(TPolinom &q);
	TPolinom& operator-(TPolinom &q);

	TPolinom& operator+(TMonom &tm);
	TPolinom& operator-(TMonom &tm);

	TPolinom& operator*=(const double c);
	TPolinom& operator*=(TMonom &tm);
	
	TPolinom& operator+=(TPolinom &q);
	TPolinom& operator-=(TPolinom &q);

	TPolinom& operator+=(TMonom &tm);
	TPolinom& operator-=(TMonom &tm);

	//bool operator==(TPolinom &q);
	//bool operator!=(TPolinom &q);

	friend bool operator==(const TPolinom &q, const TPolinom &p);
	friend bool operator!=(const TPolinom &q, const TPolinom &p);

	friend std::istream& operator >> (std::istream &in, TPolinom &P);
	friend std::ostream& operator <<(std::ostream &out, TPolinom &P);
};

