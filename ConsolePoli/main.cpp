#include "../Polinom/TPolinom.h"
#include "../Polinom/TPolinom.cpp"

int main() {

	TPolinom P, Q;

	std::cout << "Input P: ";
	std::cin >> P;

	std::cout << "Input Q: ";
	std::cin >> Q;

	std::cout << "Result = " << (P + Q).ToString();

	return 0;
}