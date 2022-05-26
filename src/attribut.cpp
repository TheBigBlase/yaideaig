#include "attribut.hpp"
#include <iostream>
#include <cmath>

float Attribut::entropy(){
	
	return 0;
}

Attribut::Attribut(std::string name, std::string value){
	mName = name;
	mValue = value;
}

std::string Attribut::getValue(){
	return mValue;
}

std::string Attribut::getName(){
	return mName;
}

void Attribut::printValue(){
	std::cout << mValue;
}

void Attribut::printName(){
	std::cout << mName;
}
