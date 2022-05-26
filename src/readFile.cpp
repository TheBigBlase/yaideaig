#include "readFile.hpp"
#include <iostream>
#include <fstream>
#include "trainingSet.hpp"
 
TrainingSet readFile(std::string fileName){
	std::fstream file;
	TrainingSet trainingSet;

	file.open(fileName, std::ios::in); //open a file

	if (file.is_open()){//double check
		std::string line;

		if(getline(file, line)){
			trainingSet.addFirstLine(line);
		}
		while(getline(file, line)){ //read data from file object and put it into string.
			trainingSet.addLine(line);
		}
		file.close();
	}
	return trainingSet;
}
