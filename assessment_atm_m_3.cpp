#include <iostream>
#include <ctime>

using namespace std;

const int ATM_PIN = 12345;
double accountBalance = 20000; 

double initialBalance = 60000; 
	string name = "bhavin";
    string address = "gujarat";
    string branch = "ahmedabad";

void displayWelcomeScreen() 
{
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "\n\n\t WELCOME TO ATM";
    cout << "\n\n\t ---------------------------";
    cout << "\n\n\t Current date: " << dt;
    cout << "\n\n\t ---------------------------";
    cout << "\n\n\t Press 1 and Enter to Access Your Account";
    cout << "\n\n\t Press 0 and Enter to get Help";
}

void displayHelpScreen() 
{
    cout << "\n\n\t ATM ACCOUNT STATUS";
    cout << "\n\n\t You must have the correct PIN to access this account.";
    cout << "\n\n\t See your bank representative for assistance.";
    cout << "\n\n\t Thanks for your choice today!!";
}

void displayMenu() {
    cout << "\n\n\t ATM Main Menu Screen";
    cout << "\n\n\t [1] Deposit Cash";
    cout << "\n\n\t [2] Withdraw Cash";
    cout << "\n\n\t [3] Balance Inquiry";
    cout << "\n\n\t [0] Exit ATM";
    cout << "\n\n\t Please enter a selection: ";
}

void depositAmount() {
    double amount;
    cout << "\n\n\t ATM ACCOUNT DEPOSIT SYSTEM";
    cout <<"\n\n\t the name of the account holder are="<<name;
    cout<<"\n\n\t the account holder address is="<<address;
    cout<<"\n\n\t the branch location is= "<<branch;
    cout << "\n\n\t Present available balance: Rs. " << accountBalance;
    cout << "\n\n\t Enter the Amount to be Deposited: Rs. ";
    cin >> amount;
    accountBalance += amount;
    cout << "\n\n\t Your new available balance is Rs. " << accountBalance;
}

void withdrawAmount() 
{
    double amount;
    cout << "\n\n\t ATM ACCOUNT WITHDRAWAL";
    cout << "\n\n\t Enter the amount to withdraw: Rs. ";
    cin >> amount;
    if (amount > accountBalance) 
	{
        cout << "\n\n\t Insufficient Available Balance in your account.";
    } else 
	{
        accountBalance -= amount;
        cout << "\n\n\t Withdrawal successful! Your new balance is Rs. " << accountBalance;
    }
}

void checkBalance() 
{
    cout << "\n\n\t Your current account balance is: Rs. " << accountBalance;
}

int main() 
{
    int choice;
    displayWelcomeScreen();
    cin >> choice;
    
    if (choice == 0) 
	{
        displayHelpScreen();
        return 0;
    }
    
    if (choice == 1) 
	{
        int enteredPin;
        cout << "\n\n\t Enter Your ATM Pin: ";
        cin >> enteredPin;
        
        if (enteredPin != ATM_PIN) 
		{
            cout << "\n\n\t THANK YOU";
            cout << "\n\n\t You had made your attempt which failed!!! No More attempts allowed!! Sorry!!";
            return 0;
        }
        
        while (true) 
		{
            displayMenu();
            cin >> choice;
            
            switch (choice) 
			{
                case 1:
                    depositAmount();
                    break;
                case 2:
                    withdrawAmount();
                    break;
                case 3:
                    checkBalance();
                    break;
                case 0:
                    cout << "\n\n\t Thank you for using ATM. Goodbye!";
                    return 0;
                default:
                    cout << "\n\n\t Invalid choice! Please try again.";
            }
        }
    }
    
    cout << "\n\n\t Invalid choice! Exiting...";
    return 0;
}
