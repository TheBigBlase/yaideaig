#include "trainingSet.hpp"
#include <iostream>
#include <cmath>
#include "example.hpp"
#include "attribut.hpp"


std::vector<TrainingSet::Column *> TrainingSet::mEntropyCol = 
		std::vector<TrainingSet::Column *> {};

struct TrainingSet::AgregaCol TrainingSet::mAgregaCol = {};

TrainingSet::TrainingSet(){

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
	initEntropy();
	printEn();
	initAgregaCol();
	//calculate entropy there 
	//halp pls 
}


void TrainingSet::computeEntropy(){//should look by attribut name, (col not line)
	float tmp=0;
	std::string tmpStr;
	for(Column * e : mEntropyCol){
		for(Attribut * a  : *e->mCol){
			//int nb = mAgregaCol[0]->mNbOccurence / mEntropyCol.size();
			//tmp = tmp + log10(nb);
		}
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


void TrainingSet::initEntropy(){//only add first line big bad
	for(Example * e : mExample){//ayo ????
		for(Attribut * a : *e->getAttribut()){
			if(!isIn(&mEntropyCol, a)){
				mEntropyCol.push_back(
					new Column{1, new std::vector<Attribut*> {a}} //0 is pure
				);

				std::cout << "[INIT EN] adding " << a->getName() <<"\n";
			}
		}
	}
}


void TrainingSet::initAgregaCol(){//not working properly ? TODO
	for(auto k : mEntropyCol){//for each col
		for(Attribut * l : *k->mCol){
			std::cout << "[INIT AG] adding " << l->getName() <<"\n";
			mAgregaCol.add(l);
		}
	}
}


Attribut * TrainingSet::getAttrFromAgrega(std::string str){//line from agrega col
	if(mAgregaCol.mCol == NULL) 
		return NULL;//vacuity check

	for(auto * k : *mAgregaCol.mCol){
		for(auto * l : *k->mLine)//lmao
			if(l->getName() == str)
				return l;
	}

	return NULL;//monkaOMEGA bet im gonna regret that later
}


void TrainingSet::AgregaCol::add(Attribut * a){//wtf is that
	std::cout << "[ADD] name " << a->getName() <<"\n";

	if(getAttrFromAgrega(a->getName()) == NULL){ //if not present
		std::cout << "  [ADD] adding " << a->getName() <<"\n";

		if(mCol == NULL){ //be careful of null
			std::cout << "  [ADD] NEW COL " << "\n";
			mCol = new std::vector<LineAgreaCol *> {
				new LineAgreaCol{1, a->getName(), new std::vector<Attribut *>{a}}
			};//if none add first col

			return; // break
		}

		for(auto * k : *mCol){//all cols shall allready be init
			for(auto * l : *k->mLine){
				if(k->mName == a->getName()){ //if belong col AND is not in
					return k->mLine->push_back(a);//push and git out
				}
			}
		}//if not returned yet, create new col and push it in
		mCol->push_back(
				new LineAgreaCol{1, a->getName(), new std::vector<Attribut *>{a}}
			);
		//triggered in init
	}

	else {//if exists then incr
		std::cout << "[ADD] INCR " << a->getName() << "\n";
		incrByAttribut(a);
	}
}


void TrainingSet::incrByAttribut(std::string str){//wtf wrong name
	std::cout << "[INCR] AYOOO ?\n";
	if(!mAgregaCol.mCol || mAgregaCol.mCol == NULL)
		std::cout << "  [INCR] FUCK"; return;

	for(auto * col : *mAgregaCol.mCol){
		for(Attribut * l :  *col->mLine){
			if(l->getName() == str){
				col->mNbOccurence++;
				std::cout << "  [ADD] INCR " << l->getName() << " TO " 
					<< col->mNbOccurence << "\n";
			}
		}
	}
}


void TrainingSet::incrByAttribut(Attribut * a){//same as other 
	std::cout << "[INCR] Hello ?\n";
	if(!mAgregaCol.mCol || mAgregaCol.mCol == NULL)
		std::cout << "  [INCR] FUCK"; return;

	for(auto * col : *mAgregaCol.mCol){
		for(Attribut * l :  *col->mLine){
			if(l->getName() == a->getName()){//only diff
				col->mNbOccurence++;
				std::cout << "  [ADD] INCR " << l->getName() << " TO " 
					<< col->mNbOccurence << "\n";
			}
		}
	}
}


void TrainingSet::AgregaCol::print(){
	for(auto * k : *mAgregaCol.mCol){
		k->print();
		std::cout << std::endl;
	}
}


TrainingSet::AgregaCol * TrainingSet::getAgreCol(){
	return &mAgregaCol;
}


void TrainingSet::LineAgreaCol::print(){
	for(auto * k : *mLine){
		std::cout << k->getValue();
	}
}

void TrainingSet::printEn(){
	for(auto * k : mEntropyCol){
		for(auto * l : *k->mCol){
			std::cout << "[EN] name : " <<  l->getName() 
				<< " value : " << l->getValue() << "\n";
		}
	}
}

bool TrainingSet::isIn(std::vector<Column *> * a, Attribut * val){
	for(auto *k : *a){
		for(auto *l : *k->mCol){
			if(l->getValue() == val->getValue())
				return true;
		}
	}
	return false;
}//kill me already
