#pragma once
#ifndef __TMONOM_H__

#define __TMONOM_H__

#include <iostream>
#include <string>
#include <regex>
//#include "stdafx.h"

struct TMonom
{
	int coeff;
	int x, y, z;

	TMonom();
	TMonom(int _coeff, int _x, int _y, int _z);
	TMonom(std::string str);
	int GetCooef(std::string &s);
	std::string ToString();
};

TMonom::TMonom() {
	x = 0;
	y = 0;
	z = 0;
	coeff = 0;
}

TMonom::TMonom(int _coeff, int _x, int _y, int _z) {
	x = _x;
	y = _y;
	z = _z;
	coeff = _coeff;
}


int TMonom::GetCooef(std::string &s) {
	int result;
	std::regex coeffPattern("^[0-9,-]+");
	std::smatch matches;
	if (std::regex_search(s, matches, coeffPattern)) {
		std::string coeffStr = matches.str();
		if (coeffStr == "-") result = -1;
		else result = std::stoi(coeffStr);
		int coeffStrLength = coeffStr.length();
		s = s.substr(coeffStrLength, s.length() - coeffStrLength);
	}
	else {
		result = 1;
	}

	return result;
}

TMonom::TMonom(std::string str) {
	x = 0;
	y = 0;
	z = 0;
	coeff = 0;


	coeff = GetCooef(str);

	int strLen = str.length();

	while (strLen != 0 && str != "" && str != " ") {

		if (str[0] == 'x') {
			if (strLen > 1 && str[1] == '^') {
				str = str.substr(2, strLen - 2);
				x = GetCooef(str);
			}
			else {
				x = 1;
				str = str.substr(1, strLen - 1);
			}
		}
		else if (str[0] == 'y') {
			if (strLen > 1 && str[1] == '^') {
				str = str.substr(2, strLen - 2);
				y = GetCooef(str);
			}
			else {
				y = 1;
				str = str.substr(1, strLen - 1);
			}
		}
		else if (str[0] == 'z') {
			if (strLen > 1 && str[1] == '^') {
				str = str.substr(2, strLen - 2);
				z = GetCooef(str);
			}
			else {
				z = 1;
				str = str.substr(1, strLen - 1);
			}
		}

		strLen = str.length();
	}

}

std::string TMonom::ToString() {
	std::string result = "";


	if ( (coeff < -1) || (coeff > 1) || (((coeff == 1) || (coeff == -1)) && (x == 0) && (y == 0) && (z == 0))) { 
		result += std::to_string(coeff);
	}

	if (coeff != 0) {
		if (x > 0) result += "x";
		if (x > 1) {
			result += "^";
			result += std::to_string(x);
		}

		if (y > 0) result += "y";
		if (y > 1) {
			result += "^";
			result += std::to_string(y);
		}

		if (z > 0) result += "z";
		if (z > 1) {
			result += "^";
			result += std::to_string(z);
		}
	}
	return result;
}

bool operator<(const TMonom& t1, const TMonom& t2) {
	return (t1.x * 100 + t1.y * 10 + t1.z) < (t2.x * 100 + t2.y * 10 + t2.z);
}

bool operator>(const TMonom& t1, const TMonom& t2) {
	return (t1.x * 100 + t1.y * 10 + t1.z) > (t2.x * 100 + t2.y * 10 + t2.z);
}

bool operator==(const TMonom& t1, const TMonom& t2) {
	return (t1.x * 100 + t1.y * 10 + t1.z) == (t2.x * 100 + t2.y * 10 + t2.z);
}

bool operator!=(const TMonom& t1, const TMonom& t2) {
	return(t1.x * 100 + t1.y * 10 + t1.z) != (t2.x * 100 + t2.y * 10 + t2.z);
}

#endif // __TMONOM_H__