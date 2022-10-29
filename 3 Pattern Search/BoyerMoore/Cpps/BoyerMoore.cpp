#include "../Headers/BoyerMoore.h"

BoyerMoore::BoyerMoore() {

}

BoyerMoore::BoyerMoore(const string &text, const string &pattern) {
	this -> object.pattern = pattern;
	makeOffsets();
	
	int i, j, t, step;
	int c = 0;
	int s = pattern.size() - 1;

	///From the end of the pattern to the end of the text
	for (i = s; i < text.size(); i) {

		///From the end of the pattern to the beginning
		for (j = s; j >= 0; j--) {
			step = s - j;
			t = i - step;

			///If the letters match
			if (pattern[j] == text[t]) {
				c++;

			} else {

				///If step more than offset
				if (getCharOffset(text[t]) < step) {
					step = 0;
				}

				///Make a shift
				i += getCharOffset(text[t]) - step;
				c = 0;
				break;
			}
		}
		///If matching amount is equal words length
		if (c == s + 1) {
			object.amount++;
			c = 0;
			i++;
		}
	}
}

void BoyerMoore::makeOffsets() {
	pair <char, int> twix;
	int i;
	int s = object.pattern.size() - 1;

	///From penultimate to beginning
	for (i = s - 1; i >= 0; i--) {

		///If the element is not in the table
		if (!isCharInTheTable(object.pattern[i])) {
			twix = make_pair(object.pattern[i], s - i);
			object.offsets.push_back(twix);
		}
	}

	///For the last element
	if (!isCharInTheTable(object.pattern[s])) {
		twix = make_pair(object.pattern[s], s + 1);
		object.offsets.push_back(twix);
	}
}

bool BoyerMoore::isCharInTheTable(const char &letter) {
	int i;

	///Enumeration of values
	for (i = 0; i < object.offsets.size(); i++) {
		if (object.offsets[i].first == letter) {
			return true;
		}
	}

	return false;
}

int BoyerMoore::getCharOffset(const char &letter) {
	int i;

	///Enumeration of values
	for (i = 0; i < object.offsets.size(); i++) {
		if (object.offsets[i].first == letter) {
			return object.offsets[i].second;
		}
	}

	return object.pattern.size();
}

BoyerMooreStruct BoyerMoore::getObject() {
	return object;
}