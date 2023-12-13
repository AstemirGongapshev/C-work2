
#pragma once
#endif // COIN_H
#include "Lab_7.h"
#include <vector>
#include <string>

struct Coin {
	std::string name;
	double value;
};



class CoinWallet {
private:
	std::vector<Coin> wallet;

public:
	void addCoinByName(const std::string& name, double value);
	void addCoinByValue(const std::string& name, double value);
	void removeCoinByName(const std::string& name);
	void removeCoinByValue(double value);
	int countUniqueCoins();
	std::vector<Coin> findCoinByName(const std::string& name);
	std::vector<Coin> findCoinByValue(double value);
	void viewWalletStructure();
};


