#include <iostream>
#include <string>
using namespace std;
class bankAccount{
int accNum;
int phoneNum;
string address;
public:
string name; 
string email;
bankAccount(string n, string num, int a, int b, string c) : name(n),email(num), accNum(a), phoneNum(b), address(c) {}
// input is taken using constructor
void displayDetails() //member function 
{
    cout<<"Name: "<< name <<endl;
    cout << "Email: " << email << endl; 
}
friend class Manager;
};
class Manager{
    
    public:
    void privateDetails(bankAccount& acc) //member function
    {
        cout<<"Account Number: "<<acc.accNum<<endl;
         cout<<"Phone Number: "<<acc.phoneNum<<endl;
          cout<<"Address: "<<acc.address<<endl;

    }
};
int main ()
{
bankAccount Hbl("Hamna", "xyz@hotmail.com", 123344, 6573233, "dsfdgfg");
Hbl.displayDetails();
Manager M;
M.privateDetails(Hbl);
return 0;
}