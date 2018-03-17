#include <cstdio>
#include <random>
#include <omp.h>

void ShellSort(double* dataArray, int size);

int main(int argc, char * argv[])
{
	double *dataArray;
	int size;

	FILE* f1;
	FILE* f2;

	freopen_s(&f1, "..//sort.in", "rb", stdin);
	freopen_s(&f2, "..//sort.out", "wb", stdout);

	fread(&size, sizeof(size), 1, stdin);
	dataArray = new double[size];
	fread(dataArray, sizeof(*dataArray), size, stdin);
	
	double time = omp_get_wtime();
	ShellSort(dataArray, size);
	time = omp_get_wtime() - time;

	fwrite(&time, sizeof(time), 1, stdout);
	fwrite(&size, sizeof(size), 1, stdout);
	fwrite(dataArray, sizeof(*dataArray), size, stdout);

	fclose(f1);
	fclose(f2);
	return 0;
}