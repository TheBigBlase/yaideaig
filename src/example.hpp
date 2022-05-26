#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include "classes.hpp"
#include "attribut.hpp"
#include <vector>

class Example{
	public:
		Example(Classes *);
		Example(Classes *, std::vector<Attribut *> *);
		Example();
		~Example(){};
		void add(Attribut);
		void add(std::string, std::string);
		Attribut * getByIndex(int);
		void setClass(Classes &);
		void print();
		void printFirstLine();
		std::vector<Attribut *> *getAttribut();
	private:
		//short mNbAttributes;// needed ?
		bool mIsFirst;
		std::vector<Attribut *> mAttributes;
		Classes mClass;
};
#endif
