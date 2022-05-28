#include <iostream>
#include "readFile.hpp"
#include "trainingSet.hpp"

int main(){
	TrainingSet set = readFile("./data/golf.csv");
	set.train();//only one line agregacol
	set.print();
	set.getAgreCol()->print();
}
