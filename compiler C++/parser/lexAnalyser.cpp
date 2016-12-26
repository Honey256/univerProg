#include <iostream>
#include <fstream>      // std::ifstream
#include <cstring>
#include <vector>

void lexAnalyser(const char* path);

unsigned int basicType( std::string firstWord );

unsigned long long getID(std::string name);

std::string getWord();

void start();


void fnCreate();

void fnUse();

void fnShow();

void fnAlter();

void fnDrop();

void fnInsert();

void fnDelete();

void fnSelect();


void varLexem(unsigned short type);


//---------------------------------------------------------------------------------


char ch = ' ';

const char *localVarPath = new char[128];

std::ifstream *inFile = new std::ifstream;

const int space = ' ';

//---------------------------------------------------------------------------------


enum type{SYSTEMFLAGS, FIRSTWORD, TYPEOFOBJECT, KEYWORD, VAR, VALUE, SEPARATOR, OPERATOR};

enum typeList{DEFAULT, INT, DOUBLE, STRING, DATABASE, TABLE};

enum systemFlags{BEGIN, ENDOFCOMAND, EoF};

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

std::vector<Register> registerArray;

//---------------------------------------------------------------------------------


class Lexem{
public:
	unsigned short type : 3;
	int number;
	double digit;
	std::string text;
	std::string name;
	unsigned int ID;
	Lexem(){}

public:
	void initLexem( unsigned short newType, int newNumber ){
		type = newType;
		number = newNumber;
	}

	void initValue(unsigned short newType, int newNumber, double newDigit, std::string newText, std::string newName){
		type = newType;
		number = newNumber;
		int intTest = newDigit;
		if (newType == VAR){
			name = newName;
			ID = getID( newName );
		}
		if (newType == VALUE){
			if (newText != ""){
				number = STRING;
			} else if (intTest == newDigit){
				number = INT;
			} else {
				number = DOUBLE;
			}
		}
	}

	void print(){
		if (type == VAR){
			std::cout << "<" << type << " | " << number << " | " << name << ">" << std::endl;
		} else {
			std::cout << "<" << type << " | " << number << ">" << std::endl;

		}

	}
};

std::vector<Lexem> lexemArray;

//---------------------------------------------------------------------------------


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
		return 0;
	
	} else {
		return firstWordList[i].number;
	}
}

unsigned long long getID(std::string name){

	for (int i = 0; i < lexemArray.size(); i++){

		if (lexemArray[i].name == name){
			return lexemArray[i].ID;
		}
	}

	Register *newVar = new Register();
	registerArray.push_back(*newVar);
	return newVar->ID;
}

std::string getWord(){
	std::string word = "";

	while (ch == space){
		ch = inFile->get();
	}


	while (ch != space && !inFile->eof() && ch != ';'){
		word += ch;
		ch = inFile->get();

	}

	return word;
}

void endOfComand(){
	Lexem *end = new Lexem();
	end->type = SYSTEMFLAGS;
	end->number = ENDOFCOMAND;
	lexemArray.push_back(*end);
}

//---------------------------------------------------------------------------------

void lexAnalyser(const char* path){
	localVarPath = path;
	inFile->open(localVarPath, std::ifstream::in);

	start();
	return;

}


void start(){

	Lexem *start = new Lexem();
	start->type = SYSTEMFLAGS;
	start->number = BEGIN;
	lexemArray.push_back(*start);

	while (!inFile->eof()){

		while (ch == space || ch == '\n' && !inFile->eof()){
			ch = inFile->get();
		}

		if (inFile->eof()){
			for (int i = 0; i < lexemArray.size(); i++){
				lexemArray[i].print();
			}
			return;
		}

		std::string mainWord = getWord();

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
}

//---------------------------------------------------------------------------------


void fnCreate(){
	Lexem *newLex = new Lexem();
	newLex->initLexem(FIRSTWORD, 1);
	lexemArray.push_back(*newLex);
}

void fnUse(){
	Lexem *newLex = new Lexem();
	newLex->initLexem(FIRSTWORD, 2);
	lexemArray.push_back(*newLex);
	varLexem(DATABASE);
	if (ch == ';'){
		ch = inFile->get();
		endOfComand();
	}


}

void fnShow(){
	Lexem *newLex = new Lexem();
	newLex->initLexem(FIRSTWORD, 3);
	lexemArray.push_back(*newLex);
}

void fnAlter(){
	Lexem *newLex = new Lexem();
	newLex->initLexem(FIRSTWORD, 4);
	lexemArray.push_back(*newLex);

}

void fnDrop(){
	Lexem *newLex = new Lexem();
	newLex->initLexem(FIRSTWORD, 5);
	lexemArray.push_back(*newLex);
}

void fnInsert(){
	Lexem *newLex = new Lexem();
	newLex->initLexem(FIRSTWORD, 6);
	lexemArray.push_back(*newLex);
}

void fnDelete(){
	Lexem *newLex = new Lexem();
	newLex->initLexem(FIRSTWORD, 7);
	lexemArray.push_back(*newLex);
}

void fnSelect(){
	Lexem *newLex = new Lexem();
	newLex->initLexem(FIRSTWORD, 8);
	lexemArray.push_back(*newLex);
}

//---------------------------------------------------------------------------------


void varLexem(unsigned short type){
	std::string word = getWord();
	Lexem *newLex = new Lexem();
	newLex->initValue(VAR, type, 0, "", word);
	lexemArray.push_back(*newLex);
}