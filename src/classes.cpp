#include "classes.hpp"
#include <iostream>

Classes::Classes(std::string outcome){
	mOutcome = outcome;
}

Classes::Classes(){

}

void Classes::setOutcome(std::string out){
	mOutcome = out;
}

std::string Classes::getOutcome(){
	return mOutcome;
}

void Classes::print(){
	std::cout << mOutcome << std::endl;
}
