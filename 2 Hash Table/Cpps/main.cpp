#include "../Headers/HashTable.h"

void manualInput(HashTable &table, int size);

void autoInput(HashTable &table, int size);

int main() {
    HashTable table;
    BankAccount account;
    int size, i, accountNumber;
    bool flag = false;

    cout << endl << "Enter number of records: ";
    cin >> size;
    cout << endl;

    table = HashTable(size);

    cout << "How to fill in the table?" << endl;
    cout << "\t 1) Automatically" << endl;
    cout << "\t 2) Manually" << endl;
    cout << "Enter the number: ";

	while (cin >> i) {
		cout << endl;
		switch (i) {
			case 1:
				autoInput(table, size);
				flag = true;
				break;

			case 2:
				manualInput(table, size);
				flag = true;
				break;

			default:
				cout << "Unidentified number" << endl;
				cout << "Try again: ";
		}

		if (flag) {
			break;
		}
	}

	cout << "Filling was successful!" << endl << endl;

	cout << "You can use 4 operations:" << endl;
	cout << "\t 1) Inserting data into a table" << endl;
	cout << "\t 2) Deleting data from a table" << endl;
	cout << "\t 3) Finding data by key" << endl;
	cout << "\t 4) Show table" << endl;
	cout << "\t 0) End the program" << endl;

	cout << "Enter the number: ";
	cin >> i;

	while (i != 0) {
		cout << endl;
		switch (i) {
			case 1:
				cout << "Account number: ";
				cin >> account.accountNumber;

				cout << "Full name: ";
				cin >> account.fullName;

				cout << "Address: ";
				cin >> account.address;

				table.insertItem(account);
				cout << endl << "Inserting was successful!" << endl << endl;
				break;

			case 2:
				cout << "Enter the account number: ";
				cin >> accountNumber;
				cout << endl;

				flag = table.deleteItem(accountNumber);

				if (flag) {
					cout << "Deleting was successful!" << endl << endl;

				} else {
					cout << "No such entry exists" << endl << endl;
				}
				break;

			case 3:
				cout << "Enter the account number: ";
				cin >> accountNumber;
				cout << endl;

				account = table.findItem(accountNumber);

				if (account.accountNumber == -1) {
					cout << "No such entry exists" << endl << endl;

				} else {
					cout << "Account number: " << account.accountNumber << endl;
					cout << "Full name: " << account.fullName << endl;
					cout << "Address: " << account.address << endl << endl;
				}
				break;

			case 4:
				table.outputTable();
				break;

			default:
				cout << "Unidentified number" << endl;
				cout << "Try again. ";
		}

		cout << "Enter the number: ";
		cin >> i;
	}

    return 0;
}

void manualInput(HashTable &table, int size) {
	BankAccount account;
	int i;

	for (i = 0; i < size; i++) {
        cout << "Record " << i + 1 << ":" << endl;

        cout << "\t Account number: ";
        cin >> account.accountNumber;

        cout << "\t Full name: ";
        cin >> account.fullName;

        cout << "\t Address: ";
        cin >> account.address;
        cout << endl;

        table.insertItem(account);
    }
}

void autoInput(HashTable &table, int size) {
	int i;
	BankAccount account;
	string names[21] = {"Daniel", "Andrey", "Artem", "Alex", "Roman",
						"Igor", "Nastya", "Natali", "Katya", "Tanya",
						"Dmitry", "Kirill", "Eren", "Arina", "Vika",
						"Angel", "Ilia", "Max", "Yana", "Ivan", "Margo"};

	for (i = 0; i < size; i++) {
		account.accountNumber = rand() % 10000000 + 1000000;
		account.fullName = names[rand() % 21];
		account.address = to_string(rand() % 10000 + 1000);

		table.insertItem(account);
	}
}