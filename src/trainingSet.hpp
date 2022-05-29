#ifndef TRAININGSET_HPP
#define TRAININGSET_HPP
#include "example.hpp"
#include <vector>
#include <string>

class TrainingSet{
	private:
		typedef struct Column{
			float entropy;
			std::vector<Attribut *> * mCol;//column of csv file
			//std::string attributName;//this is redundant, its the 1st of col
		}Column;


		static std::vector<Column *> mEntropyCol;

		std::vector<Example *> mExample;
		Example mFirstLine;

		Attribut * getAttributFromFirstLine(int);
		std::string getNameFromFirstLine(int);
		Attribut * getBestAttribut();

		void initEntropy();
		void initAgregaCol();

		struct LineAgreaCol{
			int mNbOccurence;
			std::string mName;//name of col
			std::vector<Attribut *> * mLine;
			void print();
		};
		//agrecol should be a collection of dif attribut of 1st line
		struct AgregaCol{//same as col, but not 2 same
			std::vector<LineAgreaCol *> * mCol;
			void add(Attribut *);
			void print();
		};

		static AgregaCol mAgregaCol;

		static Attribut * getAttrFromAgrega(std::string);
		static void incrByAttribut(std::string);
		static void incrByAttribut(Attribut *);
		void computeEntropy();

		static bool isIn(std::vector<Column *> *, Attribut *);

	public:
		TrainingSet();
		~TrainingSet(){};

		void addLine(std::string);
		void addFirstLine(std::string);
		void print();
		void train();


		AgregaCol * getAgreCol();

		void printEn();

};
#endif
