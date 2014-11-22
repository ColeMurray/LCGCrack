#ifndef __LCGCRACK_H__
#define __LCGCRACK_H__

#include <vector>
#include <iostream>
using namespace std;

void findDivisors(unsigned long long int sum);
bool findA(unsigned long long int possibleDivisor);
long long int gcd(long long int u, long long int v);
long long int modInverse(unsigned long long int a, unsigned long long int m);
long long int findB (long long int a, long long int x0, long long int x1, long long int m);

long long int testValues[] = {2,4,3,0,5,6};
bool generateLCG(signed long long int a, signed long long int b, long long int m, unsigned long long int x0);

vector <long long int> lcgValues ;
void loadFromFile (string filename);
void subtractUTF (vector <long long int> &lcgValues);
#endif