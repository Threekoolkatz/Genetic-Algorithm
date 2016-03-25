#include <cmath>
#include <iostream>
#include <time.h>


using namespace std;

const int BITS = 16;
const int POP = 30;
const int SIZE = 17;
const int GEN = 250;
const int TOP = 10;

double encode(char bitstring[]);
void decode(double value, char string[]);
int bin2dec(char string[]);
void dec2bin(int val, char string[]);
double fit(char string[]);
void printpop(char population[][SIZE], double fitness[]);
void mutate(char string[]);
void recomb(char string1[], char string2[], char string3[]);
void initpop(char population[][SIZE]);
void fitpop(char population[][SIZE], double fitness[]);
void sort(char population[][SIZE], double fitness[]);
