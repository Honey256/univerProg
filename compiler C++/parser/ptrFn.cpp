#include "iostream"

void fnnn(int value);


class FiniteStateMachine{

private:
	static int fn1(){
		return 1;
	}

	static int fn2(){
		return 2;
	}

	static int fn3(){
		return 3;
	}

	static int (*fArray[3])();

public:
	void executor(int value){
		if (value == 1){
			std::cout << fArray[0]();
		} else if (value == 2){
			std::cout << fArray[1]();
		} else if (value == 3){
			std::cout << fArray[2]();
		} else {
			std::cout << -1;
		}
	}
};

int (*FiniteStateMachine::fArray[3])()= {fn1, fn2, fn3};

void fnnn(int value){
	FiniteStateMachine* object = new FiniteStateMachine();
	object->executor(value);
}


int main(int argc, char const *argv[]){
	int arr[6] = {0,1,2,1,5,1};

	for (int i = 0; i < 6; i++){
		fnnn(arr[i]);
		std::cout<<std::endl;
	}
	return 0;
}