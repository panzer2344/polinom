#pragma once
#include "THeadList.h"


struct TMonom
{
	int coeff;
	int x, y, z;
};

bool operator<(const TMonom& t1, const TMonom& t2) {
	return (t1.x * 100 + t1.y * 10 + t1.z) < (t2.x * 100 + t2.y * 10 + t2.z);
}

bool operator>(const TMonom& t1, const TMonom& t2) {
	return (t1.x * 100 + t1.y * 10 + t1.z) > (t2.x * 100 + t2.y * 10 + t2.z);
}

class TPolinom : public THeadList<TMonom> {
public:
	TPolinom() : THeadList() {
		pHead->value.coeff = 0;
		pHead->value.x = pHead->value.y = pHead->value.z = -1;
	}
};

