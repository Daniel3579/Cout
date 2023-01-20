#include <iostream>
#include <bitset>

using namespace std;

void f1(int const a);
void f2(int const a);
void f3();
void f4();
void f5();

int main() {
    int const a = 0x4285f4;
    int c;

    cout << "1 - 1 program" << endl
        << "2 - 2 program" << endl
        << "3 - 3 program" << endl
        << "4 - 4 program" << endl
        << "5 - 5 program" << endl
        << "0 - exit" << endl;

    cout << "Choose a program: ";
    cin >> c;
    cout << endl;

    while (c != 0) {

        switch (c) {
            case 1:
                f1(a);
                break;

            case 2:
                f2(a);
                break;
            
            case 3:
                f3();
                break;

            case 4:
                f4();
                break;

            case 5:
                f5();
                break;
            
            default:
                cout << "Unknown number..." << endl;
                break;
        }

        cout << "Choose a program: ";
        cin >> c;
        cout << endl;
    }
}

void f1(int const a) {
    int b;

    b = a | 0b11111000000000;

    cout << "From the 9-th 4 from the left" << endl;
    cout << bitset <24> (a) << endl
        << "000000000011111000000000" << endl
        << bitset <24> (b) << endl << endl;
}

void f2(int const a) {
    int b;

    b = a & 0b111111010111111111111101;

    cout << "17-th, 15-th, 1-st" << endl;
    cout << bitset <24> (a) << endl
        << "111111010111111111111101" << endl
        << bitset <24> (b) << endl << endl;
}

void f3() {
    int a, b;

    cout << "Multiply by 1024" << endl;

    cout << "Enter the number: ";
    cin >> a;
    cout << endl;

    b = a << 10;

    cout << "Multiply by 1024" << endl;
    cout << a << endl << b << endl << endl;
}

void f4() {
    int a, b;

    cout << "Devide by 1024" << endl;

    cout << "Enter the number: ";
    cin >> a;
    cout << endl;

    b = a >> 10;

    cout << "Devide by 1024" << endl;
    cout << a << endl << b << endl << endl;
}

void f5() {
    int a, b, c;

    cout << "n-th bit set to zero" << endl;

    cout << "Enter the number: ";
    cin >> a;
    cout << endl;

    cout << "Enter the n-th bit: ";
    cin >> b;
    cout << endl;

    c = a & ~(0b1 << b);

    cout << b << "-th bit set to zero" << endl;
    cout << bitset <24> (a) << endl << bitset <24> (c) << endl << endl;
}