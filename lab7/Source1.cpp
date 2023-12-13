#include "Lab_7.h"
#include <algorithm>
#include <iostream>

void CoinWallet::addCoinByName(const std::string& name, double value) {
	Coin coin = { name, value };
	wallet.push_back(coin);
}

void CoinWallet::addCoinByValue(const std::string& name, double value) {
	Coin coin = { name, value };
	wallet.push_back(coin);
	std::sort(wallet.begin(), wallet.end(), [](const Coin& a, const Coin& b) {
		return a.value < b.value;
	});
}

void CoinWallet::removeCoinByName(const std::string& name) {
	wallet.erase(std::remove_if(wallet.begin(), wallet.end(), [name](const Coin& coin) {
		return coin.name == name;
	}), wallet.end());
}

void CoinWallet::removeCoinByValue(double value) {
	wallet.erase(std::remove_if(wallet.begin(), wallet.end(), [value](const Coin& coin) {
		return coin.value == value;
	}), wallet.end());
}

int CoinWallet::countUniqueCoins() {
	std::vector<std::string> uniqueNames;
	for (const Coin& coin : wallet) {
		if (std::find(uniqueNames.begin(), uniqueNames.end(), coin.name) == uniqueNames.end()) {
			uniqueNames.push_back(coin.name);
		}
	}
	return static_cast<int>(uniqueNames.size());
}

std::vector<Coin> CoinWallet::findCoinByName(const std::string& name) {
	std::vector<Coin> result;
	for (const Coin& coin : wallet) {
		if (coin.name == name) {
			result.push_back(coin);
		}
	}
	return result;
}

std::vector<Coin> CoinWallet::findCoinByValue(double value) {
	std::vector<Coin> result;
	for (const Coin& coin : wallet) {
		if (coin.value == value) {
			result.push_back(coin);
		}
	}
	return result;
}

void CoinWallet::viewWalletStructure() {
	for (const Coin& coin : wallet) {
		std::cout << "Coin: " << coin.name << ", Value: " << coin.value << std::endl;
	}
}
