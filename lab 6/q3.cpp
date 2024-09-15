#include <iostream>
#include <string>
using namespace std;
class Salon{
string appointment;
float charges;
static float  totalcharges;
static float totalEarnings;
static int numApp;

public:
Salon(string a, float c) : appointment(a), charges(c){
    numApp++;
    totalcharges+=charges;
   
}
void display(){
    cout<<"Appointment details:" <<endl;
    cout<<"Service: "<<appointment<<endl;
    cout<<"Cost: "<<charges<<endl;
}
static void numofapp()
{
cout<<"Total number of appointments made are: "<<numApp<<endl;

}
static void avgEarnings(){
    totalEarnings=totalcharges/numApp;
cout<<"The average earnings are: Rs. "<<totalEarnings<<endl;
}

};

int Salon::numApp=0;
float Salon::totalcharges;
float Salon::totalEarnings;
int main()
{

Salon A1("Hair cutting", 2500.0);
A1.display();
    Salon A2("Party Makeup", 6000.0); 
    A2.display();
    Salon A3("Hair cutting", 2500.0);
    A3.display();
    Salon A4("Party Makeup", 6000.0);
    A4.display();
Salon::numofapp();
Salon::avgEarnings();
}