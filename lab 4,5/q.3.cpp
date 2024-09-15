#include <iostream>
#include<string>
using namespace std;
class WeekDays {
  
  private:
    string Days[7]; 
    int CurrentDay; 

  public:

    WeekDays() {
      
      Days[0] = "Sunday";
      Days[1] = "Monday";
      Days[2] = "Tuesday";
      Days[3] = "Wednesday";
      Days[4] = "Thursday";
      Days[5] = "Friday";
      Days[6] = "Saturday";
    }

    WeekDays(int n) {
      Days[0] = "Sunday";
      Days[1] = "Monday";
      Days[2] = "Tuesday";
      Days[3] = "Wednesday";
      Days[4] = "Thursday";
      Days[5] = "Friday";
      Days[6] = "Saturday";

      CurrentDay = n;
      if (CurrentDay > 6) {
        CurrentDay = CurrentDay % 7;
      }
    }

    string getCurrentDay() {
      
      return Days[CurrentDay];
  }
    string getNextDay() {
      return Days[CurrentDay + 1];
    }

    string getPreviousDay() {
      
      return Days[CurrentDay -1];
    }

  
    string getNthDayFromToday(int N) {
      
      return Days[CurrentDay + N];
    }
};
