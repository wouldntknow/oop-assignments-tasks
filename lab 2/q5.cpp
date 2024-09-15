#include <iostream>
#include <string>
using namespace std;
void breakString(const string& str, int startIndex, int length, int parts) {
   
    if (parts == 0) {
        return;
    }

    int substringLength = length;
    if (parts == 1) { 
        substringLength = str.length() - startIndex;
    }

   
    string substring = str.substr(startIndex, substringLength);

   
    cout << "Substring " << 4 - parts + 1 << ": " << substring <<endl;

   
    breakString(str, startIndex + substringLength, length, parts - 1);
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int length = input.length() / 4; 
    breakString(input, 0, length, 4);

    return 0;
}
