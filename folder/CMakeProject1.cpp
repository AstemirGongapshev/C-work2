#include <iostream>
#include "heading.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите размер массива: ";
	cin >> size;

	Result result = init(size);

	cout << "Среднее значение: " << result.average << endl;
	cout << "Минимальное значение: " << result.min << endl;
	cout << "Максимальное значение: " << result.max << endl;

	system("pause");
	return 0;
}
