#include <iostream>
#include <string>
using namespace std;

class BankAccount {
	private:
    	double balance; 

	protected:
    	BankAccount(double initialBalance) : balance(initialBalance) {}

	public:
		virtual void withdraw() = 0;
    	virtual void accountBalance() = 0;
		
		double getBalance() const {
        	return balance;
    	}

		void setBalance(double newBalance) {
        	if (newBalance >= 0) {
            	balance = newBalance;
        	}
    	}
    	
    	void depositAccount() {
        	double deposit;
        	char choice;
        	do {
            	cout << "Enter Deposit Amount: $";
            	cin >> deposit;
            	if (deposit <= 0) {
            	    cout << "Invalid amount!" <<endl;
            	    cin.clear();
					cin.ignore(1000, '\n');
            	    cout << "Do you wish to continue? (Y/N): ";
					cin >> choice;
					if (choice == 'N' || choice == 'n') {
                		return; 
            		}
            	} 
				else {
            	    setBalance(getBalance() + deposit);
            	    cout << "Deposit successful!" <<endl;
					cout << "New Balance: $" << getBalance() <<endl;
            	}
        	} while (deposit <= 0);
    	}
    	
    	void charValidation(){
    		cin.clear();
			cin.ignore(1000, '\n');
		}
};

class SavingsAccount : public BankAccount {
	public:
    	SavingsAccount() : BankAccount(1000) {}
    	
    	void withdraw() override {
    		if (getBalance() == 1000) {
        		cout << "You are unable to make withdrawal due to insufficient balance!" << endl;
        		return;
        	}
        	double withdraw;
        	char choice;
        	do {
        	    cout << "Enter Withdrawal Amount: $";
        	    cin >> withdraw;
        	    if (withdraw > getBalance() || getBalance() - withdraw <= 999) {
        	        cout << "Insufficient balance!" <<endl;
					cout << "Current Balance: $" << getBalance() <<endl;
					cout << "Do you wish to continue? (Y/N): ";
					cin >> choice;
					if (choice == 'N' || choice == 'n') {
                		return; 
            		}
            	} 
				else if (withdraw <= 0) {
            		cout << "Invalid amount!" <<endl;
            		charValidation();
            		cout << "Do you wish to continue? (Y/N): ";
					cin >> choice;
					if (choice == 'N' || choice == 'n') {
            			return; 
            		}
            	} 
				else {
            	    setBalance(getBalance() - withdraw);
        			cout << "Withdrawal successful!" <<endl;
					cout << "New Balance: $" << getBalance() << endl;
            	}
            	if (getBalance() == 1000) {
        			cout << "You cannot withdraw anymore due to insufficient balance!" << endl;
        			return;
        		}
        	} while (withdraw <= 0 || withdraw > getBalance() || getBalance() - withdraw <= 999);
    	}
    	
    	void accountBalance() override {
    	    cout << "\nSavings Account Balance: $" << getBalance() <<endl;
    	}
};

class CurrentAccount : public BankAccount {
	public:
    	CurrentAccount() : BankAccount(0) {}
	
    	void withdraw() override {
    		if (getBalance() == 0) {
        		cout << "You are unable to make withdrawal due to 0 balance!" << endl;
        		return;
        	}
        	double withdraw;
        	char choice;
        	do {
        	    cout << "Enter Withdrawal Amount: $";
        	    cin >> withdraw;
        	    if (withdraw > getBalance()) {
        	        cout << "Insufficient balance!" <<endl;
					cout << "Current Balance: $" << getBalance() <<endl;
					cout << "Do you wish to continue? (Y/N): ";
					cin >> choice;
					if (choice == 'N' || choice == 'n') {
                		return; 
            		}
        	    } 
				else if (withdraw <= 0) {
        	    	cout << "Invalid amount!" <<endl;
            		charValidation();
            		cout << "Do you wish to continue? (Y/N): ";
					cin >> choice;
					if (choice == 'N' || choice == 'n') {
            			return; 
            		}
        	    } 
				else {
        	        setBalance(getBalance() - withdraw);
        			cout << "Withdrawal successful!" <<endl;
					cout << "New Balance: $" << getBalance() << endl;
        	    }
        	    if (getBalance() == 0) {
            		cout << "You cannot withdraw anymore due to 0 balance!" << endl;
            		return;
            	}
        	} while (withdraw <= 0 || withdraw > getBalance());
    	}	

    	void accountBalance() override {
    	    cout << "\nCurrent Account Balance: $" << getBalance() << endl;
    	}
};

void charValidation(){
    	cin.clear();
		cin.ignore(1000, '\n');
	}

void subMenu(BankAccount &account){
	int choice;
	do{
		cout << "\n-------------------------";
		cout << "\n1 - Deposit" << endl;
    	cout << "2 - Withdraw" << endl;
		cout << "3 - Check Balance" << endl;
    	cout << "4 - Back" << endl;
    	cout << "-------------------------" <<endl;
    	cin >> choice;
    	charValidation();
        switch (choice) {
            case 1:
            	account.accountBalance();
                account.depositAccount();
                break;
            case 2:
            	account.accountBalance();
                account.withdraw();
                break;
            case 3:
                account.accountBalance();
                break;
            case 4:
                break;
            default:
                cout << "Invalid Input!" << endl;
                break;
        }
    } while (choice != 4);
}

int main() {
    int choice;
    SavingsAccount savings;  
    CurrentAccount current;
    
    do {
    	cout << "-------------------------";
        cout << "\nMain Menu" <<endl;
        cout << "-------------------------";
        cout << "\n1 - Savings Account" <<endl;
        cout << "2 - Current Account" <<endl;
        cout << "3 - Exit" << endl;
        cout << "-------------------------" <<endl;
        cin >> choice;
        charValidation();

        switch (choice) {
            case 1:
            	cout << "-------------------------";
                cout << "\nMenu for Savings Account";
                subMenu(savings);
                break;
            case 2:
            	cout << "\n-------------------------";
                cout << "\nMenu for Current Account";
                subMenu(current);
                break;
            case 3:
                break;
            default:
                cout << "Invalid Input!" << endl;
                break;
        }
    } while (choice != 3);
    return 0;
}