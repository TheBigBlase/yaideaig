#include "trainingSet.hpp"
#include <iostream>
#include "example.hpp"
#include "attribut.hpp"



std::vector<TrainingSet::AgregaCol *> TrainingSet::mAgregaCol = 
		std::vector<TrainingSet::AgregaCol *> {};

TrainingSet::TrainingSet() : mFirstLine{Example{new Classes{}}}{
	mExample = std::vector<Example*>{};
}


void TrainingSet::addLine(std::string line){
	int i = 0;
	short position;

	std::string sep {","};
	std::string token;

	Example * ex = new Example{new Classes{}};
	
	while ((position = line.find(sep)) != std::string::npos) {//while at least 1 elt
		token = line.substr(0, position); //
		line.erase(0, position + sep.length());
		ex->add(getNameFromFirstLine(i), token);//example
		i++;
	}

	if(line.back() == '\r'){//watch out for dos like files
		line.pop_back();
	}

	ex->setClass(* new Classes (line));//last one is the outcome
	mExample.push_back(ex);
}


void TrainingSet::addFirstLine(std::string line){
	int i = 0;
	short position;

	std::string token;
	std::string sep {","};

	Example ex{new Classes{}};

	while ((position = line.find(sep)) != std::string::npos) {//while at least 1 elt
		token = line.substr(0, position); //
		line.erase(0, position + sep.length());
		ex.add(token, "");//example
		i++;
	}

	if(line.back() == '\r'){//watch out for dos like files
		line.pop_back();
	}

	ex.setClass(*new Classes{line});//new since it has to be persistent
	mFirstLine = ex;
}


Attribut * TrainingSet::getAttributFromFirstLine(int i){
	return mFirstLine.getByIndex(i);
}


std::string TrainingSet::getNameFromFirstLine(int i){
	return mFirstLine.getByIndex(i)->getName();
}


void TrainingSet::print(){
	mFirstLine.printFirstLine();
	for(Example * a : mExample){
		a->print();
	}
}

void TrainingSet::train(){
	//aha go brrr
}

void TrainingSet::computeEntropy(){//should look by attribut name, (col not line)
	float tmp=0;
	std::string tmpStr;
	for(Column * e : mEntropyCol){

	}
}

Attribut * TrainingSet::getBestAttribut(){
	Attribut * best{};
	float bestEntropy;
	for(Column * e : mEntropyCol){
		if(e->entropy > bestEntropy){
			bestEntropy = e->entropy;
		}
	}
	return best;
}

void TrainingSet::initEntropy(){
	for(Attribut * a : *mFirstLine.getAttribut()){
		Column * col = new Column{0, new std::vector<Attribut*> {a}};
		mEntropyCol.push_back(col);
	}
}

void TrainingSet::initAgregaCol(){
	for(auto k : mEntropyCol){
		for(Attribut * l : *k->column){
			std::vector<Attribut * > * tmp = new std::vector<Attribut *>;
			tmp->push_back(l);
			mAgregaCol.push_back(new AgregaCol{1, tmp});
		}
	}
}

void TrainingSet::AgregaCol::incrByAttribut(std::string str){
	for(AgregaCol * k : mAgregaCol){
		if(k->col)
			k->nbOccurence++;
	}
}
