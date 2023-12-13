#include <iostream>
#include <fstream>
#include <string>
#include "Vector3D.h"

int main() {
	setlocale(LC_ALL, "Russian");

	std::ifstream inputFile("C:\\Users\\User\\Desktop\\Новая папка (2)\\Lab_5\\Lab_5\\input.txt");
	if (!inputFile.is_open()) {
		std::cerr << "Не удалось открыть файл input.txt" << std::endl;
		return 1;
	}

	
	std::string line1, line2;
	if (!std::getline(inputFile, line1) || !std::getline(inputFile, line2)) {
		std::cerr << "Недостаточно строк в файле input.txt" << std::endl;
		return 1;
	}

	Vector3D vec1, vec2;

	
	int x1, y1, z1, x2, y2, z2;
	if (sscanf(line1.c_str(), "%d %d %d", &x1, &y1, &z1) != 3 ||
		sscanf(line2.c_str(), "%d %d %d", &x2, &y2, &z2) != 3) {
		std::cerr << "Ошибка в формате данных в файле input.txt" << std::endl;
		return 1;
	}

	vec1.setX(x1);
	vec1.setY(y1);
	vec1.setZ(z1);

	vec2.setX(x2);
	vec2.setY(y2);
	vec2.setZ(z2);

	
	Vector3D sum = vec1 + vec2;
	Vector3D diff = vec1 - vec2;
	Vector3D scalarProduct = vec1 * 2;
	Vector3D crossProduct = vec1.crossProduct(vec2);

	
	std::cout << "Сумма векторов: " << sum << std::endl;
	std::cout << "Разность векторов: " << diff << std::endl;
	std::cout << "Произведение на скаляр: " << scalarProduct << std::endl;
	std::cout << "Векторное произведение: " << crossProduct << std::endl;

	
	std::ofstream outputFile("output.txt");
	if (!outputFile.is_open()) {
		std::cerr << "Не удалось открыть файл output.txt" << std::endl;
		return 1;
	}

	outputFile << "Сумма векторов: " << sum << std::endl;
	outputFile << "Разность векторов: " << diff << std::endl;
	outputFile << "Произведение на скаляр: " << scalarProduct << std::endl;
	outputFile << "Векторное произведение: " << crossProduct << std::endl;

	return 0;
}
