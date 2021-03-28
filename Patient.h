#pragma once
#include<iostream>
#include"BIO.h"
#include"date.h"
#include<vector>
#include"Appointment.h"
using namespace std;
class Patient
{
protected:
	int id;
	string encrypted_password;
	string emergency_contact;
	BIO bio;
	int DID;
	float blood_pressure;
	float heart_rate;
	float sugar_rate;
	date last_checkup;
	vector<Appointment> Appointments;
public:
	Patient() 
	{
		Appointments.clear();
	}
	Patient(int ID, string Encrypted_Password,string Emergency_Contact,int DoctorID,BIO Bio)
	{
		id = ID;
		encrypted_password = Encrypted_Password;
		emergency_contact = Emergency_Contact;
		bio = Bio;
		DID = DoctorID;
	}
	Patient(int ID, string Encrypted_Password, string Emergency_Contact, int DoctorID,BIO Bio, date Last_Checkup,float Blood_Pressure,float Heart_Rate,float Sugar_Rate)
	{
		id = ID;
		encrypted_password = Encrypted_Password;
		emergency_contact = Emergency_Contact;
		bio = Bio;
		last_checkup = Last_Checkup;
		heart_rate = Heart_Rate;
		blood_pressure = Blood_Pressure;
		sugar_rate = Sugar_Rate;
		DID = DoctorID;
	}
	int getID()
	{
		return id;
	}
	bool CheckPassword(string Pass)
	{
		return Pass == encrypted_password;
	}
	void UpdateHeartRate(float Heart_Rate) { heart_rate = Heart_Rate; }
	void UpdateBloodPressure(float Blood_Pressure) { blood_pressure = Blood_Pressure; }
	void UpdateSugarRate(float Sugar_Rate) { sugar_rate = Sugar_Rate; }
	void SetAppointment(int App_ID,int DoctorID, date Appointment_Date, int time)
	{
		Appointments.push_back(Appointment(App_ID,DoctorID, id, Appointment_Date, time));
	}
};

