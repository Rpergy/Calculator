#include <iostream>
#include <string>
#inclide <math.h>
#include "calculator.h"

std::string calculator::format(std::string input){
  std::string output = "";

	//If char is space, remove it
	for(int i = 0; i < input.length(); i++){
		if(input[i] != ' ')
			output += input[i];	
  }
	return output;
}

float calculator::calculate(std::string input){
  std::string splitEquation[equation.length()];

	std::string currentTerm = "";
	for(int i = 0; i < equation.length(); i++){
		//If char is an operator then add the last term to a new array spot
		if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '^'){
			for(int ii = 0; ii < (sizeof(splitEquation) / sizeof(splitEquation[0])); ii++){
				if(splitEquation[ii] == ""){
					splitEquation[ii] = currentTerm;
					currentTerm = "";
					splitEquation[ii + 1] = equation[i];
					break;
				}
			}
		}
		else
			currentTerm += equation[i];
	}

	for(int i = 0; i < (sizeof(splitEquation) / sizeof(splitEquation[0])); i++){
		if(splitEquation[i] == ""){
			splitEquation[i] = currentTerm;
			break;
		}
	}

	
	float output = 0.0f;
	
	if(splitEquation[1] == "+")
		output = std::stof(splitEquation[0]) + std::stof(splitEquation[2]);
	else if(splitEquation[1] == "-")
		output = std::stof(splitEquation[0]) - std::stof(splitEquation[2]);
	else if(splitEquation[1] == "*")
		output = std::stof(splitEquation[0]) * std::stof(splitEquation[2]);
	else if(splitEquation[1] == "/")
		output = std::stof(splitEquation[0]) / std::stof(splitEquation[2]);
	else if(splitEquation[1] == "^")
		output = pow(std::stof(splitEquation[0]), std::stof(splitEquation[2]));
	

	return output;
}
