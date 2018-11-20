#include <iostream>
using namespace std;
int main()
{
    int year = 0;
    int mon = 1;
    int count = 0;
    int day = 1;
    int day_of_week = 1;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(year != 101)
    {
        day++;
        day_of_week++;      
        if(day_of_week > 7)
        {
            day_of_week = 1;
        }
        if(day > months[mon])
        {
            day = 1;
            mon++;
        }  
        if(day_of_week == 7 && day == 1)
        {
            if(year>0)
            {
                count++;
            }        
        }
        if(mon > 12)
        {
            mon = 1;
            year++;
        }
    }
    cout << count << endl;
}
