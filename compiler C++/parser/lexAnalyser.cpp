#include <iostream>
#include <fstream>      // std::ifstream
#include <cstring>

const char *localVarPath = new char[128];

const int space = ' ';

enum type{FIRSTWORD, TYPEOFOBJECT, KEYWORD, DOUBDIGIT, INTDIGIT, VAR, SOMEWORD, SEPARATOR, OPERATOR};

enum varTypeList{INT, DOUBLE, STRING};

class Register{
public:
	static int incrementValue;
	unsigned long long ID;
	unsigned short type : 2;
	std::string strValue;
	double value;
	Register(){
		ID = incrementValue;
		incrementValue++;
		type = 3;
		strValue = "";
		value = 0;

	}
};

int Register::incrementValue = 0;

struct Word{
	const unsigned  short number : 5;
   	const char name[25];
};


const Word firstWordList[] = {
    {1, "CREATE"},
	{2, "USE"},
	{3, "SHOW"},
	{4, "ALTER"},
	{5, "DROP"},
	{6, "INSERT"},
	{7, "DELETE"},
	{8, "SELECT"}
};
const unsigned firstWordListSize = 8;


const Word typeOfOvjectsList[] = {
	{1, "TABLE"},
	{2, "DATABASE"}
};
const unsigned short typeOfObjectsSize = 2;


const Word anotherKeywordsList[] = {
	{1, "DESCRIBE"}, 
	{2, "UPDATE"},
	{3, "INTO"},
	{4, "VALUES"}, 
	{5, "PRIMARY"}, 
	{6, "KEY"}, 
	{7, "TYPE"}, 
	{8, "ADD"}, 
	{9, "INDEX"},	
	{10, "CHANGE"},	
	{11, "FIRST"}, 
	{12, "AFTER"}, 
	{13, "WHERE"}, 
	{14, "ORDER"}, 
	{15, "BY"},
	{16, "LIMIT"}, 
	{17, "ASC"}, 
	{18, "DESC"}, 
	{19, "FROM"}, 
	{20, "SET"}, 
	{21, "FIELDS"}, 
	{22, "_NULL"}
};
const unsigned short anotherKeywordsListSize = 22;


struct Lexem{
	short int type;
	int number;
	int intDigit;
	double doubDigit;
	std::string name;
	unsigned int ID;
	Lexem(){

	}
};

void lexAnalyser(const char* path){
	localVarPath = path;
	std::ifstream inFile(localVarPath, std::ifstream::in);
	char sym;
	
	//while (sym != space){

	//}

}