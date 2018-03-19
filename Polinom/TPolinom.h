#pragma once
#include "THeadList.h"
#include <iostream>

struct TMonom
{
	int coeff;
	int x, y, z;

	TMonom();
	TMonom(int _coeff, int _x, int _y, int _z);
	TMonom(std::string str);
};

bool operator<(const TMonom& t1, const TMonom& t2) {
	return (t1.x * 100 + t1.y * 10 + t1.z) < (t2.x * 100 + t2.y * 10 + t2.z);
}

bool operator>(const TMonom& t1, const TMonom& t2) {
	return (t1.x * 100 + t1.y * 10 + t1.z) > (t2.x * 100 + t2.y * 10 + t2.z);
}

bool operator==(const TMonom& t1, const TMonom& t2) {
	return (t1.coeff == t2.coeff) &&
		((t1.x * 100 + t1.y * 10 + t1.z) == 
		(t2.x * 100 + t2.y * 10 + t2.z));
}

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

	void operator*=(const double c);
	void operator*=(TMonom &tm);
	
	void operator+=(TPolinom &q);
	void operator-=(TPolinom &q);

	void operator+=(TMonom &tm);
	void operator-=(TMonom &tm);

	bool operator==(TPolinom &q);
	bool operator!=(TPolinom &q);

	friend std::istream& operator >> (std::istream &in, TPolinom &P);
	friend std::ostream& operator <<(std::ostream &out, TPolinom &P);
};

