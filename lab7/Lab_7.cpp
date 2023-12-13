#include "Lab_7.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	CoinWallet wallet;

	while (true) {
		std::cout << "\nВыберите действие:\n"
			<< "1. Добавить монету по названию\n"
			<< "2. Добавить монету по возрастанию ценности\n"
			<< "3. Удалить монету по названию\n"
			<< "4. Удалить монету по ценности\n"
			<< "5. Подсчет суммы кол-ва уникальных монет\n"
			<< "6. Поиск монеты по названию\n"
			<< "7. Поиск монеты по ценности\n"
			<< "8. Просмотр структуры кошелька\n"
			<< "0. Выйти\n";

		int choice;
		std::cin >> choice;

		switch (choice) {
		case 1: {
			std::string name;
			double value;
			std::cout << "Введите название монеты: ";
			std::cin >> name;
			std::cout << "Введите ценность монеты: ";
			std::cin >> value;
			wallet.addCoinByName(name, value);
			break;
		}
		case 2: {
			std::string name;
			double value;
			std::cout << "Введите название монеты: ";
			std::cin >> name;
			std::cout << "Введите ценность монеты: ";
			std::cin >> value;
			wallet.addCoinByValue(name, value);
			break;
		}
		case 3: {
			std::string name;
			std::cout << "Введите название монеты, которую нужно удалить: ";
			std::cin >> name;
			wallet.removeCoinByName(name);
			break;
		}
		case 4: {
			double value;
			std::cout << "Введите ценность монеты, которую нужно удалить: ";
			std::cin >> value;
			wallet.removeCoinByValue(value);
			break;
		}
		case 5: {
			int count = wallet.countUniqueCoins();
			std::cout << "Количество уникальных монет: " << count << std::endl;
			break;
		}
		case 6: {
			std::string name;
			std::cout << "Введите название монеты для поиска: ";
			std::cin >> name;
			std::vector<Coin> result = wallet.findCoinByName(name);
			if (result.empty()) {
				std::cout << "Монета не найдена" << std::endl;
			}
			else {
				for (const Coin& coin : result) {
					std::cout << "Coin: " << coin.name << ", Value: " << coin.value << std::endl;
				}
			}
			break;
		}
		case 7: {
			double value;
			std::cout << "Введите ценность монеты для поиска: ";
			std::cin >> value;
			std::vector<Coin> result = wallet.findCoinByValue(value);
			if (result.empty()) {
				std::cout << "Монета не найдена" << std::endl;
			}
			else {
				for (const Coin& coin : result) {
					std::cout << "Coin: " << coin.name << ", Value: " << coin.value << std::endl;
				}
			}
			break;
		}
		case 8: {
			wallet.viewWalletStructure();
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			std::cout << "Некорректный ввод. Пожалуйста, введите число от 0 до 8." << std::endl;
			break;
		}
		}
	}
	system("pause");
	return 0;
}
