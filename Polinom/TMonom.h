#pragma once
#include <iostream>
#include <string>
#include <regex>


struct TMonom
{
	int coeff;
	int x, y, z;

	TMonom();
	TMonom(int _coeff, int _x, int _y, int _z);
	TMonom(std::string str);
	int GetCooef(std::string &s);
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
		result = std::stoi(coeffStr);
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

	while (strLen != 0) {

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



	/*	int strLen = str.length();
	std::string tmpStr = "";
	int i = 0;

	while (i < strLen) {
	if (!((str[i] > '0') &&
	(str[i] < '9') ||
	(str[i] == '^') ||
	(str[i] == 'x') ||
	(str[i] == 'y') ||
	(str[i] == 'z')
	)) str[i] = '\0';
	i++;
	}

	for (i = 0; i < strLen; i++) {
	while ((str[i] < '9') && (str[i] > '0')) {
	tmpStr += str[i];
	i++;
	}
	if (tmpStr != "") {
	coeff = std::stoi(str);
	tmpStr = "";
	}
	else {
	coeff = 1;
	}

	if (str[i] == 'x') {
	i++;
	if (str[i] == '^') {
	i++;
	while ((str[i] < '9') && (str[i] > '0')) {
	tmpStr += str[i];
	i++;
	}
	if (tmpStr != "") {
	x = std::stoi(str);
	tmpStr = "";
	}
	}
	else {
	x = 1;
	}
	}

	if (str[i] == 'y') {
	i++;
	if (str[i] == '^') {
	i++;
	while ((str[i] < '9') && (str[i] > '0')) {
	tmpStr += str[i];
	i++;
	}
	if (tmpStr != "") {
	y = std::stoi(str);
	tmpStr = "";
	}
	}
	else {
	y = 1;
	}
	}

	if (str[i] == 'z') {
	i++;
	if (str[i] == '^') {
	i++;
	while ((str[i] < '9') && (str[i] > '0')) {
	tmpStr += str[i];
	i++;
	}
	if (tmpStr != "") {
	z = std::stoi(str);
	tmpStr = "";
	}
	}
	else {
	z = 1;
	}
	}
	}
	*/
}

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

bool operator!=(const TMonom& t1, const TMonom& t2) {
	return (t1.coeff != t2.coeff) &&
		((t1.x * 100 + t1.y * 10 + t1.z) !=
		(t2.x * 100 + t2.y * 10 + t2.z));
}