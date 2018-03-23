#include "TPolinom.h"

TPolinom::TPolinom() : THeadList() {
	pHead->value.coeff = 0;
	pHead->value.x = pHead->value.y = pHead->value.z = -1;
}

TPolinom::TPolinom(TMonom *tm, int size) : THeadList()
{
	pHead->value.coeff = 0;
	pHead->value.x = pHead->value.y = pHead->value.z = -1;
	InsertFirst(tm[0]);
	for (int i = 1; i < size; i++)
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

TPolinom::TPolinom(std::string str) : THeadList() {
	FromString(str);
}

void TPolinom::ClearTPolinom() {
	if (IsEmpty()) {
		return;
	}

	for (Reset(); !IsEnd(); GoNext()) {
		DelCurrent();
	}
}

TPolinom& TPolinom::operator=(TPolinom& P) {
	for (Reset(); !IsEnd(); GoNext()) {
		DelCurrent();
	}

	for (P.Reset(); !P.IsEnd(); P.GoNext()) {
		InsertCurrent(P.pCurrent->value);
	}

	return *this;
}

void TPolinom::InsertByOrder(TMonom& tm) {
	if (IsEmpty()) {
		InsertFirst(tm);
	}
	else {

		for (Reset(); !IsEnd(); GoNext()) {
			if (pCurrent->value < tm) {
				InsertCurrent(tm);
				return;
			}

			if (pCurrent->value == tm) {
				pCurrent->value.coeff += tm.coeff;

				if (pCurrent->value.coeff = 0) {
					DelCurrent();
				}
				return;
			}
		}
		InsertLast(tm);
	}
}

TPolinom& TPolinom::operator*(const double c) {
	TPolinom *tmp(this);

	for (Reset(); !IsEnd(); GoNext()) {
		tmp->pCurrent->value.coeff *= c;
	}

	return *tmp;
}

TPolinom& TPolinom::operator*(TMonom &tm) {
	TPolinom *tmp(this);

	for (Reset(); !IsEnd(); GoNext()) {
		tmp->pCurrent->value.coeff *= tm.coeff;
		
		tmp->pCurrent->value.x += tm.x;
		tmp->pCurrent->value.y += tm.y;
		tmp->pCurrent->value.z += tm.z;
	}

	return *tmp;
}

TPolinom& TPolinom::operator+(TPolinom &q) {
	TPolinom *tmp = new TPolinom(*this);
	
	tmp->Reset();
	q.Reset();

	while ((!q.IsEnd()) || (!tmp->IsEnd())) {
		if (tmp->pCurrent->value == q.pCurrent->value) {
			tmp->pCurrent->value.coeff += q.pCurrent->value.coeff;
			if (tmp->pCurrent->value.coeff == 0) {
				tmp->DelCurrent();
				q.GoNext();
				continue;
			}
			else {
				tmp->GoNext();
				q.GoNext();
			}
		}

		if (tmp->pCurrent->value < q.pCurrent->value) {
			tmp->InsertCurrent(q.pCurrent->value);
			q.GoNext();
		}

		if (tmp->pCurrent->value > q.pCurrent->value) {
			tmp->GoNext();
		}
	}

	return *tmp;
}

TPolinom& TPolinom::operator-(TPolinom &q) {
	TPolinom *tmp = new TPolinom(*this);

	tmp->Reset();
	q.Reset();

	while ((!q.IsEnd()) || (!tmp->IsEnd())) {
		if (tmp->pCurrent->value == q.pCurrent->value) {
			tmp->pCurrent->value.coeff -= q.pCurrent->value.coeff;
			if (tmp->pCurrent->value.coeff == 0) {
				tmp->DelCurrent();
				q.GoNext();
				continue;
			}
			else {
				tmp->GoNext();
				q.GoNext();
			}
		}

		if (tmp->pCurrent->value < q.pCurrent->value) {
			TMonom tmpMonom = q.pCurrent->value;
			
			tmpMonom.coeff = -tmpMonom.coeff;
			tmp->InsertCurrent(tmpMonom);
			q.GoNext();
		}

		if (tmp->pCurrent->value > q.pCurrent->value) {
			tmp->GoNext();
		}
	}

	return *tmp;
}

TPolinom& TPolinom::operator+(TMonom &tm) {
	TPolinom *tmp = new TPolinom(*this);

	tmp->InsertByOrder(tm);

	return *tmp;
}

TPolinom& TPolinom::operator-(TMonom &tm) {
	TPolinom *tmp = new TPolinom(*this);
	TMonom tmpMonom = tm;
	tmpMonom.coeff = -tmpMonom.coeff;

	tmp->InsertByOrder(tmpMonom);

	return *tmp;
}

TPolinom& TPolinom::operator*=(const double c) {
	return TPolinom();
}

TPolinom& TPolinom::operator*=(TMonom &tm) {
	return TPolinom();
}

TPolinom& TPolinom::operator+=(TPolinom &q) {
	Reset();
	q.Reset();

	while ((!q.IsEnd()) || (!IsEnd())) {
		if (pCurrent->value == q.pCurrent->value) {
			pCurrent->value.coeff = q.pCurrent->value.coeff;
			if (pCurrent->value.coeff == 0) {
				DelCurrent();
				q.GoNext();
				continue;
			}
			else {
				GoNext();
				q.GoNext();
			}
		}

		if (pCurrent->value < q.pCurrent->value) {
			InsertCurrent(q.pCurrent->value);
			q.GoNext();
		}

		if (pCurrent->value > q.pCurrent->value) {
			GoNext();
		}
	}

	return *this;
}

TPolinom& TPolinom::operator-=(TPolinom &q) {
	Reset();
	q.Reset();

	while ((!q.IsEnd()) || (!IsEnd())) {
		if (pCurrent->value == q.pCurrent->value) {
			pCurrent->value.coeff -= q.pCurrent->value.coeff;
			if (pCurrent->value.coeff == 0) {
				DelCurrent();
				q.GoNext();
				continue;
			}
			else {
				GoNext();
				q.GoNext();
			}
		}

		if (pCurrent->value < q.pCurrent->value) {
			TMonom tmpMonom = q.pCurrent->value;

			tmpMonom.coeff = -tmpMonom.coeff;
			InsertCurrent(tmpMonom);
			q.GoNext();
		}

		if (pCurrent->value > q.pCurrent->value) {
			GoNext();
		}
	}

	return *this;
}

TPolinom& TPolinom::operator+=(TMonom &tm) {
	InsertByOrder(tm);

	return *this;
}
TPolinom& TPolinom::operator-=(TMonom &tm) {
	TMonom tmpMonom = tm;
	tmpMonom.coeff = -tmpMonom.coeff;

	InsertByOrder(tmpMonom);

	return *this;
}

//bool TPolinom::operator==(TPolinom &q) {
//	return true;
//}
//
//bool TPolinom::operator!=(TPolinom &q) {
//	return true;
//}

void TPolinom::FromString(std::string str) {
	std::string tmp = "";
	size_t strLen = str.length();
	str = str;
	bool sign = 0; // 0 - plus, 1 - minus

	for (size_t i = 0; i < strLen; i++) {
		if (!((str[i] == '+') ||
			(str[i] == '-') ||
			(str[i] == '^') ||
			(str[i] == 'x') ||
			(str[i] == 'y') ||
			(str[i] == 'z') ||
			(str[i] <= '9' && str[i] >= '0'))
			) 
		{
			str[i] = '\0';
		}
	}

	for (size_t i = 0; i < strLen; i++) {
		if (str[i] == '+') {
			sign = 0;
			continue;
		}
		
		if (str[i] == '-') {
			sign = 1;
			continue;
		}

		if ((str[i] == 'x') || (str[i] == 'y') || (str[i] == 'z') || ((str[i] <= '9') && (str[i] >= '0'))) {
			while (1) {
				if (i == strLen) {
					break;
				}

				tmp += str[i];
				
				if (i + 1 < strLen) {
					if ((str[i + 1] == '+') || (str[i + 1] == '-')) {
						break;
					}
				}
				i++;
			}
			if (sign) {
				tmp = '-' + tmp;
			}
			InsertByOrder(TMonom(tmp));
			tmp = "";
		}
	}

}

std::istream& operator >> (std::istream &in, TPolinom &P) {
	return in;
}
std::ostream& operator <<(std::ostream &out, TPolinom &P) {
	return out;
}

bool operator==(const TPolinom &q, const TPolinom &p) {
	TLink<TMonom>* pQcur = q.pFirst;
	TLink<TMonom>* pPcur = p.pFirst;

	while ((pPcur != p.pStop) || (pQcur != q.pStop)) {
		if (pQcur->value != pPcur->value) { 
			return false;
		}

		pQcur = pQcur->pNext;
		pPcur = pPcur->pNext;
	}
	return true;
}
bool operator!=(const TPolinom &q, const TPolinom &p) {
	TLink<TMonom>* pQcur = q.pFirst;
	TLink<TMonom>* pPcur = p.pFirst;

	while ((pPcur != p.pStop) || (pQcur != q.pStop)) {
		if (pQcur->value != pPcur->value) {
			return true;
		}

		pQcur = pQcur->pNext;
		pPcur = pPcur->pNext;
	}
	return false;
}