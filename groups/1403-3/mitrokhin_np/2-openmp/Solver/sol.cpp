#include <iostream>

using namespace std;

void Insert(double* dataArray, int size, int start, int step) {
	for (int i = start + step; i < size; i += step) {
		double key = dataArray[i];
		int j = i;
		while (j > start && dataArray[j - step] > key) {
			dataArray[j] = dataArray[j - step];
			j -= step;
		}
		dataArray[j] = key;
	}
}

void ShellSort(double* dataArray, int size) {
	for (int step = size / 2; step > 0; step = step / 2) {
		for (int i = 0; i < step; i++) {
			Insert(dataArray, size, i, step);
		}
	}
}

void ParallelShellSort(double* dataArray, int size) {
	for (int step = size / 2; step > 0; step = step / 2) {
#pragma omp parallel for schedule(dynamic) shared( dataArray, size, step, i)  default(none)
		for (int i = 0; i < step; i++) {
			Insert(dataArray, size, i, step);
		}
	}
}