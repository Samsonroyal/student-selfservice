// Online C++ compiler to run C++ program online
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class Student_Account
{
	
	int Money_Deposit;
	char type;
	int acno;
	char name[70];
public:
	
	void report() const;
	int retMoney_Deposit() const;
	void create_Student_Account();
	void dep(int);
	int retacno() const;
	void Display_Account() const;
	void Updation();
	char rettype() const;
	void draw(int);
};
 
 
void Student_Account::Updation()
{
	cout<<"\n\tStudent_Account No. : "<<acno;
	cout<<"\n\tUpdation Student_Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tUpdation Type of Student_Accountt : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tUpdation Balance Total-Money : ";
	cin>>Money_Deposit;
}
void Student_Account::create_Student_Account()
{
	system("CLS");
	cout<<"\n\tPlease Enter the Student_Account No. : ";
	cin>>acno;
	cout<<"\n\n\tPlease Enter the Name of the Student_Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tPlease Enter Type of the Student_Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tPlease Enter The Starting Total-Money : ";
	cin>>Money_Deposit;
	cout<<"\n\n\tStudent_Account Created..";
}
 
void Student_Account::Display_Account() const
{
	cout<<"\n\tStudent_Account No. : "<<acno;
	cout<<"\n\tStudent_Accountt Holder Name : ";
	cout<<name;
	cout<<"\n\tType of Student_Account : "<<type;
	cout<<"\n\tBalance Total-Money : "<<Money_Deposit;
}
int Student_Account::retacno() const
{
	return acno;
}
 
 
 
char Student_Account::rettype() const
{
	return type;
}
void Student_Account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<Money_Deposit<<endl;
}
void Student_Account::dep(int x)
{
	Money_Deposit+=x;
}
void Student_Account::draw(int x)
{
	Money_Deposit-=x;
}
int Student_Account::retMoney_Deposit() const
{
	return Money_Deposit;
}
 
 
void write_Student_Account();
void display_sp(int);
void display_all();
 
void delete_Student_Account(int);
void Money_Deposit_withdraw(int, int);
void Updation_Student_Account(int);
int main()
{
	char ch;
	int num;
	do
	{
	system("CLS");
	cout<<"\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	
	cout<<"\t\tSTUDENT SELF-SERVICE PLATFORM";
	cout<<"\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
 
		cout<<"\t\t   ::MAIN MENU::\n";
		cout<<"\n\t\t1. Register Student Account";
		cout<<"\n\t\t2. Pay Tuition";
		cout<<"\n\t\t3. View Course Units";
		cout<<"\n\t\t4. Student Account";
		cout<<"\n\t\t5. EXIT";
		cout<<"\n\n\t\tSelect Your Option (1-5): ";
		cin>>ch;
 
		switch(ch)
		{
		case '1':
			write_Student_Account();
			break;
		case '2':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Student_Account Reg No. : "; cin>>num;
			Money_Deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Student_Account Reg No. : "; cin>>num;
			Money_Deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Student_Account Reg No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Student_Account Reg No. : "; cin>>num;
			delete_Student_Account(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Updation_Student_Account(num);
			break;
		 case '8':
		 	system("CLS");
			cout<<"\n\n\tDesigned by Samson, Ziporah, James and Christopher";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}
 
 
 
 
 
void write_Student_Account()
{
	Student_Account ac;
	ofstream outFile;
	outFile.open("Student_Account.dat",ios::binary|ios::app);
	ac.create_Student_Account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Student_Account));
	outFile.close();
}
void delete_Student_Account(int n)
{
	Student_Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Student_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Student_Account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Student_Account));
		}
	}
    inFile.close();
	outFile.close();
	remove("Student_Account.dat");
	rename("Temp.dat","Student_Account.dat");
	cout<<"\n\nRecord Deleted ..";
}
 
void display_sp(int n)
{
	Student_Account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("Student_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\ STUDENT DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Student_Account)))
	{
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\tStudent_Account number does not exist";
}
 
 
void display_all()
{
	system("CLS");
	Student_Account ac;
	ifstream inFile;
	inFile.open("Student_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tStudent_Account HOLDER LIST\n\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Student_Account)))
	{
		ac.report();
	}
	inFile.close();
}
void Updation_Student_Account(int n)
{
	bool found=false;
	Student_Account ac;
	fstream File;
    File.open("Student_Account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Student_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			cout<<"\n\n\tPlease Enter The New Details of Student_Account"<<endl;
			ac.Updation();
			int pos=(-1)*static_cast<int>(sizeof(Student_Account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Student_Account));
		    cout<<"\n\n\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
}
 
void Money_Deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Student_Account ac;
	fstream File;
    File.open("Student_Account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Student_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			if(option==1)
			{
				cout<<"\n\n\tTO Money_DepositSS Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be Money_Deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be withdraw: ";
				cin>>amt;
				int bal=ac.retMoney_Deposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Student_Account));
			cout<<"\n\n\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
}