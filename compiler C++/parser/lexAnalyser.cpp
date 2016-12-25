#include <iostream>
#include <fstream>      // std::ifstream
#include <cstring>

void lexAnalyser(const char* path);

unsigned int basicType( std::string firstWord );

void fnCreate();

void fnUse();

void fnShow();

void fnAlter();

void fnDrop();

void fnInsert();

void fnDelete();

void fnSelect();

void start();

//---------------------------------------------------------------------------------


char ch;

const char *localVarPath = new char[128];

std::ifstream *inFile = new std::ifstream;

const int space = ' ';

//---------------------------------------------------------------------------------


enum type{FIRSTWORD, TYPEOFOBJECT, KEYWORD, VAR, SEPARATOR, OPERATOR};

enum varTypeList{INT, DOUBLE, STRING};

//---------------------------------------------------------------------------------


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

//---------------------------------------------------------------------------------


class Lexem{
public:
	short int type;
	int number;
	double digit;
	std::string text;
	std::string name;
	unsigned int ID;
	Lexem(){}
};

//---------------------------------------------------------------------------------


struct Word{
	const unsigned  short number : 5;
   	const char name[25];
};

const Word typeOfOvjectsList[] = {
	{1, "TABLE"},
	{2, "DATABASE"}
};

const unsigned short typeOfObjectsSize = 2;


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

//---------------------------------------------------------------------------------


unsigned int basicType( std::string firstWord ){

	int i = 0;

	while (firstWord != firstWordList[i].name && i != firstWordListSize) { i++; }
	if (i == firstWordListSize){
		std::cout << "baaaaaadssss";
		return 0;
	} else {
		return firstWordList[i].number;
	}
}

//---------------------------------------------------------------------------------

void lexAnalyser(const char* path){
	localVarPath = path;
	inFile->open(localVarPath, std::ifstream::in);

	start();
	//fnUse();
	return;

}


void start(){
	std::string mainWord = "";
	ch = inFile->get();
	while (ch == space){
		ch = inFile->get();
	}

	while (ch != space && !inFile->eof()){
		mainWord = mainWord + ch;
		ch = inFile->get();

	}
	switch ( basicType( mainWord ) ){

		case 1:
			fnCreate();
			break;

		case 2:
			fnUse();
			break;

		case 3:
			fnShow();
			break;

		case 4:
			fnAlter();
			break;

		case 5:
			fnDrop();
			break;

		case 6:
			fnInsert();
			break;

		case 7:
			fnDelete();
			break;

		case 8:
			fnSelect();
			break;

		case 0:
			std::cerr << "syntax error";
			break;
			return;

	}
}

//---------------------------------------------------------------------------------


void fnCreate(){
	std::cout << "createe" << std::endl;
}

void fnUse(){
	std::cout << "usee" << std::endl;
}

void fnShow(){
	std::cout << "showw" << std::endl;
}

void fnAlter(){
	std::cout << "alterr" << std::endl;
}

void fnDrop(){
	std::cout << "dropp" << std::endl;
}

void fnInsert(){
	std::cout << "insertt" << std::endl;
}

void fnDelete(){
	std::cout << "deletee" << std::endl;
}

void fnSelect(){
	std::cout << "selectt" << std::endl;
}

