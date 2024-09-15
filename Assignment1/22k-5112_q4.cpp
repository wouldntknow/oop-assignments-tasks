//23K-2079
#include<iostream>
using namespace std;

class rollercoaster {
    string name;
    int height;
    int length;
    int speed;
    int capacity;
    int Ridersseated;
    bool Rideinprog;

public:

    rollercoaster() 
	{
        name = "Ride or Die";
        height = 500;
        length = 2000;
        speed=0;
        capacity = 20;
        Ridersseated=0;
        Rideinprog = false;
    }
    rollercoaster(string name,int height,int length,int speed,int capacity,int Ridersseated,bool Rideinprog )
    {
    	this->name=name;
    	this->height=height;
    	this->speed=speed;
    	this->length=length;
    	this->capacity=capacity;
    	this->Ridersseated=Ridersseated;
    	this->Rideinprog=Rideinprog;
	}

    void setname(string name)
	 {
        this->name = name;
    }

    void setheight(int height)
	 {
        this->height = height;
    }

    void setlength(int length)
    {
        this->length = length;
    }

    void setspeed(int speed) 
	{
        this->speed = speed;
    }

    void setcapacity(int capacity) 
	{
        this->capacity = capacity;
    }

    void setRidersseated(int Ridersseated) 
	{
        this->Ridersseated = Ridersseated;
    }

    void setRideinprog(bool Rideinprog) 
	{
        this->Rideinprog = Rideinprog;
    }

    string getname() 
	{
        return name;
    }

    int getheight() {
        return height;
    }

    int getlength() 
	{
        return length;
    }

    int getspeed() 
	{
        return speed;
    }

    int getcapacity() 
	{
        return capacity;
    }

    int getRidersseated() 
	{
        return Ridersseated;
    }

    bool getRideinprog() 
	{
        return Rideinprog;
    }

    void display() {
        cout << "Attraction name: " << name << endl;
        cout << "Height of ride : " << height << endl;
        cout << "Length of ride : " << length << endl;
        cout << "Speed of ride: " << speed << endl;
        cout << "p capacity in one ride: " << capacity << endl;
        cout << "Current ps on ride : " << Ridersseated << endl;
        cout << "Ride in progress : " << Rideinprog << endl;
       
        
    }

    void seatriders() 
	{
        int p;
        cout << "Enter number of people seated : " << endl;
        cin >> p;
        if (Ridersseated >= capacity) 
		{
            cout << "ride is full. No space available" << endl;
        }
        else 
		{
            Ridersseated += p;
        }
    }

    int Startride() 
	{
        if (Rideinprog) 
		{
            return -1;
        }
        else if (Ridersseated <= capacity)
		 {
            int emptyseat= capacity - Ridersseated;
            return emptyseat;
              
        }
        
        else 
		{
            Rideinprog = true;
            return 0;
        }
        
    }
    
    
    int StopRide()
    {
    	
    	if(Rideinprog ==true)
    	{
    		Rideinprog =false;
    		cout<<"STOPPED RIDE SUCCESSFULLY!"<<endl;
    		
		}
		else{
			cout<<"CANNOT STOP THE RIDE.RIDE IS IN PROCESS"<<endl;
		}
	}
	
   int UnloadRiders()
   {
   	if(Rideinprog == false)
   	{
   		Ridersseated = 0;
   		cout<<"UNLOADING RIDERS "<<endl;
   		return Ridersseated;
	   }
	   else
	   {
	   	cout<<"CANNOT ULOAD RIDERS BECAUSE RIDE IS IN PROGRESS"<<endl;
	   }
   }
   
   int Acc()
   {
   	int rollno;
   	cout<<"Enter your roll no : "<<endl;
   	cin>>rollno;
   	while(rollno%10==0)
	   {
   		rollno /=10;
	   }
   	 rollno=rollno%10;
   	 speed+=rollno;
   	 
   	 	
	}
	

   
   
   void SlowD()
   {
   	int rollno;
   	cout<<"Enter your roll no : "<<endl;
   	cin>>rollno;
   while(rollno>=10)
   {
   		rollno /=10;
	   }
	   speed -=rollno;
	   Rideinprog=true;
   }
};

int main() 
{
    rollercoaster ride("Ride or Die",15,12,40,6,4,"true");
    ride.setheight(15);
    ride.setlength(1);
    ride.setspeed(40);
    ride.setcapacity(6);
    ride.setRidersseated(4);
    ride.setRideinprog(true);
    cout<<"DISPLAY ALL INFORMATION"<<endl;
    cout<<"***************************"<<endl;
    ride.display();
    cout<<"****************************"<<endl;
    
    
    cout << endl;
    cout<<"**************************"<<endl;
    cout<<"DISPLAY SEATED RIDERS"<<endl;
    ride.seatriders();
    cout << endl;
    ride.display();
    cout<<"***************************"<<endl;
    
    
    cout << endl;
    cout<<"START RIDE INFORMATION"<<endl;
    cout<<"************************"<<endl;
    int emptyseat=ride.Startride();
    cout << "empty seat : " << emptyseat << endl;
    cout << endl;
    ride.display();
    
    cout<<endl;
    cout<<"STOPPING RIDE  INFORMATION"<<endl;
    cout<<"****************************"<<endl;
    ride.StopRide();
    ride.display();
    cout<<endl;
    
    cout<<" UNLOAD RIDERS"<<endl;
    cout<<"**************************"<<endl;
	ride.UnloadRiders();
    ride.display();
    
    cout<<endl;
    cout<<"Acceleration"<<endl;
    cout<<"*************************"<<endl;
    ride.Acc();
    ride.display();
    
    cout<<endl;
    cout<<"SLOWS DOWN"<<endl;
    cout<<"****************************"<<endl;
    ride.SlowD();
    ride.display();


    return 0;
}
