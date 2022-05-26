#include "example.hpp"
#include "attribut.hpp"
#include <iostream>


Example::Example(){
	std::vector<Attribut> mAttributes;
}

Example::Example(Classes *c) : mClass{*c}{
	std::vector<Attribut> mAttributes;

}

Example::Example(Classes *c, std::vector<Attribut *> *a) : mClass{*c}{
	mAttributes = *a;
	mClass = *c;
}

void Example::add(Attribut at){
	mAttributes.push_back(&at);
}

void Example::add(std::string name, std::string value){
	mAttributes.push_back(new Attribut(name,value));
}

void Example::setClass(Classes &c){
	mClass = c;
}

Attribut* Example::getByIndex(int i){
	return mAttributes[i];
}

void Example::print(){
	for(auto a : mAttributes){
		a->printValue();
		std::cout << " ";
	}
	mClass.print();
}


void Example::printFirstLine(){
	for(auto a : mAttributes){
		a->printName();
		std::cout << " ";
	}
	mClass.print();//outcomes (class) already endl
}

std::vector<Attribut *> *Example::getAttribut(){
	return &mAttributes;
}
