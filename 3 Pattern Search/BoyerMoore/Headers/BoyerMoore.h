#ifndef COUT_BOYERMOORE_H
#define COUT_BOYERMOORE_H

#include "BoyerMooreStruct.h"
#include <algorithm>
#include <iostream>

class BoyerMoore {
	private:
		BoyerMooreStruct object;

	public:
		BoyerMoore();
		BoyerMoore(const string &text, const string &pattern);
		BoyerMooreStruct getObject();

	private:
		void makeOffsets();
		bool isCharInTheTable(const char &letter);
		int getCharOffset(const char &letter);
};

#endif //COUT_BOYERMOORE_H
