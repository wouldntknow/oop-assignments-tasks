#include <iostream>
#include <cstring>
using namespace std;
class bankAcc{
int accId;
double balance;
public:
int *transactHis;
int numTrans;



bankAcc(int id, double bal, int* transactHis, int num ): accId(id), balance(bal), numTrans(num)
{
transactHis=new int[num];
memcpy(transactHis, transactHis, numTrans * sizeof(int));
}
bankAcc(const bankAcc& copyAcc): accId(copyAcc.accId),balance(copyAcc.balance),numTrans(copyAcc.numTrans), transactHis(copyAcc.transactHis)
{
    // copy constructor
}
~bankAcc() //destructor
{
    delete[] transactHis;
}
void display()
{
    cout<<"ID: "<<accId<<endl;
    cout<<"Balance: "<<balance<<endl;
    cout<<"Transaction History: "<<endl;
    for(int i=0;i<numTrans;i++)
    {
        cout<<transactHis[i]<<endl;
    }
    

}

void updateTransactionHistory(int* newTransactions, int newNumTransactions) {
        delete[] transactHis;  
       transactHis= new int[newNumTransactions];
        
        memcpy(transactHis, newTransactions, newNumTransactions * sizeof(int));
      
        numTrans = newNumTransactions;
    }
};
int main()
{
    int initialTransactions[] = {100, 50, 200, 100};
    int numTransactions = sizeof(initialTransactions) / sizeof(int);

bankAcc account1(123456, 1000.0, initialTransactions, numTransactions);

bankAcc account2 = account1;

 cout << "Original Account:\n";
    account1.display();
    cout << "\nCopied Account:\n";
    account2.display();

     int newTransactions[] = {50, 20, 150};
    int newNumTransactions = sizeof(newTransactions) / sizeof(int);
    account1.updateTransactionHistory(newTransactions, newNumTransactions);

    
    cout << "\nOriginal Account After Update:\n";
    account1.display();

    return 0;



}