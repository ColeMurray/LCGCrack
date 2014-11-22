#include "parseEnum.cpp"
#include <iostream>
#include <vector>

using namespace std;

class Decrypt {
public:
	static void DecryptBook (map <int, string> enumMap, vector<long long int> lcgValues,
							vector <long long int> lcgGenValues ){
		for (int i = 0; i < lcgValues.size(); i++){
			int charValue = lcgValues[i] - lcgGenValues[i];
			cout << enumMap[charValue] << " " ;
		}

	}
	static vector <long long int> loadFromFile(string filename){
		vector <long long int> lcgValues;
		string line;
		ifstream myFile (filename.c_str());
		if (myFile.is_open()){
			while ( getline (myFile,line) ){
				long long int value = stoll(line);
				lcgValues.push_back(value);
			}
		}
		return lcgValues;

	}


	static vector<long long int> generateLCGValues(signed long long int a, signed long long int b, 
		long long int m, unsigned long long int x0, int size){
		vector <long long int> lcgGenValues;
		unsigned long long int x1;
		for (int i = 0; i < size; i++){
			x1 = (a * x0 + b) % m;
			x0 = x1;
			lcgGenValues.push_back(x1);

		}
		return lcgGenValues;
	}
};

void setupVectors(vector <long long int> &lcgGenValues,	vector <long long int> &lcgEncodedValues){
	lcgEncodedValues = Decrypt::loadFromFile("book1.enc");
	lcgEncodedValues.erase(lcgEncodedValues.begin());
	lcgGenValues = Decrypt::generateLCGValues(4276115653, 634785765, 4294967296, 2699531045, lcgEncodedValues.size());
	lcgGenValues.insert(lcgGenValues.begin(),2699531045);
}

int main(){
	map <int,string> parseMap = ParseBook::parseFileToMap();
	vector <long long int> lcgGenValues;
	vector <long long int> lcgEncodedValues;
	setupVectors(lcgGenValues,lcgEncodedValues);

	Decrypt::DecryptBook(parseMap,lcgEncodedValues,lcgGenValues);

}