#include "Header.h"

int main()
{

	char population[POP][SIZE];
	double ans, fitness[POP];
	int i, j, mom, dad;
	
	srand(int(time(NULL)));
	initpop(population);
	fitpop(population, fitness);
	sort(population, fitness);
	printpop(population, fitness);
	for (i = 0; i < GEN; i++) {
		for (j = TOP; j < POP; j++)
			{
			mom = rand() % TOP;
			dad = rand() % TOP;
			recomb(population[mom], population[dad], population[j]);
			mutate(population[j]);
			fitness[j] = fit(population[j]);
			}
		sort(population, fitness);

	}
	cout << endl << "Sorted population:" << endl;
	printpop(population, fitness);

	ans = encode(population[0]);
	printf(" Approximate answer is %f\n", ans);

	return 0;
}







