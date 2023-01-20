#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node {
    string symbol;
    float probability;
    int arr[10];
    int top;
};

//Function to find Shannon code
void shannon(int l, int h, Node p[]) {
    float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
    int i, k, j;
    
    if ((l + 1) == h || l >= h) {
        if (l == h || l > h) {
            return;
        }
        
        p[h].arr[++(p[h].top)] = 0;
        p[l].arr[++(p[l].top)] = 1;
        return;
        
    } else {
        for (i = l; i <= h - 1; i++) {
            pack1 = pack1 + p[i].probability;
        }
        
        pack2 = pack2 + p[h].probability;
        diff1 = pack1 - pack2;
        
        if (diff1 < 0) {
            diff1 = diff1 * -1;
        }
        
        j = 2;
        
        while (j != h - l + 1) {
            k = h - j;
            pack1 = pack2 = 0;
            
            for (i = l; i <= k; i++) {
                pack1 = pack1 + p[i].probability;
            }
            
            for (i = h; i > k; i--) {
                pack2 = pack2 + p[i].probability;
            }
            
            diff2 = pack1 - pack2;
            
            if (diff2 < 0) {
                diff2 = diff2 * -1;
            }
            
            if (diff2 >= diff1) {
                break;
            }
            
            diff1 = diff2;
            j++;
        }
        
        k++;
        
        for (i = l; i <= k; i++) {
            p[i].arr[++(p[i].top)] = 1;
        }
        
        for (i = k + 1; i <= h; i++) {
            p[i].arr[++(p[i].top)] = 0;
        }

        //Call Shannon function
        shannon(l, k, p);
        shannon(k + 1, h, p);
    }
}

//Function to sort the symbols
void sortByProbability(int n, Node p[]) {
    int i, j;
    Node temp;
    
    for (j = 1; j <= n - 1; j++) {
        for (i = 0; i < n - 1; i++) {
            if ((p[i].probability) > (p[i + 1].probability)) {
                temp.probability = p[i].probability;
                temp.symbol = p[i].symbol;

                p[i].probability = p[i + 1].probability;
                p[i].symbol = p[i + 1].symbol;

                p[i + 1].probability = temp.probability;
                p[i + 1].symbol = temp.symbol;
            }
        }
    }
}

//Function to display shannon codes
void display(int n, Node p[]) {
    int i, j;
    
    cout << "\nSymbol Probability Code";
    
    for (i = n - 1; i >= 0; i--) {
        cout << "\n" << left << setw(7) << p[i].symbol << left << setw(12) << p[i].probability;
        
        for (j = 0; j <= p[i].top; j++) {
            cout << p[i].arr[j];
        }
    }
    
    cout << "\n\n";
}

int main() {
    int n, i;
    float total = 0;
    string ch;
    Node temp, p[20];

    //Input number of symbols
    cout << "Enter number of symbols\t: ";
    n = 5;
    cout << n << endl;

    //Input symbols
    for (i = 0; i < n; i++) {
        cout << "Enter symbol " << i + 1 << ": ";
        ch = (char)(65 + i);
        cout << ch << endl;

        //Insert the symbol to node
        p[i].symbol += ch;
    }
    
    cout << endl;

    //Input probability of symbols
    float x[] = { 0.22, 0.28, 0.15, 0.30, 0.05 };
    
    for (i = 0; i < n; i++) {
        cout << "Enter probability of " << p[i].symbol << ": ";
        cout << x[i] << endl;

        //Insert the value to node
        p[i].probability = x[i];
        total = total + p[i].probability;

        //Checking max probability
        if (total > 1) {
            cout << "Invalid. Enter new values";
            total = total - p[i].probability;
            i--;
        }
    }

    p[i].probability = 1 - total;

    //Sorting the symbols
    sortByProbability(n, p);

    for (i = 0; i < n; i++) {
        p[i].top = -1;
    }

    //Find the Shannon code
    shannon(0, n - 1, p);

    //Display the codes
    display(n, p);
    return 0;
}
