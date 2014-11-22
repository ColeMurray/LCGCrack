#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector <string> charFromFile;
void loadFromFile(string filename){
	string line;
	ifstream myFile (filename.c_str());
	if (myFile.is_open()){
		while ( getline (myFile,line) ){
			charFromFile.push_back(line);
		}
	}
}

void writeToFile (string filename, const char letter, const int value){
	ofstream output (filename.c_str(),ios::app);
	if (output.is_open()){
		output << letter << "," << value << "\n";
	}
}

void mapString (map<char,int> &container, string currentString){
	for ( int i = 0 ; i < currentString.length(); i++){
			char c = currentString[i];
			map<char,int>::const_iterator foundKey = container.find(c);
			if (foundKey == container.end())
			{
				cout << "Does not exist yet" << endl;
				container[c] =1;
			}
			else{
				int val = foundKey->second;
				container[c] = val+1;
			}

		}

}

int main (){
	map <char,int> container;
	cout << "Finding the frequency distribution over a string" << endl;
	loadFromFile("book2.enc");
	for (int j = 0; j < charFromFile.size(); j++){
		string currentString = charFromFile.at(j);
		//mapString(&container,currentString);
		for ( int i = 0 ; i < currentString.length(); i++){
			char c = currentString[i];
			map<char,int>::const_iterator foundKey = container.find(c);
			if (foundKey == container.end())
			{
				//cout << "Does not exist yet" << endl;
				container[c] =1;
			}
			else{
				int val = foundKey->second;
				container[c] = val+1;
			}

		}
		
	}


	for (auto it = container.cbegin(); it!= container.cend(); ++it){
		cout << it->first << ", " << it->second << endl ;
		writeToFile("freq.csv",it->first,it->second);
	}
}