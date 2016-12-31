#include <iostream>
#include "lexAnalyser.cpp"
//main

int main(int argc, char const *argv[]){
	if ( argc == 1 ){
		std::cerr << "error: file not found" << std::endl;
	} else {
		lexAnalyser(argv[1]);
	}
	return 0;
}