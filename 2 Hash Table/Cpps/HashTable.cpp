#include "../Headers/HashTable.h"

HashTable::HashTable() {

}

HashTable::HashTable(int size) {
    this -> size = size;
    this -> table = new BankAccount[this -> size];
}

int HashTable::hashFunction(int accountNumber) {
    return (accountNumber % size);
}

void HashTable::insertItem(BankAccount data) {
    int key;

    key = data.accountNumber;
    key = hashFunction(key);
    key = collisionSolution(key);

    if (key == -1) {
        tableEnlargement();
        key = size - 1;
    }

    table[key] = data;
    table[key].unlocked = false;
    recordsNumber++;

    if ((float) recordsNumber / (float) size >= 0.75) {
        reHashing();
    }
}

int HashTable::collisionSolution(int key) {

    for (key ; key < size; key++) {
        if (table[key].unlocked) {
            return key;
        }
    }

    return -1;
}

void HashTable::reHashing() {
    BankAccount *oldTable;
    int i, key;

    oldTable = table;

    size *= 2;
    table = new BankAccount[size];

    for (i = 0; i < size / 2; i++) {
    	if (!oldTable[i].unlocked) {
    		key = hashFunction(oldTable[i].accountNumber);
			key = collisionSolution(key);

			if (key == -1) {
				tableEnlargement();
				key = size - 1;
			}

			table[key] = oldTable[i];
    	}
    }

    delete [] oldTable;
}

void HashTable::tableEnlargement() {
    BankAccount *oldTable;
    int i;

    oldTable = table;

    size++;
    table = new BankAccount[size];

    for (i = 0; i < size - 1; i++) {
        table[i] = oldTable[i];
    }

    delete [] oldTable;
}

bool HashTable::deleteItem(int accountNumber) {
    int key;

    key = findKey(accountNumber);

    if (key == -1) {
    	return false;

    } else {
		table[key].unlocked = true;
		recordsNumber--;
		return true;
    }
}

int HashTable::findKey(int accountNumber) {
	int key;

	key = hashFunction(accountNumber);

	for (key ; key < size; key++) {
		if (table[key].accountNumber == accountNumber) {
			return key;
		}
	}

	return -1;
}

BankAccount HashTable::findItem(int accountNumber) {
	int key;
	BankAccount account;

	key = findKey(accountNumber);

	if (key == -1) {
		account.accountNumber = -1;
		return account;

	} else {
		return table[key];
	}
}

void HashTable::outputTable() {
    int i;

    for (i = 0; i < size; i++) {
        cout << "table[" << i << "] --> ";
        cout << table[i].accountNumber << ", "
            << table[i].fullName << ", "
            << table[i].address << ", "
            << table[i].unlocked;

        cout << endl;
    }
    cout << endl;
}