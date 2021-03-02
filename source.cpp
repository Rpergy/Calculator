#include <iostream>
#include "calculator.h"

int main(){
	std::cout << "Enter Equation: ";

	std::string input = "";
	getline(std::cin, input);
	std::cout << calculator::calculate(calculator::format(input)) << std::endl;
}

