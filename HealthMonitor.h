#pragma once
#include<iostream>
#include"Doctor.h"
#include"BIO.h"
using namespace std;
int hash2(string word)
{
	unsigned h = 400157;
	int index = 0;
	while (word[index] && index < word.size()) {
		h = (h * 7919) ^ (word[0] * 71);
		index++;
	}
	if (h > 125) h %= 125;
	if (h < 33) h += 33;
	return h;
}
string Encode(string A)
{
	string ret = A;
	int size = A.size();
	for (int i = 0; i < size; i++)
	{
		ret[i] = A[size - i - 1];
		if (i != 0)
			ret[i] = hash2(ret) + ret[i - 1];
		else
			ret[i] = hash2(ret);

		cout << ret << endl;
	}
	return ret;
}

class HealthMonitor
{
protected:
	vector<Doctor> Ds;
	vector<Patient> Ps;
	int CurrentPatientID;
	int CurrentDoctorID;
	int CurrentAppID;
public:
	HealthMonitor() 
	{
		CurrentPatientID = 200000;
		CurrentDoctorID = 100000;
		CurrentAppID = 100;
	}
	void AddDoctor(string Password,string Name,int Age,int BirthDay,int BirthMonth,int BirthYear,char gender,string contact,string profession)
	{
		Ds.push_back(Doctor(CurrentDoctorID, Encode(Password), BIO(Name, Age, date(BirthDay, BirthMonth, BirthYear), gender, contact, profession)));
		CurrentDoctorID++;
	}
	void AddPatient(string Password, string Name, int DoctorID,string EmergencyContact, int Age, int BirthDay, int BirthMonth, int BirthYear, char gender, string contact, string profession)
	{
		Ps.push_back(Patient(CurrentPatientID, Encode(Password), EmergencyContact,DoctorID,BIO(Name, Age, date(BirthDay, BirthMonth, BirthYear), gender, contact, profession)));
		CurrentPatientID++;
	}
	bool SetAppointment(int PatientID, int DoctorID, date Date, int time)
	{
		int di=-1, pi=-1;
		for (int i = 0; i < Ds.size(); i++)
		{
			if (Ds[i].getID() == DoctorID)
			{
				di = i;
				break;
			}
		}
		for (int i = 0; i < Ps.size(); i++)
		{
			if (Ps[i].getID() == PatientID)
			{
				di = i;
				break;
			}
		}
		if (di == -1 || pi == -1) return false;
		Ps[pi].SetAppointment(CurrentAppID, Ds[di].getID(), Date, time);
		Ds[di].AddAppointment(CurrentAppID, Ps[pi].getID(), Date, time);
		CurrentAppID++;
	}
	bool CheckDoctorPassword(string Password, int DoctorID)
	{
		string Encoded = Encode(Password);
		for (int i = 0; i < Ds.size(); i++)
		{
			if (Ds[i].getID() == DoctorID)
			{
				return Ds[i].CheckPassword(Encoded);
			}
		}
	}	 
	bool CheckPatientPassword(string Password, int PatientID)
	{
		string Encoded = Encode(Password);
		for (int i = 0; i < Ps.size(); i++)
		{
			if (Ps[i].getID() ==PatientID)
			{
				return Ps[i].CheckPassword(Encoded);
			}
		}
	}

};

