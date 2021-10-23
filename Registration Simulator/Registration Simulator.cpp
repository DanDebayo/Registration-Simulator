// Registration Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
int Mainchoice = 0;

void AccountCreate() {
	string Username;
    string Password;
	string backupPassword;


	cout << "Please input your desired username:\n\n";
	
	cin >> Username;
	cout << "\n\n";

	cout << "Please input your desired password\n\n";

	cin >> Password;
	cout << "\n\n";

	cout << "In any case you forgot your password, What is your date of birth(dd/mm/yyy)?\n\n";
	cin >> backupPassword;
	cout << "\n\n";

	ofstream file;
	file.open(Username + ".txt");

	file << Username << endl << Password << endl << backupPassword;
	file.close();
}

void forgotpassword(){
	string Username, Fname;
	string Password;
	string birthday, bday;

	cout << "Please Input you Username:\n";
		cin >> Username;
		cout << "\n";

		cout << "Please input your date of birth(dd/mm/yyyy):\n";
		cin >> birthday;
		cout << "\n";

		ifstream read(Username + ".txt");
		getline(read, Fname);
		getline(read, Password);
		getline(read, bday);

		if (Fname == Username && bday == birthday) {
            cout << "Your password is:" << Password << endl;
			cout << "Please Don't forget :)\n\n";
			
			return;
		}
		else {
			cout << " The date of birth or username is wrong please try again\n\n";
			forgotpassword();
		}
}
int MainMenu() {
	int choice;

  cout << "\tWELCOME TO THE REGISTRATION SIMULATOR\n\n";

   cout << "\tCHOOSE BETWEEN THE OPTIONS:\n\n";

   cout << "\t1. Login\n \t2. Create an account\n \t3. Exit\n";

   cin >> choice;

   return choice;
}

void Login() {

	char ForgotPword;

	string Username, Fname;
		string Password,Fpass;

		cout << "Please input your username:\n\n";

		cin >> Username;
		cout << "\n\n";

		cout << "Please input your password\n\n";

		cin >> Password;
		cout << "\n\n";

		ifstream read(Username + ".txt");
		getline(read, Fname);
		getline(read, Fpass);

		if (Fname == Username && Fpass == Password) {
			cout << "Your username was successfully found\n";
		}
		else {
			cout << "Wrong Username or Password.\n\n ";

			cout << "Did you forget your password? (y/n)\n";
			cin >> ForgotPword;

			if (ForgotPword == 'n') {
              Login();
			}
			else if (ForgotPword == 'y') {
				forgotpassword();
			}

		}
				
}



int main()
{
	
   while (Mainchoice != 3) {
	   Mainchoice = MainMenu();
	   if (Mainchoice == 1) {
		   Login();
	   }
	   else if (Mainchoice == 2) {
            AccountCreate();
		   cout << "Thank you for making an account with us\n\n";
	   }
	   else {
		   cout << "Goodbye\n";
	   }
   }



   
}
