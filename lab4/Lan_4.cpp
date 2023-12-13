#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	ifstream inputFile("C:\\Users\\User\\Desktop\\Новая папка (2)\\Lan_4\\Lan_4\\input.txt");
	ofstream outputFile("C:\\Users\\User\\Desktop\\Новая папка (2)\\Lan_4\\Lan_4\\output.txt");

	if (!inputFile.is_open() || !outputFile.is_open()) {
		cerr << "Error: Unable to open input.txt or output.txt" << endl;
		system("pause");
		return 1;
	}

	double S0;
	int count = 100;
	double r = 0.05;
	double sigma = 0.2;
	double t = 2.0;
	double K = 50.0;

	inputFile >> S0;

	srand(time(NULL)); 

	vector<double> z(count);
	for (int i = 0; i < count; i++) {
		z[i] = ((double)rand() / RAND_MAX);
	}

	double min_z = *min_element(z.begin(), z.end());
	double max_z = *max_element(z.begin(), z.end());

	for (int i = 0; i < count; i++) {
		z[i] = (z[i] - min_z) / (max_z - min_z);
	}

	vector<double> si_arr(count, 0.0);
	vector<double> ci_arr(count, 0.0);

	for (int i = 0; i < count; i++) {
		si_arr[i] = S0 * exp((r - 0.5 * sigma * sigma) + sigma * t * t * z[i]);
		ci_arr[i] = max(si_arr[i] - K, 0.0) * exp(-r * t);
		outputFile << si_arr[i] << " " << ci_arr[i] << endl;
		//cout << z[i] << " ";
	}


	//double ci_arr_mean = \\(ci_arr.begin(), ci_arr.end(), 0.0);
	double counter = 0.0;
	for (int i = 0; i < ci_arr.size(); i++) {
		counter += ci_arr[i];
	}
	double ci_arr_mean = counter / 5;
	
	cout << "Массив цен: ";
	for (int i = 0; i < si_arr.size(); i++) {
		cout << si_arr[i] << " " ;
	}
	cout << endl;




	cout << "Среднее: " << ci_arr_mean / count << endl;
	
	inputFile.close();
	outputFile.close();
	system("pause");

	return 0;
}
