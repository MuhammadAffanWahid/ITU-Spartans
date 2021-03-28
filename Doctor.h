#include<iostream>
#include"Patient.h"
#include"BIO.h"
#include"date.h"
#include<vector>
#include"Appointment.h"
using namespace std;
#pragma once
class Patient;
class Doctor
{
protected:
	int id;
	string encrypted_password;
	BIO bio;
	vector<Patient*> Ps;
	vector<Appointment> Requested_Appointments;
	vector<Appointment> Pending_Appointments;
public:
	Doctor() {}
	int getID()
	{
		return id;
	}
	bool CheckPassword(string Pass)
	{
		return Pass == encrypted_password;
	}
    Doctor(int ID,string Encrypted_Password, BIO Bio)
	{
		id = ID;
		encrypted_password = Encrypted_Password;
		bio = Bio;
	}
	void AddPatient(Patient* P)
	{
		Ps.push_back(P);
	}
	bool RemovePatient(int Patient_id)
	{
		int size = Ps.size();
		for (int i = 0; size; i++)
		{
			if (Ps[i]->getID() == Patient_id)
			{
				swap(Ps[i], Ps[size - 1]);
				Ps.pop_back();
				return true;
			}
		}
		return false;
	}
	void AddAppointment(int ID, int PatientID, date app_date, int app_hour)
	{
		Pending_Appointments.push_back(Appointment(ID, id, PatientID, app_date, app_hour));
	}
	bool ApproveAppointment(int ID)
	{
		int size = Requested_Appointments.size();
		for (int i = 0; i < size; i++)
		{
			if (Requested_Appointments[i].id == ID)
			{
				Pending_Appointments.push_back(Requested_Appointments[i]);
				swap(Requested_Appointments[i], Requested_Appointments[size - 1]);
				Requested_Appointments.pop_back();
				return true;
			}
		}
		return false;
	}
	bool DeclineAppointment(int ID)
	{
		int size = Requested_Appointments.size();
		for (int i = 0; i < size; i++)
		{
			if (Requested_Appointments[i].id == ID)
			{
				swap(Requested_Appointments[i], Requested_Appointments[size - 1]);
				Requested_Appointments.pop_back();
				return true;
			}
		}
		return false;
	}
};

