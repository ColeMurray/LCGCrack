#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

string inputKeyword(string prompt){
   string input;
   cout << prompt;
   cin >> input;
   return input;
}
string orderedKeyword (string keyword){
	string temp = keyword; 
	sort(temp.begin(),temp.end());

	return temp;
}
vector <int> columnRemap (string orderedKeyword, string keyword){
	vector <int> columnOrdering;
	for (int i = 0; i < keyword.length(); i++){
		for (int j = 0; j < keyword.length(); j++){
		if (orderedKeyword[i] == keyword[j]){
			cout << "Match with character " << orderedKeyword[i]
				<< " at " << j << endl;
			columnOrdering.push_back(j);
			break;
		}
		}
	}
	return columnOrdering;
}
int main (){
  string keyword =  inputKeyword("Enter keyword: ");
  string plaintext = inputKeyword("Enter plaintext: "); 
  int keywordLength = keyword.length();
  //calculate the rows, need a ceiling
  int rows = (plaintext.length() + keyword.length() -1) / keyword.length();
  char matrix[rows][keywordLength];

  for (int i = 0 ; i < rows; i++){
	 for (int j = 0; j < keywordLength; j++){
		matrix[i][j] = plaintext[(i*keywordLength) + j]; 
	 }
  }


 for (int i = 0; i < rows; i++){
		 for (int j = 0; j < keywordLength;j++){
			 cout << matrix[i][j] << " " ;
		 }
		 cout << endl;
 }
  string ordKeyword = orderedKeyword(keyword);
  cout << ordKeyword <<endl;
  vector <int> columnStructure = columnRemap(ordKeyword,keyword);
  cout << "Char at 0 : " << columnStructure[0] << endl;
  for (int i = 0; i < columnStructure.size(); i++){
	  cout << columnStructure[i] << endl;
  
  }

 for (int j = 0; j < columnStructure.size(); j++){
	for(int i = 0 ; i < rows; i++){
		cout << matrix[i][columnStructure[j]];
	}
	cout << "   "  ;
 }
 cout << endl;
  return 0;

		
}
