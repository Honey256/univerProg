#include <iostream>
#include "lexAnalyser.cpp"

int main(int argc, char const *argv[]){
	int index = 0;
	lexAnalyser(argv[1]);
	std::cout << std::endl << argc;
	return 0;
}