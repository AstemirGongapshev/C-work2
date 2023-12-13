#include "heading.h"
#include <cstdlib>
#include <ctime>

Result init(int size) {
	double* arr1 = new double[size];
	double* arr2 = new double[size];
	double* arr3 = new double[size];

	fill_random(arr1, arr2, arr3, size);

	double avg, max, min;
	get_average_min_max(arr3, &avg, &min, &max, size);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	Result result;
	result.average = avg;
	result.min = min;
	result.max = max;

	return result;
}

void fill_random(double* arr1, double* arr2, double* arr3, int size) {
	srand(static_cast<unsigned>(std::time(nullptr)));
	for (int i = 0; i < size; i++) {
		double value1 = static_cast<double>(std::rand()) / RAND_MAX;
		double value2 = static_cast<double>(std::rand()) / RAND_MAX;
		arr1[i] = static_cast<int>(value1 * 10 + 0.5) / 10.0;
		arr2[i] = static_cast<int>(value2 * 10 + 0.5) / 10.0;
		arr3[i] = arr1[i] + arr2[i];
	}
}

void get_average_min_max(double* arr, double* avg, double* min, double* max, int size) {
	*avg = 0;
	*max = arr[0];
	*min = arr[0];
	for (int i = 0; i < size; i++) {
		*avg += arr[i];
		if (arr[i] > *max) {
			*max = arr[i];
		}
		if (arr[i] < *min) {
			*min = arr[i];
		}
	}

	*avg = *avg / static_cast<double>(size);
}
