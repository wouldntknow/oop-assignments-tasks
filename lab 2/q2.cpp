#include<iostream>
#include<string>
using namespace std;
void eligibleForExam(int attendance)
{ //function with argument
    if(attendance>=80)
    {
        cout<<"You can sit in exam"<<endl;
    }
    else {
        cout<<"You can't sit in exam. Make sure to not miss classes next time"<<endl;
    }
}
int main()
{
    int attendance;
    eligibleForExam(80); //user input isn't necessary as it is not mentioned in question
     eligibleForExam(60);
    return 0;
}