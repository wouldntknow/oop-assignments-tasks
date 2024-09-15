#include<iostream>
using namespace std;
int main ()
{
    int n;
    float tMarks, avgMarks, mathMarks, sciMarks, engMarks;
    char grade;
    cout<<"Enter the number of students: "<<endl;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Enter Math marks: "<<endl;
        cin>>mathMarks;
        cout<<"Enter Science marks: "<<endl;
        cin>>sciMarks;
        cout<<"Enter English marks: "<<endl;
        cin>>engMarks;

    tMarks=mathMarks+engMarks+sciMarks;
    avgMarks=tMarks/3;
    cout<<"Total marks of Student "<<i+1<<": ";
    cout<<tMarks<<endl;
    cout<<"Average marks of Student "<<i+1<<": ";
    cout<<avgMarks<<endl;
    if(avgMarks>=90)
    {
        grade ='A';
        cout<<"Grade: "<<grade<<endl;
    }
    else if(avgMarks<=89 && avgMarks>=80){
    grade ='B';
     cout<<"Grade: "<<grade<<endl;
}
 else if(avgMarks<=79 && avgMarks>=70){
    grade ='C';
     cout<<"Grade: "<<grade<<endl;
}
 else if(avgMarks<=69 && avgMarks>=60){
    grade ='D';
     cout<<"Grade: "<<grade<<endl;
}
else if(avgMarks<60)
{
    grade='F';
    cout<<"Grade: "<<grade<<endl;
}
}
return 0;
}