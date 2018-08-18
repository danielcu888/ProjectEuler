#include <string>
#include <iostream>
#include <stdexcept>

using std::string; using std::cout;
using std::endl; using std::domain_error;

static const int weekday = 7;
static const int January = 31;
static const int February = 28;
static const int LeapFebruary = 29;
static const int March = 31;
static const int April = 30;
static const int May = 31;
static const int June = 30;
static const int July = 31;
static const int August = 31;
static const int September = 30;
static const int October = 31;
static const int November = 30;
static const int December = 31;
static const string daynames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; 
static const int Months[] = {January, February, March, April, May, June, July, August, September, October, November, December};
static const int LeapMonths[] = {January, LeapFebruary, March, April, May, June, July, August, September, October, November, December};
static const int num_months = 12;

bool leap_year(int year)
{
  if(year >= 1900 && year < 2001)
    {
      if(year == 1900)
	return false;
      else if(year == 2000)
	return true;
      else
	{
	  return (double)(year-1900)/4.0 - (year-1900)/4 == 0 ? true : false;
	}
    }
  else
    throw domain_error("invalid year!");
}

int main()
{
  //initial conditons
  int year = 1901;
  int month = 1;
  int day = 1;
  int weekday = 2; //1st Jan 1901 is a Tuesday, determined by running program from 1st Jan 1900 to 31st December 1900
  int sum = 0;

  while(year < 2001)
    {
      bool leap = leap_year(year);

      cout << daynames[weekday-1] << " " << day << " " << month << " " << year << endl;

      if(!leap)
	{
	  if(day == 1 && weekday == 7) 
	    ++sum;
	  
	  if(weekday == 7)
	    weekday = 1;
	  else
	    ++weekday;
	  
	  if(day == Months[month-1])
	    {
	      day = 1;
	      if(month == num_months)
		{
		  month = 1;
		  ++year;
		}
	      else
		++month;
	    }
	  else
	    ++day;
	}
      else
	{
          if(day == 1 && weekday == 7)
	    ++sum;

          if(weekday == 7)
            weekday = 1;
          else
            ++weekday;

          if(day == LeapMonths[month-1])
            {
              day = 1;
              if(month == num_months)
                {
                  month = 1;
                  ++year;
                }
              else
                ++month;
            }
          else
            ++day;
	}
    }

  cout << endl << sum << endl;
  
  return 0;
}
