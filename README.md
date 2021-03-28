# ITU-Spartans

Code contains following classes:
BIO
Patient 
Doctor
Appointment
HealthMonitor(Main class)

BIO contains Name, age, gender, date of birth etc. 
	Each patient has his doctor ID.Both of them have BIO stored in their class. Patient can request an appointment from doctor. Patient also stores his current health attributes ie. Blood pressure, heart beat rate etc which he can update whenever he wants.
	Each doctor has a list of patients. Doctor has two lists of appointments. One that has requested and other that has approved appointments. Doctor can approve or decline appointments. Doctor can also see the patient health attributes. 
	HealthMonitor is the main class. It contains doctors, patients and appointments. It can create new accounts of doctors as well as patients and assign them new id each account. It also assigns id to appointment.
HealthMonitor contains an attribute of blockchain. Instead of storing original passwords of doctors and patients, it pass the password through a encoding process which encode the password that can not be decoded again. It stores the encoded passwords in doctor and patient classes. Whenever anyone has to access their account, they provide the password which is encoded and compared with stored encoded password. If they match, they are granted access else they are asked for correct password.
	
