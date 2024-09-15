#include<iostream>
#include<string>
using namespace std;
int mcq()
{
    int mcqm;
    cout<<"Enter Mcqs marks: "<<endl;
    cin>>mcqm;
    if(mcqm<=50)
    {  //each section is of 50 marks 
    return mcqm;
    }
    else {
        cout<<"Make sure your marks are in the range. Total marks of each section is 50"<<endl;
        cout<<"Enter again"<<endl;
        mcq();
    }
}
int essay()
{
    int essaym;
    cout<<"Enter Essay marks: "<<endl;
    cin>>essaym;
     if(essaym<=50)
    {  //each section is of 50 marks 
    return essaym;
    }
    else {
        cout<<"Make sure your marks are in the range. Total marks of each section is 50"<<endl;
        cout<<"Enter again"<<endl;
        essay();
    }
    
}
int viva()
{
    int vivam;
    cout<<"Enter Viva marks: "<<endl;
    cin>>vivam;
    if(vivam<=50)
    {  //each section is of 50 marks 
    return vivam;
    }
    else {
        cout<<"Make sure your marks are in the range. Total marks of each section is 50."<<endl;
        cout<<"Enter again"<<endl;
        viva();
    }
}
int main ()
{


    if(mcq()+essay()+viva()>=75)
    {
        cout<<"You have passed the test and are elgible for CYs Program!"<<endl;
    }
    else{
        cout<<"Didn't pass. You're not eligible.Better luck next time!"<<endl;
    }
    return 0;
    }