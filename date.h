#pragma once
class date
{
public:
	int day;
	int month;
	int year;
date()
{
	day = 1;
	month = 1;
	year = 2000;
}
date(int Day, int Month, int Year)
{
	SetDate(Day, Month, Year);
}
void SetDate(int Day, int Month, int Year)
{
	if (Day > 0 && Day < 32) day = Day;
	if (Month > 0 && Month < 32) month = Month;
	if (Year > 0 && Year < 32) year = Year;
}
};

