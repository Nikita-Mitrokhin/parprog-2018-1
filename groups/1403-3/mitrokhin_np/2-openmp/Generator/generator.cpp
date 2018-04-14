#include <cstdio>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

int n_tests[] = { 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 100, 200, 300, 400, 500,
600, 700, 800, 900, 1000 };

int main(int argc, char * argv[])
{
	FILE* f1;
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	uniform_real_distribution <double> disrtibution(-1e4, 1e4);
	uniform_int_distribution <int> distribution_size(0, 666666);
	int n;

	std::string fileName = "sort";
	if (argc == 2) {
		n = atoi(argv[1]);
	}
	else {
		if (argc == 3)
			 {
			n = atoi(argv[1]);
			fileName = argv[2];
			}
		else {
			n = distribution_size(generator);
			
		}
		
	}

	freopen_s(&f1, ("..//" + fileName + ".in").c_str(), "wb", stdout);
	fwrite(&n, sizeof(n), 1, stdout);
	double *cur = new double[n];
	for (int i = 0; i < n; i++)
		cur[i] = disrtibution(generator);
	fwrite(cur, sizeof(*cur), n, stdout);
	fclose(f1);
	return 0;
}