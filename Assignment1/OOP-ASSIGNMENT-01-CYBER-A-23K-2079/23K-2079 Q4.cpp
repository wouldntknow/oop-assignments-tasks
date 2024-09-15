//23K-2079
#include<iostream>
using namespace std;

class rollercoaster {
    string name;
    int height;
    int length;
    int speed;
    int personcapacity;
    int currentriderseated;
    bool rideinprogress;

public:

    rollercoaster() 
	{
        name = "rollercoaster";
        height = 500;
        length = 2000;
        speed=0;
        personcapacity = 20;
        currentriderseated=0;
        rideinprogress = false;
    }
    rollercoaster(string name,int height,int length,int speed,int personcapacity,int currentriderseated,bool rideinprogress )
    {
    	this->name=name;
    	this->height=height;
    	this->speed=speed;
    	this->length=length;
    	this->personcapacity=personcapacity;
    	this->currentriderseated=currentriderseated;
    	this->rideinprogress=rideinprogress;
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

    void setpersoncapacity(int personcapacity) 
	{
        this->personcapacity = personcapacity;
    }

    void setcurrentriderseated(int currentriderseated) 
	{
        this->currentriderseated = currentriderseated;
    }

    void setrideinprogress(bool rideinprogress) 
	{
        this->rideinprogress = rideinprogress;
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

    int getpersoncapacity() 
	{
        return personcapacity;
    }

    int getcurrentriderseated() 
	{
        return currentriderseated;
    }

    bool getrideinprogress() 
	{
        return rideinprogress;
    }

    void display() {
        cout << "customer name is : " << name << endl;
        cout << "height of ride is : " << height << endl;
        cout << "length of ride is : " << length << endl;
        cout << "speed of ride is : " << speed << endl;
        cout << "person capacity in one ride is : " << personcapacity << endl;
        cout << "current persons on ride is : " << currentriderseated << endl;
        cout << "ride in progress : " << rideinprogress << endl;
       
        
    }

    void seatriders() 
	{
        int person;
        cout << "enter how many persons want to seat : " << endl;
        cin >> person;
        if (currentriderseated >= personcapacity) 
		{
            cout << "ride is full. No space available" << endl;
        }
        else 
		{
            currentriderseated += person;
        }
    }

    int startride() 
	{
        if (rideinprogress) 
		{
            return -1;
        }
        else if (currentriderseated <= personcapacity)
		 {
            int emptyseat= personcapacity - currentriderseated;
            return emptyseat;
              
        }
        
        else 
		{
            rideinprogress = true;
            return 0;
        }
        
    }
    
    
    int stopride()
    {
    	
    	if(rideinprogress ==true)
    	{
    		rideinprogress =false;
    		cout<<"STOPPED RIDE SUCCESSFULLY"<<endl;
    		
		}
		else{
			cout<<"CANNOT STOP RIDE .RIDE IS IN PROCESS"<<endl;
		}
	}
	
   int unloadriders()
   {
   	if(rideinprogress == false)
   	{
   		currentriderseated = 0;
   		cout<<"UNLOADING RIDERS "<<endl;
   		return currentriderseated;
	   }
	   else
	   {
	   	cout<<"CANNOT ULOAD RIDERS BECAUSE RIDE IS IN PROGRESS"<<endl;
	   }
   }
   
   int accelerate()
   {
   	int rollno;
   	cout<<"enter your roll no : "<<endl;
   	cin>>rollno;
   	while(rollno%10==0)
	   {
   		rollno /=10;
	   }
   	 rollno=rollno%10;
   	 speed+=rollno;
   	 
   	 	
	}
	

   
   
   void slowdown()
   {
   	int rollno;
   	cout<<"enter your roll no : "<<endl;
   	cin>>rollno;
   while(rollno>=10)
   {
   		rollno /=10;
	   }
	   speed -=rollno;
	   rideinprogress=true;
   }
};

int main() 
{
    rollercoaster ride("roller coaster",15,12,40,6,4,"true");
    ride.setname("roller coaster");
    ride.setheight(15);
    ride.setlength(1);
    ride.setspeed(40);
    ride.setpersoncapacity(6);
    ride.setcurrentriderseated(4);
    ride.setrideinprogress(true);
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
    int emptyseat=ride.startride();
    cout << "empty seat is : " << emptyseat << endl;
    cout << endl;
    ride.display();
    
    cout<<endl;
    cout<<"STOPPING RIDE  INFORMATION"<<endl;
    cout<<"****************************"<<endl;
    ride.stopride();
    ride.display();
    cout<<endl;
    
    cout<<" UNLOAD RIDERS"<<endl;
    cout<<"**************************"<<endl;
	ride.unloadriders();
    ride.display();
    
    cout<<endl;
    cout<<"ACCELERATE"<<endl;
    cout<<"*************************"<<endl;
    ride.accelerate();
    ride.display();
    
    cout<<endl;
    cout<<"SLOWS DOWN"<<endl;
    cout<<"****************************"<<endl;
    ride.slowdown();
    ride.display();


    return 0;
}
