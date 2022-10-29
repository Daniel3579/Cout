#ifndef UNTITLED_HASHTABLE_H
#define UNTITLED_HASHTABLE_H

#include <iostream>
#include "BankAccount.h"

class HashTable {
    private:
        int size;
        int recordsNumber = 0;
        BankAccount *table;

    public:
        HashTable();
        HashTable(int size);

		BankAccount findItem(int accountNumber);

		bool deleteItem(int accountNumber);

		void insertItem(BankAccount data);
		void outputTable();

    private:
		int findKey(int accountNumber);
        int hashFunction(int accountNumber);
        int collisionSolution(int key);

        void reHashing();
        void tableEnlargement();
};

#endif //UNTITLED_HASHTABLE_H