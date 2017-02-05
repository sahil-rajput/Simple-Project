/*		SAHIL RAJPUT		*/
#include <iostream>
using namespace std;

class Bank
{
	private : 
				string name,address,email;
				long int mobileno,balance;
	public :
				int accno[100];
				void openAccount();
				void showAllInfo();
				void showParticularInfo();
				void withdraw();
				void deposit();
				void showBalanceInfo();
};
void Bank :: openAccount()
{

	cout<<"\nEnter the Name of Client : ";
	cin>>name;
	cout<<"Enter the Address of Client : ";
	cin.ignore();
	getline(cin,address);
	cout<<"Enter the Mobile Number of Client : ";
	cin>>mobileno;
	cout<<"Enter the Email of Client : ";
	cin>>email;
}
void Bank :: showAllInfo()
{
	cout<<"Name of Client : "<<name;
	cout<<"\nAddress of Client : "<<address;
	cout<<"\nMobile Number of Client : "<<mobileno;
	cout<<"\nEmail of Client : "<<email;
	cout<<"\nAccount Balance of Client : "<<balance;

}
void Bank :: showParticularInfo()
{
	cout<<"Name of Client : "<<name;
	cout<<"\nAddress of Client : "<<address;
	cout<<"\nMobile Number of Client : "<<mobileno;
	cout<<"\nEmail of Client : "<<email;
	cout<<"\nAccount Balance of Client : "<<balance;	
}
void Bank :: withdraw()
{
	    long amtdrawn;
    	cout<<"Enter amount to be withdrawn: ";
    	cin>>amtdrawn;
    	if(balance<amtdrawn)
    		cout<<"\nInsufficient balance! Operation Cannot be performed!"<<endl<<endl;
    	else
    		balance=balance-amtdrawn;
}
void Bank :: deposit()
{
		long int dep;
    	cout<<"Enter amount to be deposited: ";
    	cin>>dep;
    	balance+=dep;
}
void Bank :: showBalanceInfo()
{
	cout<<"Current Balance is : "<<balance;
}
int main(void)
{
	Bank client[100];
	int n,choice=0;
	do{
		cout<<"\nWhat You Want To Do ?"<<endl;
		cout<<"1. Open New Account\n2. Show All Account Information\n3. Show Particular Account Information\n4. Deposit\n5. Withdraw\n6. Show Balance Informaion\n7. Exit\n";
		cin>>choice;
		if(choice == 1)
		{
			cout<<"How Many Account You Want To Open?"<<endl;
			cin>>n;
			int j=0;
			for(int i=0;i<n;i++)
			{
				client[i].accno[j]=i+1;
				client[i].openAccount();
				cout<<"Your Account Number is : "<<client[i].accno[j];
				j++;
			}
		}
		else if(choice == 2)
		{		
			cout<<"#####\tAll Account Information\t#####\n";
			for(int i=0;i<n;i++)
			{
				cout<<"\n\n-----\tAccount No: "<<i+1<<"\t-----\n\n";
				client[i].showAllInfo();
				cout<<"\nAccount Number of Client : "<<client[i].accno[i];
			}
		}
		else if(choice == 3)
		{
			int k;
			cout<<"Enter Your Account Number";
			cin>>k;
			int i=0,f=0;
			while(i<n)
			{
				if(k == client[i].accno[i])
				{
					client[i].showParticularInfo();
					break;
				}
				else
					f=1;
			}
			if(f==1)
				cout<<"Invalid Account\n";		
		}
		else if(choice == 4)
		{
			int k;
			cout<<"Enter Your Account Number";
			cin>>k;
			int i=0,f=0;
			while(i<n)
			{
				if(k == client[i].accno[i])
				{
					client[i].deposit();
					break;
				}
				else
					f=1;
			}
			if(f==1)
				cout<<"Invalid Account\n";	
		}
		else if(choice == 5)
		{
			int k;
			cout<<"Enter Your Account Number";
			cin>>k;
			int i=0,f=0;
			while(i<n)
			{
				if(k == client[i].accno[i])
				{
					client[i].withdraw();
					break;
				}
				else
				{
					f=1;
				}
			}
			if(f==1)
				cout<<"Invalid Account\n";
		}
		else if(choice == 6)
		{
			int k;
			cout<<"Enter Your Account Number";
			cin>>k;
			int i=0,f=0;
			while(i<n)
			{
				if(k == client[i].accno[i])
				{
					client[i].showBalanceInfo();
					break;
				}
				else
				{
					f=1;
				}
			}
			if(f==1)
				cout<<"Invalid Account\n";
		}


	}while(choice!=7);

}
