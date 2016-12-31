#include <iostream>
#include <fstream> 
#include <cstring>
#include <vector>

void lexAnalyser(const char* path);

void scaner();

unsigned long long getID(std::string name);

std::string getWord();

bool isSpace();

bool isDigit();

bool isLetter();

bool isCapital();

void addInstance(int type, int number);

double stringToDigit(std::string str){
	double digit = 0;
	bool flag = 0;
	int i = 0;
	int flagIndex = 0;

	while (i != str.length()){
		if (str[i] == '.'){
			flag = 1;
			i++;
		}

		if (flag == 1){
			flagIndex++;
		}

		digit = digit * 10 + str[i] - 48;
		i++;
	}

	for (int j = 0; j < flagIndex; j++){
		digit /= 10;
	}
}


//---------------------------------------------------------------------------------


char ch = ' ';

const char *localVarPath = new char[128];

std::ifstream *inFile = new std::ifstream;

const int space = ' ';

const unsigned short keywordsListSize = 31;


//---------------------------------------------------------------------------------


enum type{KEYWORD, VAR, DIGIT, TEXT, VALUE, SEPARATOR, OPERATOR, SYSTEMFLAGS};

enum typeList{DEFAULT, INT, DOUBLE, STRING, DATABASE, TABLE};

enum systemFlags{START, BEGIN, END, EoF};

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
	Lexem( unsigned short newType, int newNumber ){
		type = newType;
		number = newNumber;
	}

	Lexem(unsigned short newType, int newNumber, double newDigit, std::string newText, std::string newName){
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


const Word keywordsList[] = {
    {1, "CREATE"},
	{2, "USE"},
	{3, "SHOW"},
	{4, "ALTER"},
	{5, "DROP"},
	{6, "INSERT"},
	{7, "DELETE"},
	{8, "SELECT"},
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
	{22, "_NULL"},
	{23, "DESCRIBE"}, 
	{24, "UPDATE"},
	{25, "INTO"},
	{26, "KEY"}, 
	{27, "TYPE"}, 
	{28, "ADD"}, 
	{29, "VALUES"}, 
	{30, "PRIMARY"},
	{31, "*"} 
};

//---------------------------------------------------------------------------------


class FiniteStateMachine{

private:
	static std::string buffer;

private:
	static void isKeywordLexem(){

		buffer = "";

		bool flag = 0;

		int i = 0;

		while ( isLetter() || ch == '_' ){
			buffer += ch;
			ch = inFile->get();
		}

		while ( i != keywordsListSize ){

			if ( buffer == keywordsList[i].name ){
				flag = 1;
				break;
			}
			i++;
		}

	}

	static void isDigitLexem(){

		buffer = "";
		int flag = 0;

		while( isDigit() || ch == '.'){
			if (ch == '.'){
				flag++;
			}
			buffer += ch;
			ch = inFile->get();
		}

		if (flag > 1){
			std::cerr << "Syntax error";
			return;
		}
	}

	static void isStringLexem(){

		buffer = "";
		ch = inFile->get();

		while(ch != '"'){
			buffer += ch;
			ch = inFile->get();
		}



	}

	static void (*state[3])();

public:
	void executor(){
		addInstance(SYSTEMFLAGS, START);

		while ( !inFile->eof() ){

			addInstance(SYSTEMFLAGS, BEGIN);
			ch = inFile->get();

			while( isSpace() ){
				ch = inFile->get();

				if ( !inFile->eof() ){
					addInstance(SYSTEMFLAGS, END);
					break;
				}
			}

			if (ch =='"'){
				state[TEXT]();

			} else if ( isDigit() ){
				state[DIGIT]();
			}

			if (ch == ';'){
				addInstance(SYSTEMFLAGS, END);
				continue;

			}


			addInstance(SYSTEMFLAGS, END);
		}

		addInstance(SYSTEMFLAGS, EoF);


		
	}
};

std::string FiniteStateMachine::buffer;

void (*FiniteStateMachine::state[3])() = {isKeywordLexem, isDigitLexem, isStringLexem};

//---------------------------------------------------------------------------------

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



void addInstance(int type, int number){
		Lexem *instance = new Lexem(type, number);
		lexemArray.push_back(*instance);
}

bool isSpace(){
	if (ch == space){
		return true;
	} else {
		return false;
	}
}

bool isDigit(){
	if (ch > 47 && ch < 58){
		return true;
	} else {
		return false;
	}
}

bool isLetter(){
	if (ch > 64 && ch < 91 || ch > 96 && ch < 123){
		return true;
	} else {
		return false;
	}
}

bool isCapital(){
	if (ch > 64 && ch < 91){
		return true;
	} else {
		return false;
	}
}

//---------------------------------------------------------------------------------

void lexAnalyser(const char* path){
	localVarPath = path;
	inFile->open(localVarPath, std::ifstream::in);
	scaner();
	return;

}

void scaner(){

}




//---------------------------------------------------------------------------------


