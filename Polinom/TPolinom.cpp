#include "TPolinom.h"

TPolinom::TPolinom() : THeadList() {
	pHead->value.coeff = 0;
	pHead->value.x = pHead->value.y = pHead->value.z = -1;
}

TPolinom::TPolinom(TMonom *tm, int size) : THeadList()
{
	pHead->value.coeff = 0;
	pHead->value.x = pHead->value.y = pHead->value.z = -1;
	for (int i = 0; i < size; i++)
		InsertByOrder(tm[i]);
}

TPolinom::TPolinom(TPolinom& tm) : THeadList() {
	pHead->value.coeff = 0;
	pHead->value.x = pHead->value.y = pHead->value.z = -1;

	Reset();
	for (tm.Reset(); !tm.IsEnd(); tm.GoNext()) {
		this->InsertByOrder(tm.GetCurrent());
	}
}

void TPolinom::ClearTPolinom() {}

TPolinom& TPolinom::operator=(TPolinom& P) {
	return TPolinom();
}

void TPolinom::InsertByOrder(TMonom& tm) {
}

TPolinom& TPolinom::operator*(const double c) {
	return TPolinom();
}

TPolinom& TPolinom::operator*(TMonom &tm) {
	return TPolinom();
}

TPolinom& TPolinom::operator+(TPolinom &q) {
	return TPolinom();
}

TPolinom& TPolinom::TPolinom::operator-(TPolinom &q) {
	return TPolinom();
}

TPolinom& TPolinom::operator+(TMonom &tm) {
	return TPolinom();
}

TPolinom& TPolinom::operator-(TMonom &tm) {
	return TPolinom();
}

void TPolinom::operator*=(const double c) {}
void TPolinom::operator*=(TMonom &tm) {}

void TPolinom::operator+=(TPolinom &q) {}
void TPolinom::operator-=(TPolinom &q) {}

void TPolinom::operator+=(TMonom &tm) {}
void TPolinom::operator-=(TMonom &tm) {}

std::istream& operator >> (std::istream &in, TPolinom &P) {
	return in;
}
std::ostream& operator <<(std::ostream &out, TPolinom &P) {
	return out;
}