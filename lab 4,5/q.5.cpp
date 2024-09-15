#include<iostream>
#include<string>
using namespace std;
class ValidateString {
  
  private:
    string str; 

  
  public:
    
    ValidateString(string a) {

      str = a;
    }

    // A constant function that checks whether the string variable is valid or not
    // We make a function constant when we do not want to modify the object's state
    // If we do not make the function constant, we cannot use it on constant objects because a non-constant fuction cannot be used for a constant object and vice versa
    bool isValid() const {

      for (char c : str) {
        if (!isalpha(c)) {
          return false;
        }
      }
      return true;
    }
};


int main() {
  
  ValidateString vs1("Hi");
  ValidateString vs2("84839");
  ValidateString vs3("Sir!"); //wont accept because of "!"


  cout << "Is vs1 valid? " << vs1.isValid() << endl; //1
  cout << "Is vs2 valid? " << vs2.isValid() << endl; //0
  cout << "Is vs3 valid? " << vs3.isValid() << endl; //0

  return 0;
}
