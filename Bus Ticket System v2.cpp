#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Account {
  string username;
  string password;
};

struct Schedule{
	char place[100];
	char time[100];
};

bool validatePassword(const string& password) {
  const regex pattern("^(?=.*[A-Za-z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
  return regex_match(password, pattern);
}

void createAccount() {
  Account newAccount;
  string password;

  // Get user input for username
  cout << "Enter Username: ";
  getline(cin, newAccount.username);

  do {
    // Get user input for password with validation
    cout << "Enter Password (minimum 8 characters with at least 1 number and 1 special symbol): ";
    getline(cin, password);
  } while (!validatePassword(password));

  newAccount.password = password;

  // Open file for writing account in append mode
  ofstream outfile("accounts.txt", ios::app);

  if (outfile.is_open()) {
    outfile << newAccount.username << endl;
    outfile << newAccount.password << endl;
    outfile.close();
    cout << "Account created successfully!" << endl;
  } else {
    cerr << "Error opening file for account storage!" << endl;
  }
}

void Tickets(){
	int ticket, pw;
	
	reset:
	cout << "Enter your Password: ";
	cin >> pw;
	if (pw == Account.password){
		cout << "How many tickets will you order?: ";
		cin >> ticket;
		
		cout << "Thank you for ordering!"<<endl;
	}
	else {
		cout << "Invalid Password. Try Again!" << endl;
		goto reset;
		system ("pause");
	}
}

void Book(){
	Schedule location[100] ={	
		{"San Mateo", "5:00"},
		{"Sta. Lucia", "5:30"},
		{"Santolan", "5:35"},
		{"Cubao", "4:00"},
		{"Philcoa", "4:30"},
	};
	
	for(int i = 0; i < 6; i++){
		cout << location[i].place << endl;
	}
}
int main(){
	int choice;
	
	do{
		cout << "=== MKD Bus Ticket System ===" << endl;
		cout << "1. Create Account" << endl;
		cout << "2. Order Ticket" << endl;
		cout << "3. Book Schedule" << endl;
		cout << "4. View Schedule" << endl;
		cout << "5. Display Account" << endl;
		cout << "6. EXit" << endl;
		
		cin >> choice;
		cin.ignore();
		
		switch (choice){
		case 1:
			cout << "Account Creation screen" << endl;
			createAccount ();
			break;
		case 2:
			cout << "Order Tickets" << endl;
			Tickets ();
			break;
		case 3:
			cout << "Booking" << endl;
			Book ();
			break;
		case 4:
			cout << "Schedule Viewer" << endl;
			break;
		case 5:
			cout << "Account Information" << endl;
			break;
		case 6:
			cout << "Exit" << endl;
			break;

		}
	}while (choice != 6);
}