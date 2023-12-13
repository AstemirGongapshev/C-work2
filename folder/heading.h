#pragma once

struct Result {
	double average;
	double min;
	double max;
};

Result init(int size);
void fill_random(double* arr1, double* arr2, double* arr3, int size);
void get_average_min_max(double* arr, double* avg, double* min, double* max, int size);
