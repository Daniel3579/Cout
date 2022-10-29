#ifndef COUT_BOYERMOORESTRUCT_H
#define COUT_BOYERMOORESTRUCT_H

#include <string>
#include <vector>
using namespace std;

struct BoyerMooreStruct {
	string pattern;
	int amount = 0;
	vector <pair <char, int>> offsets;
	bool unlocked = true;
};

#endif //COUT_BOYERMOORESTRUCT_H
