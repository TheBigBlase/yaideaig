#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <string>
#include <vector>
#include "attribut.hpp"

class Classes{//represents outcome
	private:
		std::string mOutcome;
	public:
		//float entropy();
		//float infoGain();
		//float infoEntropy();
		Classes(std::string);
		Classes();
		~Classes(){};
		void setOutcome(std::string);
		std::string getOutcome();
		void print();
};

#endif
