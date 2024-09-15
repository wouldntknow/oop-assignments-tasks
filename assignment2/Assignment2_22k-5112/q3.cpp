#include <iostream>
#include<string>
using namespace std;
class DarazPersonData{
string lastName;
string phone;
string zip;
string address;
public: 
string firstName;
string state;
 
 DarazPersonData(string a, string b, string c, string d, string e, string f):firstName(a),lastName(b), phone(c),state(d),zip(e),
 address(f){}

 void diplayDeets()
 {
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Phone Name: "<<phone<<endl;
    cout<<"State Name: "<<state<<endl;
    cout<<"Zip Code: "<<zip<<endl;
    cout<<"Address: "<<address<<endl;
 }

};
class DarazCustomerData{
    int customerNum;
    int loyaltyPoints;
    public:
  DarazCustomerData(int c, int l): customerNum(c), loyaltyPoints(l){}
   
void display()
{
    
    cout<<"Customer Id: "<<customerNum<<endl;
    cout<<"Loyalty Points: "<<loyaltyPoints<<endl;
}
friend class DarazLoyaltyProgram;
};
class DarazLoyaltyProgram{
public:
int purchases; 
float discount=0.00;
int totalPoints;
int c;

DarazLoyaltyProgram(int a): purchases(a){}
void redeem( DarazCustomerData d1)
{
    if(purchases>6)
{
    cout<<"You have purchased a total of "<<purchases<<" items. Congratulations you are eligible for our loyalty program!"<<endl;
    discount=d1.loyaltyPoints;
   d1.loyaltyPoints++; //increasing only 1 on every checkout
   cout<<"Your loyaly points have been updated successfully."<<endl;
   totalPoints=d1.loyaltyPoints;
   cout<<"Total Loyalty Points: "<<totalPoints<<endl;
   cout<<"Do you want to redeem your loyaly points for discount?"<<endl;
   cout<<"Enter 1 for Yes and 0 for No"<<endl;
   cin>>c;
   if(c==1){
    cout<<"Your loyalty points have been redeemed!"<<endl;
    cout<<"You're getting a discount of " <<discount<<" %. Thank you for shopping with us!"<<endl;}
    else if(c==0){
        cout<<"You can redeem them later if you want!"<<endl;
    }
    else {
        cout<<"Invalid response. Try again!"<<endl;;
    }
}
else{
    cout<<"Sorry you're not eligible for out loyaly program."<<endl;
    cout<<" To be eligible and get discounts you have to make more than 6 purchases, Keep shopping!"<<endl;
}
}
};
int main()
{
    DarazPersonData p1("Hamna", "Uraizee"," 0335565768", "Karachi", "75465", "pechs society");
    p1.diplayDeets();
    DarazCustomerData d1(5112, 10);
    d1.display();
    DarazLoyaltyProgram l1(7);
    l1.redeem(d1);
}