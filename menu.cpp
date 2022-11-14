// C++ program to implement
// Bank Management System

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class Student_acc
{
	
	int Pay_Tuition;
	char type;
	int acno;
	char name[70];
public:
	
	void report() const;
	int retPay_Tuition() const;
	void create_Student_acc();
	void dep(int);
	int retacno() const;
	void Display_Account() const;
	void Update();
	char rettype() const;
	void draw(int);
};
 
 
void Student_acc::Update()
{
	cout<<"\n\tStudent_acc No. : "<<acno;
	cout<<"\n\tUpdate Student_acc Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tUpdate Type of Student_acc : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tUpdate Balance Total-Money : ";
	cin>>Pay_Tuition;
}
void Student_acc::create_Student_acc()
{
	system("CLS");
	cout<<"\n\tPlease Enter the Student_acc Reg No. : ";
	cin>>acno;
	cout<<"\n\n\tPlease Enter the Name of the Student_acc holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tPlease Enter Type of the Student_acc (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tPlease Enter The Starting Total-Money : ";
	cin>>Pay_Tuition;
	cout<<"\n\n\tStudent_acc Created..";
}
 
void Student_acc::Display_Account() const
{
	cout<<"\n\tStudent_acc No. : "<<acno;
	cout<<"\n\tStudent_acc Holder Name : ";
	cout<<name;
	cout<<"\n\tType of Student_acc : "<<type;
	cout<<"\n\tBalance Total-Money : "<<Pay_Tuition;
}
int Student_acc::retacno() const
{
	return acno;
}
 
 
 
char Student_acc::rettype() const
{
	return type;
}
void Student_acc::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<Pay_Tuition<<endl;
}
void Student_acc::dep(int x)
{
	Pay_Tuition+=x;
}
void Student_acc::draw(int x)
{
	Pay_Tuition-=x;
}
int Student_acc::retPay_Tuition() const
{
	return Pay_Tuition;
}
 
 
void write_Student_acc();
void display_sp(int);
void display_all();
 
void delete_Student_acc(int);
void Pay_Tuition_withdraw(int, int);
void Update_Student_acc(int);
int main()
{
	char ch;
	int num;
	do
	{
	system("CLS");
	cout<<"\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	
	cout<<"\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
 
		cout<<"\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t1. NEW Student_acc";
		cout<<"\n\t\t2. Pay_Tuition Total-Money";
		cout<<"\n\t\t3. WITHDRAW Total-Money";
		cout<<"\n\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t5. ALL Student_acc HOLDER LIST";
		cout<<"\n\t\t6. CLOSE AN Student_acc";
		cout<<"\n\t\t7. Update AN Student_acc";
		cout<<"\n\t\t8. EXIT";
		cout<<"\n\n\t\tSelect Your Option (1-8): ";
		cin>>ch;
 
		switch(ch)
		{
		case '1':
			write_Student_acc();
			break;
		case '2':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Student_acc No. : "; cin>>num;
			Pay_Tuition_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Student_acc No. : "; cin>>num;
			Pay_Tuition_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Student_acc No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Student_acc No. : "; cin>>num;
			delete_Student_acc(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\tPlease Enter The Student_acc No. : "; cin>>num;
			Update_Student_acc(num);
			break;
		 case '8':
		 	system("CLS");
			cout<<"\n\n\tBrought To You By code-projects.org";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}