#include "LCGCrack.h"
#include <iostream>
#include <cmath>
#include <stdint.h>
#include <fstream>
#include <vector>
#include <string>


void findDivisors(unsigned long long int sum){
	for ( signed long long int i = 2; i <= sum/2; i++){
		if ( sum % i == 0){
			if ( findA(i)){
				cout << "Finished" << endl;
				break;

			}
		}
    }
}
bool findA(unsigned long long int possibleDivisor){
	long long int rightHand = lcgValues[2] - lcgValues[1];
	long long int leftHand = lcgValues[3] - lcgValues[2];

		if (gcd(rightHand,possibleDivisor) !=1){
		return false;
	} 
	
	long long int a = leftHand * modInverse(rightHand,possibleDivisor) % possibleDivisor;
	long long int b = findB(a,lcgValues[1],lcgValues[2],possibleDivisor);
	bool LCGOutput = generateLCG(a,b,possibleDivisor,lcgValues[1]);
	if ( LCGOutput == true){
		return true;

	}
	return false;

}



  long long int gcd(long long int u, long long int v) {

  	long long int t;
  	while (v) {
  	  t = u; 
  	  u = v; 
  	  v = t % v;
  	}
  	return u < 0 ? -u : u; /* abs(u) */
}

long long int findB (long long int a, long long int x1, long long int x2, long long int m){
	long long int b = (x2-a*x1) % m ;

	if (b < 0 ){
		b+=m;
	}

	return b;

}

bool generateLCG(signed long long int a, signed long long int b, long long int m, unsigned long long int x0){
	unsigned long long int x1 = (a * x0 + b) % m;

	for (int i = 2; i < 4; i++){
		x1 = (a * x0 + b) % m;
		if (x1 != lcgValues[i]){
			return false;
		}
		x0 = x1;
	}
		cout << "Found an A and B and M: " << a << "," << b  << "," << m <<endl;

	return true;


}

void subtractUTF (vector <long long int> &lcgValues){
	lcgValues[1] -= 80;
	lcgValues[2] -= 114;
	lcgValues[3] -= 111;
	lcgValues[4] -= 106;
	lcgValues[5] -= 101;
	lcgValues[6] -= 99;
	lcgValues[7] -= 116;
	lcgValues[8] -= 32;
	lcgValues[9] -= 71;
	lcgValues[10] -= 117;
    lcgValues[11] -= 116;
	lcgValues[12] -= 101;
	lcgValues[13] -= 110;
	lcgValues[14] -= 98;
	lcgValues[15] -= 101;
	lcgValues[16] -= 114;
    lcgValues[17] -= 103;
}

void loadFromFile(string filename){
	string line;
	ifstream myFile (filename.c_str());
	if (myFile.is_open()){
		while ( getline (myFile,line) ){
			long long int value = stoll(line);
			lcgValues.push_back(value);
		}
	}
}


signed long long int extendedEuclid(unsigned long long int a, unsigned long long int b) {
    signed long long int x = 1, y = 0;
    signed long long int xLast = 0, yLast = 1;
    signed long long int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return xLast;
}
 
long long int modInverse(unsigned long long int a, unsigned long long int m) {
	signed long long int eeInverse = extendedEuclid(a,m) % m ;
	if (eeInverse < 0 )
	{
		eeInverse += m;
	}
    return eeInverse;
}


int main (){

	loadFromFile("book1.enc");
	subtractUTF(lcgValues);
	for ( int i = 0 ; i <= 3 ; i ++ ){
		cout << i << lcgValues[i] << endl;
	}
	unsigned long long int RH = (lcgValues[3] - lcgValues[2])*(lcgValues[3] - lcgValues[2]);
	unsigned long long int LH = (lcgValues[4]-lcgValues[3])*(lcgValues[2]-lcgValues[1]);
	unsigned long long int sum = RH - LH;


	findDivisors(sum);

}
