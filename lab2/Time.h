#pragma once

class Time
{
private: 
	int hour;
	int min;
	int sec;

public:

	 Time(); 
     explicit Time(int h, int m, int s);
	~Time();
	

	int getHour();
	int getMin();
	int getSec();
	
	void setHour(int h);
	void setMin(int m);
	void setSec(int s);


	void printTime();
	
	friend Time& operator-(Time& Tmp, int b);//вычитание времени пользователем
	Time& operator+ (int a);//увеличение времени пользователем

	bool operator>(const Time& T2);
	friend bool operator<(const Time& T1, const Time& T2);
	bool operator==(const Time& Tmp);
	



};

