#pragma once
#include<iostream>
#include"date.h"
using namespace std;
class Appointment
{
public:
	int id;
	int Did;
	int Pid;
	date App_Date;
	int App_Hour;  //8:55=0855 14:13=1413 3:02=0302
	Appointment(int ID,int DoctorID, int PatientID, date app_date, int app_hour)
	{
		id = ID;
		App_Date = app_date;
		App_Hour = app_hour;
		Pid = PatientID;
		Did = DoctorID;
	}
	Appointment()
	{
		id = -1;
		App_Hour = -1;
		Pid = -1;
		Did = -1;
	}
	void SetAppointment(int ID,int DoctorID, int PatientID, date app_date, int app_hour)
	{
		id = ID;
		App_Date = app_date;
		App_Hour = app_hour;
		Pid = PatientID;
		Did = DoctorID;
	}
};

