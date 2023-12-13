#include <iostream>
#include <fstream>
#include <regex>
using namespace std;
int main() {

	setlocale(LC_ALL, "Russian");
	
	
	ifstream inputFile("C:\\Users\\User\\Desktop\\Новая папка (2)\\Lab_6\\Lab_6\\input.txt");


	if (!inputFile.is_open()) {
		cerr << "Не удается открыть файл" << endl;
		return 1;
	}

	
	regex floatingPointRegex(R"([+-]?\d*\.\d)");
	regex exponentialRegex(R"([+-]?\d+\e-1)");



	string line;


	while (getline(inputFile, line)) {
	
		smatch matches;

		
		string::const_iterator searchStart(line.cbegin());
	

		while (regex_search(searchStart, line.cend(), matches, floatingPointRegex)) {
		
			cout <<  matches[0] << endl;
			searchStart = matches.suffix().first;
		}

		//cout << line << endl;

		
		searchStart = line.cbegin(); 
		

		while (regex_search(searchStart, line.cend(), matches, exponentialRegex)) {
		
			cout << matches[0] << endl;
			
			searchStart = matches.suffix().first;
		}
		
	}

	
	inputFile.close();

	system("pause");

	return 0;
}
