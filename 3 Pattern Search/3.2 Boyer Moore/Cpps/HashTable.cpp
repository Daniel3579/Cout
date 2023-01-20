#include "../Headers/HashTable.h"

HashTable::HashTable() {

}

HashTable::HashTable(const int &size) {
    this -> size = size;
    this -> table = new BoyerMooreStruct[this -> size];
}

int HashTable::hashFunction(const string &pattern) {
	int i, key = 0;

	///Converting letters to numbers
	for (i = 0; i < pattern.size(); i++) {
		key += (int) pattern[i];
	}

    return (key % size);
}

void HashTable::insertItem(const BoyerMooreStruct &data) {
    int key;
    string pattern;

    ///Key calculation
    pattern = data.pattern;
    key = hashFunction(pattern);
    key = collisionSolution(key);

    ///Exception handling
    if (key == -1) {
        tableEnlargement();
        key = size - 1;
    }

    ///Write to the table
    table[key] = data;
    table[key].unlocked = false;
    recordsNumber++;

    ///Rehash check
    if ((float) recordsNumber / (float) size >= 0.75) {
        reHashing();
    }
}

int HashTable::collisionSolution(int key) {

	///Check for free cells
    for (key ; key < size; key++) {
        if (table[key].unlocked) {
            return key;
        }
    }

    return -1;
}

void HashTable::reHashing() {
    BoyerMooreStruct *oldTable;
    int i, key;

    ///Copying the old table
    oldTable = table;

    ///Overwriting the current table
    size *= 2;
    table = new BoyerMooreStruct[size];

    ///Iterate over the elements of the old table
    for (i = 0; i < size / 2; i++) {

    	///Overwrite only occupied cells
    	if (!oldTable[i].unlocked) {

    		///Key calculation
    		key = hashFunction(oldTable[i].pattern);
			key = collisionSolution(key);

			///Exception handling
			if (key == -1) {
				tableEnlargement();
				key = size - 1;
			}

			///Write to the NEW table;
			table[key] = oldTable[i];
    	}
    }

    delete [] oldTable;
}

void HashTable::tableEnlargement() {
    BoyerMooreStruct *oldTable;
    int i;

	///Copying the old table
    oldTable = table;

	///Overwriting the current table
    size++;
    table = new BoyerMooreStruct[size];

	///Iterate over the elements of the old table
    for (i = 0; i < size - 1; i++) {
        table[i] = oldTable[i];
    }

    delete [] oldTable;
}

bool HashTable::deleteItem(const string &pattern) {
    int key;

    ///Finding key
    key = findKey(pattern);

    ///Element NOT found
    if (key == -1) {
    	return false;

	///Element found
    } else {
		table[key].unlocked = true;
		recordsNumber--;
		return true;
    }
}

int HashTable::findKey(const string &pattern) {
	int key;

	///Key calculation
	key = hashFunction(pattern);

	///Traversing the table looking for the RIGHT key
	for (key ; key < size; key++) {
		if (table[key].pattern == pattern) {
			return key;
		}
	}

	return -1;
}

BoyerMooreStruct HashTable::findItem(const string &pattern) {
	int key;
	BoyerMooreStruct account;

	///Finding key
	key = findKey(pattern);

	///Exception handling
	if (key == -1) {
		account.amount = -1;
		return account;

	///Return data
	} else {
		return table[key];
	}
}

void HashTable::outputTable() {
    int i;

    ///From the beginning to the end of the table
    for (i = 0; i < size; i++) {
        cout << "table[" << i << "] --> ";
        cout << table[i].pattern << ", "
            << table[i].amount << ", "
            << table[i].unlocked;

        cout << endl;
    }

    cout << endl;
}