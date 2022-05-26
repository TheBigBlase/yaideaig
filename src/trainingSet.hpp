#ifndef TRAININGSET_HPP
#define TRAININGSET_HPP
#include "example.hpp"
#include <vector>
#include <string>

class TrainingSet{
	public:
		TrainingSet();
		~TrainingSet(){};
		void addLine(std::string);
		void addFirstLine(std::string);
		void print();
		void train();

	private:
		typedef struct Column{
			float entropy;
			std::vector<Attribut *> * column;//column of csv file
			//std::string attributName;//this is redundant, its the 1st of col
		}Column;


		std::vector<Column *> mEntropyCol;

		std::vector<Example *> mExample;
		Example mFirstLine;
		Attribut * getAttributFromFirstLine(int);
		std::string getNameFromFirstLine(int);
		void computeEntropy();
		Attribut * getBestAttribut();
		void initEntropy();
		void initAgregaCol();

		//agrecol should be a collection of dif attribut of 1st line
		struct AgregaCol{//same as col, but not 2 same
			int nbOccurence;
			std::vector<Attribut *> * col;//wtf is that 
			void incrByAttribut(std::string);
			Attribut * getAtrr(std::string);
		};

		static std::vector<AgregaCol *> mAgregaCol;
};
#endif
