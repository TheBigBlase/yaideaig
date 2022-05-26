#ifndef ATTRIBUT_HPP
#define ATTRIBUT_HPP
#include <string>
#include <vector>

class Attribut{
	private:
		std::string mName;
		std::string mValue;
	public:
		Attribut(std::string, std::string);
		~Attribut(){};
		float entropy();
		float infoGain();
		float infoEntropy();
		std::string getValue();
		std::string getName();
		void printValue();
		void printName();
};

#endif
