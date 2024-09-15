#include <iostream>
#include<string>
using namespace std;
struct event{
    string name;
    string date;
    string venue;
 string organizer;
};

int main()
{
 event events;
    int num;
    cout<<"Enter number of events: "<<endl;
    cin>>num;
    string date;
    event *array=new event[num]; // allocation of memory
   for(int i=0;i<num;i++)
{
    cout<<"Event Name: "<<endl;
    cin>>array[i].name;
    cout<<"Event Venue: "<<endl;
    cin>>array[i].venue;
    cout<<"Event Date: "<<endl;
    cin>>array[i].date;
    cout<<"Event Organizer: "<<endl;
    cin>>array[i].organizer;

}
cout<<"Enter the date you want the details for: "<<endl;
cin>>date;
    for(int i=0;i<num;i++)
    {
if(date==array[i].date)
{
    std:cout<<"Even details are: "<<endl;
std::cout<<"Event Name: "<<array[i].name<<endl;
std::cout<<"Event Venue: "<<array[i].venue<<endl;
std::cout<<"Event Date: "<<array[i].date<<endl;
std::cout<<"Event Oragnizer: "<<array[i].organizer<<endl;

}
    }
    cout<<endl;

    delete[] array;

    return 0;

}