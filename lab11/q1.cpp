#include <iostream>
#include <string>
using namespace std;
class Bank{
private:
int balance;
public:

virtual int getBalance(int balance)=0;

};

class BankA: public Bank{
    public:
int getBalance(int balance){
    return balance;
}
};
class BankB: public Bank{
    public:
int getBalance(int balance){
    return balance;
}
};
class BankC: public Bank{
    public:
int getBalance(int balance){
    return balance;
}
};
int main()
{
    BankA a1;
   cout<<"Bank A Balance: "<< a1.getBalance(100)<<endl;
   BankB b1;
   cout<<"Bank B Balance: "<< b1.getBalance(150)<<endl;

BankA c1;
   cout<<"Bank C Balance: "<< c1.getBalance(200)<<endl;



return 0;
}