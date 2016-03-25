#include "Header.h"
#define _CRT_SECURE_NO_WARNINGS

/*
* Author:  Jeff McGough
*
*/
double encode(char string[])
{
	int val;
	double max, encoded;
	max = pow(2.0, BITS);
	val = bin2dec(string);
	encoded = val / max;
	return encoded;
}

/*
* Author:  Jeff McGough
*
*/
int bin2dec(char string[])
{
	int i, value = 0, pow = 1;

	for (i = BITS - 1; i >= 0; i--)
	{
		if (string[i] == '1') value += pow;
		pow *= 2;
	}
	return value;
}

/*
* Author:  Jeff McGough
*
*/
void decode(double value, char string[])
{
	int temp, max;

	max = pow(2, BITS);
	temp = max *(value + 2.0) / 4.0;
	dec2bin(temp, string);
}

/*
* Author:  Jeff McGough
*
*/
void dec2bin(int val, char string[])
{
	int i;
	string[BITS] = '\0 ';
	for (i = BITS - 1; i >= 0; i--)
	{
		if (val % 2 == 0) string[i] = '0';
		else string[i] = '1';
		val = val / 2;
	}
}


double fit(char string[])
{
	double x, fitvalue, exponent;

	x = encode(string);

	exponent = pow((x - 0.1) / 0.9, 2);
	exponent = exponent * -2;
	fitvalue = pow(2, exponent);


	return fitvalue;
}

void fitpop(char population[][SIZE], double fitness[])
{
	int i;
	for (i = 0; i < POP; i++)
		{
		fitness[i] = fit(population[i]);
		}
}

void initpop(char population[][SIZE])
{
	int i, j, max, value;
	max = pow(2, BITS);

	for (i = 0; i < POP; i++)
	{
		value = rand() % max;
		dec2bin(value, population[i]);
		cout << "Agent is: ";
		for (j = 0; j < BITS; j++)
			cout << population[i][j];
		cout << endl;
		}
}

void printpop(char population[][SIZE], double fitness[])
{
	int i, j;
	double value;
	char string[SIZE];
	
	for (i = 0; i < POP; i++)
		{
		value = encode(population[i]);
		decode(value, string);
		cout << " Individual = "; 
		for (j = 0; j < BITS; j++)
			cout << population[i][j]; 
		cout << " Decimal =  " << value << " \tFitness = " << fitness[i]<< endl;
		}
}

void mutate(char string[])
{
	int location;
	location = rand() % BITS;
	if (string[location] == '1') string[location] = '0';
	else string[location] = '1';
}

void recomb(char string1[], char string2[], char string3[])
{
	int i, location;
	location = rand() % BITS;

		for (i = 0; i < location; i++) string3[i] = string1[i];
	for (i = location; i < BITS; i++) string3[i] = string2[i];

}

void sort(char population[][SIZE], double fitness[])
{
	int i,j;
	char temp[SIZE];
	double fitTemp = 0;
	
	for (i = 0; i < POP - 1; i++)
	{
			for (j = 0; j < POP - 1; j++)
			{
				if (fitness[i] < fitness[i + 1])
				{
					// Swapping population[i] with population[i+1]
					strncpy_s(temp, population[i], BITS);
					strncpy_s(population[i], population[i + 1], BITS);
					strncpy_s(population[i + 1], temp, BITS);

					// Swapping fitness[i] with fitness[i+1]
					fitTemp = fitness[i];
					fitness[i] = fitness[i + 1];
					fitness[i + 1] = fitTemp;
				}					
			}
	}
	return;
}