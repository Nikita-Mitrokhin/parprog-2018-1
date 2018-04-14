#include <cstdio>
#include <random>
#include <omp.h>

void ShellSort(double* dataArray, int size);
void ParallelShellSort(double* dataArray, int size);

int main(int argc, char * argv[])
{
	double *dataArray;
	int size;

	FILE* f1;
	FILE* f2;

		std::string fileName = "sort";
	int num_threads = 1;
	if (argc == 2) {
		num_threads = atoi(argv[1]);
	}
	else {
		if (argc == 3)
		{
			num_threads = atoi(argv[1]);
			fileName = argv[2];
		}
	}
	
	freopen_s(&f1, ("..//" + fileName + ".in").c_str(), "rb", stdin);
	freopen_s(&f2, ("..//" + fileName + ".out").c_str(), "wb", stdout);

	fread(&size, sizeof(size), 1, stdin);
	dataArray = new double[size];
	dataArray_p = new double[size];
	fread(dataArray, sizeof(*dataArray), size, stdin);
	
	for (int i = 0; i < size; i++) {
		dataArray_p[i] = dataArray[i];
	}

	omp_set_num_threads(num_threads);
	double time_par = omp_get_wtime();
	ParallelShellSort(dataArray_p, size);
	time_par = omp_get_wtime() - time_par;
	double Boost = time / time_par;
	
	double time = omp_get_wtime();
	ShellSort(dataArray, size);
	time = omp_get_wtime() - time;

	fwrite(&Boost, sizeof(Boost), 1, stdout);
	fwrite(&size, sizeof(size), 1, stdout);
	fwrite(dataArray, sizeof(*dataArray), size, stdout);

	fclose(f1);
	fclose(f2);
	return 0;
}