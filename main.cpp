
#include <iostream>
#include "fibonacci.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "Введите значение n: ";
	std::cin >> n;

	if (n < 0) {
		std::cout << "n должно быть неотрицательным числом." << std::endl;
		return 1;
	}

	int result = fibonacci(n);
	std::cout << "Число Фибоначчи для n = " << n << " равно " << result << std::endl;
	system("pause");
	return 0;
}

