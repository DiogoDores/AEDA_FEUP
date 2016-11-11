#include "Corporation.h"

Utilities u1;

Corporation * Corporation::instance()
{

	if (!singleton_instance) {
		singleton_instance = new Corporation;
	}

	return singleton_instance;
}


//Checks existance of the users file
bool Corporation::foundUsersFile(string usersFile) {

	fstream f;

	f.open(usersFile);

	if (f.fail()) {
		f.close();
		u1.setColor(12); cerr << "\n  ERROR: " << usersFile << " (users file) could not be found!\n         Verify the directory!\n\n"; u1.setColor(15);
		return false;
	}

	f.close();

	this->usersFile = usersFile;
	return true;
}

//Loads the users file to memory (Users vector)
void Corporation::loadUsers() {

	string line;
	fstream f;

	f.open(usersFile);
	getline(f, line);

	while (getline(f, line)) {

		string username = line.substr(0, line.find(" ; "));
		line.erase(0, line.find(" ; ") + 3);
		string password = line.substr(0, line.find(" ; "));
		line.erase(0, line.find(" ; ") + 3);
		unsigned int nif = stoi(line.substr(0, line.find(" ; ")));
		line.erase(0, line.find(" ; ") + 3);
		unsigned int points = stoi(line.substr(0, line.length()));

		usersVec.push_back(Users(username, password, nif, points));
	}
	f.close();
	return;
}

//Loads memory to the users file
void Corporation::saveUsers() {

	ofstream f;

	f.open(usersFile, ofstream::app);

	for (size_t i = 0; i < usersVec.size(); i++) {
		f << usersVec[i].getUsername() << " ; " << usersVec[i].getPassword() << " ; " << usersVec[i].getNif() << " ; " << usersVec[i].getPoints() << endl;
	}

	f.close();

	return;
}

//Adds a user to the users vector
void Corporation::registerUser() {

	cout << "\n Name:  "; getline(cin, username);

	if (cin.eof()) {
		u1.cancelMessage();
		return;
	}

	for (unsigned int index = 0; index != username.size(); index++) {
		if (!isalpha(username[index]) && username[index] != ' ') {
			u1.setColor(12); cerr << "  ERROR: Name must only contain alphabetic characters. "; u1.setColor(15);
			Sleep(3000);
			u1.clearScreen();
			return;
		}
	}

	cout << "\n Password:  "; cin >> password;
	u1.cinClear();
	cout << "\n NIF:  "; cin >> nif;
	u1.cinClear();

	if (cin.eof()) {
		u1.cancelMessage();
		return;
	}

	usersVec.push_back(Users(username, password, nif, 0));

	for (size_t i = 0; i < usersVec.size(); i++) {
		cout << usersVec[i].getUsername() << " ; " << usersVec[i].getPassword() << " ; " << usersVec[i].getNif() << " ; " << usersVec[i].getPoints() << endl;
	}

	u1.clearScreen();
	return;
}



void Corporation::registerSuppliers()
{
	Utilities u;
	bool isIn = true;

	string n, ad;
	unsigned int nif;
	while (isIn)
	{
		cout << "What is your name?\nName: ";
		cin >> n;
		cout << "\nWhat is your FIN? (Fiscal Identification Number)\nFIN : ";
		cin >> nif;
		if (u.invalidInputRetry())
			continue;
		if (!u.invalidInputRetry())
		{
			isIn = false;

		}
		else
		{
			cout << "\nThe program will now return.\n";
			isIn = false;
			return;
		}
		isIn = false;
	}

	isIn = true;

	cout << "\nWhat is your address?\n";
	cin >> ad;
	int n;
	while (isIn)
	{

		cout << "\nHow many rents do you want to make available?\n";
		cin >> n;
		if (u.invalidInputRetry())
			continue;
		if (!u.invalidInputRetry())
		{
			n = stoi(n);
			isIn = false;
		}
		else
		{
			cout << "\nThe program will now return.\n";
			isIn = false;
			return;
		}
	}
	vector<Rent> v;
	int choice;
	for (int i = 0; i < n; i++)
	{
		cout << "What is the type of rent? \n1 - Hotel\n2 - Bed'n'Breakfast\n3 - Apartment\n4 - Flat\n5 - Apartment\n6 - Shared House";

	}

	/*
	string name, address;
	unsigned int nif;
	vector<Rent<T>> v;*/





}
== == == =
//Loads the users file to memory (Users vector)
/*template<typename T>
void Corporation::loadReservations()
{
	string name,name_rent type, type_type, d1, d2;
	unsigned int n_people;
	fstream f;
	Rent<T> *c;

	f.open("reservations.txt");

	while (!f.eof()) {
	getline(f, line)

		string  name= line.substr(0, line.find(" ; "));
		line.erase(0, line.find(" ; ") + 3);
		string  name_rent = line.substr(0, line.find(" ; "));
		line.erase(0, line.find(" ; ") + 3);
		string type = line.substr(0, line.find(" ; "));
		line.erase(0, line.find(" ; ") + 3);
		string type_type = line.substr(0, line.find(" ; "));
		line.erase(0, line.find(" ; ") + 3);
		unsigned int n_people = stoi(line.substr(0, line.find(" ; ")));
		line.erase(0, line.find(" ; ") + 3);
		string d1 = line.substr(0, line.find(" ; "));
		line.erase(0, line.find(" ; ") + 3);
		string d2 = line.substr(0, line.length());

		for (int i = 0; i < rentsVec.size(); i++)
		{
			if (name_rent == rentsVec.at(i).getName())
				c = rentsVec.at(i).getName();
		}


		reservationVec.push_back(Reservation(name, type, type_type, n_people,Date(d1),Date(d2),c));
	}
	f.close();
}*/

/*void Corporation::makeReservation()
{
	string city;
	cout << "City : ";
	getline(cin, city);

	cout << "List of possibilities : " << endl;
	for (int i = 0; i < rentsVec; i++)
	{
		if(city == rentsVec.at(i).getCity())
		cout << " -> " << rentsVec.at(i) << endl;
	}

	string d1, d2,name_rent;
	Rent<T> c;

	cout << " Name of the Rent Place : ";
	getline(cin, name_rent);

	for (int i = 0; i < rentsVec.size(); i++)
	{
		int n_people;

		cout << "Number of persons : ";
		cin >> n_people;

		if (n_people > rentsVec.at(i).getNumOcupantes())
		{
			cout << "Invalid number of persons." << endl;
			break;
		}

		if (name_rent == rentsVec.at(i).getName())
		{
			cout << " Date of check-in : ";
			getline(cin, d1);
			cout << "Date of check-out : ";
			getline(cin, d2);

			Date d1 = Date(d1);
			Date d2 = Date(d2);

			if (d1 >= rentsVec.at(i).getDataInicio() && d2 <= rentsVec.at(i).getDataFim())
			{
				string answer;
				cout << rentsVEc.at(i) << endl << "Do you want to confirm? ";
				if (answer == "yes" || answer == "Yes")
				{
					reservationsVec.push_back(Reservation())
						break;
				}
				else
					continue;
			}
			else
				cout << "invalid period of time" << endl;
		}
	}



}*/
>> >> >> > origin / master
