#include <iostream>
#include <fstream> 
#include <cstring>
#include <vector>

void lexAnalyser( const char* path );

void scaner();

unsigned long long getID( std::string name );

std::string getWord();

bool isSpace();

bool isDigit();

bool isLetter();

bool isCapital();

bool isSeparator();

bool isOperator();

void addInstance( int type, int number );

void addInstance( unsigned short type, int number, double digit, std::string text, std::string name );

double stringToDigit( std::string str );


enum type{ KEYWORD, DIGIT, TEXT, SEPARATOR, OPERATOR, VALUE, VAR, SYSTEMFLAGS };

enum typeList{ DEFAULT, INT, DOUBLE, STRING };

enum systemFlags{ START, BEGIN, END, EoF };


class Register{
public:

	static int incrementValue;
	unsigned long long ID;
	unsigned short type : 2;
	std::string strValue;
	double value;

	Register();
};

class Lexem{
public:
	unsigned short type : 4;
	int number;
	double digit;
	std::string text;
	std::string name;
	unsigned int ID;

public:
	Lexem( unsigned short newType, int newNumber );

	Lexem( unsigned short newType, int newNumber, double newDigit, std::string newText, std::string newName );

	void print();
};

struct Word{
	const unsigned  short number : 6;
   	const char name[25];
};

class FiniteStateMachine{

private:
	static std::string buffer;

private:
	static void isKeywordLexem();

	static void isDigitLexem();

	static void isStringLexem();

	static void isSeparatorLexem();

	static void isOperatorLexem();

	static void ( *state[] )();

public:
	void executor();
};

