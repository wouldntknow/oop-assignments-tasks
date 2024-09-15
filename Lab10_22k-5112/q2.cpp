#include<iostream>
#include<string>
using namespace std;
class Vehicle{
    string name, company;
    int rentalRate=2000, days;
  public:
    Vehicle(string n, string c,int days):name(n),company(c){}
    friend class car;
    friend class Motorcycle;
    friend class Bicycle;
};

class car: public Vehicle{
string model;
int year, t=0;
public:
car(string n,string c, int d, string m, int y): Vehicle(n,c,d), model(m), year(y){}
void details(Vehicle v1)
{
    cout<<"Car name: "<<v1.name<<endl;
cout<<"Car model: "<<model<<endl;
cout<<"Car company: "<<v1.company<<endl;
cout<<"Car year: "<<year<<endl;
cout<<"Rent per day: "<<v1.rentalRate<<endl;
t=v1.rentalRate*days;
cout<<"Total rent: Rs.  "<<t<<endl;
}
friend class Motorcycle;
friend class Bicycle;
};


class Motorcycle: public car{
string color;
int size;
int total=0;
public:
Motorcycle(string name,string company, int d, string clr, string model, int year, int s):car(name,company,d,model,year), color(clr), size(s){}
void details(Vehicle v1, car c1)
{
    cout<<"Motorcycle name: "<<v1.name<<endl;
cout<<"Motorcycle model: "<<c1.model<<endl;
cout<<"Motorcycle company: "<<v1.company<<endl;
cout<<"Motorcycle year: "<<c1.year<<endl;
cout<<"Motorcycle color: "<<color<<endl;
cout<<"Motocycle size: "<<size<<endl;
cout<<"Rent per day: "<<v1.rentalRate<<endl;

total=v1.rentalRate*v1.days;
cout<<"Total rent: Rs.  "<<total<<endl;
}
friend class Bicycle;
};
class Bicycle: public Motorcycle{
    string condition;
int tl=0;
public:
Bicycle(string n,string c, int d, string clr, string m, int y, int s,string cnd): Motorcycle(n,c,d,clr,m,y,s),condition(cnd){}

void details(Vehicle v1, car c1, Motorcycle m1)
{
    cout<<"Bicycle name: "<<v1.name<<endl;
cout<<"Bicycle model: "<<c1.model<<endl;
cout<<"Bicycle company: "<<v1.company<<endl;
cout<<"Bicycle year: "<<c1.year<<endl;
cout<<"Bicycle color: "<<m1.color<<endl;
cout<<"Bicycle size: "<<m1.size<<endl;
cout<<"Rent per day: "<<v1.rentalRate<<endl;

tl=v1.rentalRate*days;
cout<<"Total rent: Rs.  "<<tl<<endl;
}
};
int main()
{
    Vehicle v1("switft","suzuki",7);
car c1("switf","suzuki",10,"ahbjhs",2000);
c1.details(v1);
Motorcycle m1("sff","dfd" ,8,"red","1999", 456,8966);
m1.details(v1,c1);
Bicycle b1("gvh","toyota",10,"silver","dhfh",2019,76879,"good");
b1.details(v1,c1,m1);

}