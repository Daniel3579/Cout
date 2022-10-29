#ifndef UNTITLED_HASHTABLE_H
#define UNTITLED_HASHTABLE_H

#include "BoyerMoore.h"

class HashTable {
    private:
        int size;
        int recordsNumber = 0;
        BoyerMooreStruct *table;

    public:
        HashTable();
        HashTable(const int &size);

		BoyerMooreStruct findItem(const string &pattern);

		bool deleteItem(const string &pattern);

		void insertItem(const BoyerMooreStruct &data);
		void outputTable();

    private:
		int findKey(const string &pattern);
        int hashFunction(const string &pattern);
        int collisionSolution(int key);

        void reHashing();
        void tableEnlargement();
};

#endif //UNTITLED_HASHTABLE_H