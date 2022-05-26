#include <iostream>
#include "readFile.hpp"
#include "trainingSet.hpp"

int main(){
	TrainingSet set = readFile("./data/golf.csv");
	set.print();
}
