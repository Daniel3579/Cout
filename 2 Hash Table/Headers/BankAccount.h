#ifndef UNTITLED_BANKACCOUNT_H
#define UNTITLED_BANKACCOUNT_H

#include <string>

using namespace std;

struct BankAccount {
    int accountNumber;
	string fullName;
    string address;
    bool unlocked = true;
};

#endif //UNTITLED_BANKACCOUNT_H