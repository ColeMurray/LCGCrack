#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

class ParseBook{

public:

static void parseKeyandValue(map <int,string> &parseMap, string line){
	string parsed = line.substr(2);
			string letterKey = parsed.substr(0,parsed.find('\''));
			int posAfterComma = parsed.find(',')+1;
			string valueString = parsed.substr(posAfterComma, parsed.find(')')-posAfterComma);
			int value = atoi(valueString.c_str());
			addToMap(parseMap,value,letterKey);
}
static map <int,string> parseFileToMap(){
	map <int,string> parseMap;
	string line;
	ifstream eInput ("enum.txt");
	if (eInput.is_open()){
		while ( getline (eInput,line ) ){
			parseKeyandValue(parseMap,line);
			
		}

	}
	return parseMap;
}
static void addToMap(map <int, string> &enummap, int key, string value){
		enummap[key]=value;

}




};

