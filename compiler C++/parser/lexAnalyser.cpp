#include <iostream>
#include <fstream>      // std::ifstream


enum type{FIRSTWORD, TYPEOFOBJECT, KEYWORD, DOUBDIGIT, INTDIGIT, VAR, SOMEWORD, SEPARATOR, OPERATOR};
enum keywords{	
				DESCRIBE, UPDATE, INTO, VALUES, PRIMARY, KEY, TYPE, ADD, INDEX,	
				CHANGE,	FIRST, AFTER, WHERE, ORDER, BY,LIMIT, ASC, DESC, FROM, SET, FIELDS, _NULL};
const char *localVarPath = new char[100];
struct Lexem{
	short int type;
	int number;
	int intDigit;
	double doubDigit;
	std::string name;
	unsigned int ID;
};

struct Word{
	const unsigned short int number;
   	const char name[25];
};

const Word WordList[] =
 {
    {1, "CREATE"},
	{2, "USE"},
	{3, "SHOW"},
	{4, "ALTER"},
	{5, "DROP"},
	{6, "INSERT"},
	{7, "DELETE"},
	{8, "SELECT"}
};

const Word typeOfOvjectsArray[] =
{
	{1, "TABLE"},
	{2, "DATABASE"}
};

const Word anotherKeywordsArray[] = 
{
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
const int firstWordListSize = 8;

void lexAnalyser(const char* path){
	localVarPath = path;
	std::ifstream inFile(localVarPath, std::ifstream::in);
	char *newArr = new char[50];
	inFile.read(newArr, 5);
	std::cout << newArr;
	char sym;
}