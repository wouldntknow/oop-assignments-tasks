#include <iostream>
using namespace std;

int main() {
    int num;
    int flag = 1; 

    cout << "Enter a number: ";
    cin >> num;

    if (num <= 1) {
        cout << "Number is not prime" << endl;
        return 0;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            flag = 0; 
            break;
        }
    }

    if (flag == 1) {
        cout << "Number is prime" << endl;
    } else {
        cout << "Number is not prime" << endl;
    }

    return 0;
}
