#include "../Headers/HashTable.h"

int main() {
	string text = "jabafajfajfaffaabacavjcadgbeaabacabecadg";
	string patterns[] = {"aabaca", "cadg", "be", "afa"};
	string pattern;
	HashTable table;
	BoyerMoore object;
	BoyerMooreStruct data;
	int i;
	bool flag;

	///Make a table
	table = HashTable(size(patterns));

	///Inserting table
	for (i = 0; i < size(patterns); i++) {
		object = BoyerMoore(text, patterns[i]);
		table.insertItem(object.getObject());
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

	///Choose command
	while (i != 0) {

		cout << endl;

		switch (i) {
			case 1:
				cout << "Enter the pattern: ";
				cin >> pattern;
				cout << endl;

				object = BoyerMoore(text, pattern);
				table.insertItem(object.getObject());

				cout << "Inserting was successful!" << endl << endl;
				break;

			case 2:
				cout << "Enter the pattern: ";
				cin >> pattern;
				cout << endl;

				flag = table.deleteItem(pattern);

				if (flag) {
					cout << "Deleting was successful!" << endl << endl;

				} else {
					cout << "No such entry exists" << endl << endl;
				}
				break;

			case 3:
				cout << "Enter the pattern: ";
				cin >> pattern;
				cout << endl;

				data = table.findItem(pattern);

				if (data.amount == -1) {
					cout << "No such entry exists" << endl << endl;

				} else {
					cout << "Pattern: " << data.pattern << endl;
					cout << "Amount: " << data.amount << endl << endl;
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