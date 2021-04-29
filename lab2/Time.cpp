#include "Time.h"
#include <iostream>

using namespace std;


Time::Time(int h,int m, int s): hour(h),min(m),sec(s)
{}

Time::Time(): hour(0),min(0),sec(0){}

Time::~Time() {

}
/*

*/

int Time::getHour() { return hour; }
int Time::getMin() { return min; }
int Time::getSec() { return sec; }

void Time::setHour(int h) { hour = h; }
void Time::setMin(int m) { min = m; }
void Time::setSec(int s) { sec = s; }


Time& operator-(Time& Tmp, int x) //friend уменьшение на число 
{
	int value = 0;
	value = Tmp.getHour() * 3600 + Tmp.getMin() * 60 + Tmp.getSec();
	bool flag1 = false;

	value -= x;

	Tmp.setHour(value / 3600);
	Tmp.setMin((value % 3600) / 60);
	Tmp.setSec((value % 3600) % 60);
	

	int hh = value / 3600;
	int mm = (value % 3600) / 60;
	int ss = value % 3600 % 60;

	/*while (!flag1) {
		if (Tmp.getHour() > 23)
		{
			Tmp.setHour(hh -= 24);

		}
		else if (Tmp.getMin() > 59) {

			Tmp.setHour(hh++);
			Tmp.setMin(mm -= 59);

		}
		else if (Tmp.getSec() > 59)
		{

			Tmp.setMin(mm++);
			Tmp.setSec(ss -= 59);
		}
		
		else
			flag1 = true;
	}
	*/
	
	
	while (!flag1) {
		if (ss < 0) {

			ss = 60 - abs(ss);
			mm--;
			Tmp.setSec(ss);
			Tmp.setMin(mm);

		}
		else if (mm < 0) {
			mm = 60-abs(mm);
			hh--;
			Tmp.setMin(mm);
			Tmp.setHour(hh);
		}
		else if (hh < 0) {
			hh = 24 - abs(hh);
			Tmp.setHour(hh);
		}
		else
		flag1 = true;
	}
	

	return Tmp;

}

Time& Time::operator+(int diff) //метод увеличение на число  
{
	int value = 0;
	value = hour * 3600 + min * 60 + sec;
	bool flag = false;
	value += diff;

	hour = value / 3600;
	min = value / 60 %60;
	sec = value % 60;
	while (!flag) {
		if (hour > 23)
		{
			hour = hour - 24;

		}
		else if (min > 59) {

			hour++;
			min = min - 59;

		}
		else if (sec > 59)
		{

			min++;
			sec -= 59;
		}

		else
			flag = true;
	}
 	return *this;
	
}

void Time::printTime()
{
	cout <<"Time    "<<hour << ":" << min << ":" << sec << endl;
}

bool Time::operator>(const Time& T2)
{
	int sec1 = hour * 3600 + min * 60 + sec;
	int sec2 = T2.hour * 3600 + T2.min * 60 + T2.sec;

	if (sec1 > sec2)
		return true;
	else
		return false;
	
	}

bool operator<(const Time& T1, const Time& T2)
{
	int sec1 = T1.hour * 3600 + T1.min * 60 + T1.sec;

	int sec2 = T2.hour * 3600 + T2.min * 60 + T2.sec;

	if (sec1 < sec2)
		return true;
	else
		return false;

}

bool Time::operator==(const Time& T2)
{
	int sec1 = hour * 3600 + min * 60 + sec;
	int sec2 = T2.hour * 3600 + T2.min * 60 + T2.sec;

	if (sec1 == sec2)
		return true;
	else
		return false;
}