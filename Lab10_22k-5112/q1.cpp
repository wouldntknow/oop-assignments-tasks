#include <iostream>
#include <string>
using namespace std;
 class Message;
 class User{
string name, email;
public:
User(string n,string e): name(n), email(e){}
friend void display(User &p1, Message& mi);

//friend class Message;
 };

void display(User &p1, Message& mi)
{
    cout<<"name"<<p1.name;
}
 class Message{
    public:
/*void printMessage(User& u1)
{
    cout<<"Name of user: "<<u1.name<<endl;
    cout<<"Email of user: "<<u1.email<<endl; //accessing private members of Class user
    cout<<"This user says: Your application has been acccepted!"<<endl; // the message
}*/
friend void display(User& p1, Message& mi);

 };
 int main(){
    User u1("hamna", "xyz@gmail.com");
    Message m1;
    //m1.printMessage(u1);
display(u1,m1);
    return 0;
 }