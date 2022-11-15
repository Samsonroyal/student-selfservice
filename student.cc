#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Student
{
    int stdno;            // student number
    char name[20];       // student name
    char gender;         // student gender
    int year;            // year of study(1,2,3,4)
    char courseunit[25]; // Course Unit
    float marks;         // marks obtained by student
    float percentage;    // percentage of marks obtained by student

public:
    void getData();
    void showData();
    int getStdno() { return stdno; }
} s;

void Student::getData()
{
    cout << "\n\nEnter Student Details......\n";
    cout << "Enter Student Number.     : ";
    cin >>  stdno;              // input student number
    cout << "Enter Full Name         : "; // input student name
    cin.ignore();
    cin.getline(name, 20); // input student name
    cout << "Enter Gender (M/F)      : ";
    cin >> gender; // input student gender
    cout << "Enter Year of Study          : ";
    cin >> year; // input year of study
    cout << "Enter Course Unit Name         : "; // input Course unit name
    cin.ignore();
    cin.getline(courseunit, 25); // input course unit name
    cout << "Enter Marks (out of 100): ";
    cin >> marks;                       // input marks obtained by student
    cout << endl;                       // print new line
    percentage = marks * 10.0 / 100.00; // calculate percentage of marks obtained by student
}

void Student::showData()
{
    cout << "\n\n.......Student Details......\n";
    cout << "Student No.     : " << stdno << endl;         // display student number
    cout << "Full Name         : " << name << endl;       // display student name
    cout << "Gender            : " << gender << endl;     // display student gender
    cout << "Year of Study          : " << year << endl;   // display year of study
    cout << "Course Unit Name         : " << courseunit << endl;       // display course unit name
    cout << "Marks (out of 100): " << marks << endl;      // display marks obtained by student
    cout << "Percentage        : " << percentage << endl; // display percentage of marks obtained by student
    cout << endl;
}

void addData()
{
    ofstream fout;                                                // create object of ofstream class
    fout.open("Students.dat", ios::binary | ios::out | ios::app); // open file in binary mode for writing
    s.getData();                                                  // call getData() function to input student details
    fout.write((char *)&s, sizeof(s));                            // write student details in file
    fout.close();                                                 // close file
    cout << "\n\nData Successfully Saved to File....\n";          // display message
}

void displayData()
{
    ifstream fin;                                    // create object of ifstream class
    fin.open("Students.dat", ios::in | ios::binary); // open file in binary mode for reading
    while (fin.read((char *)&s, sizeof(s)))          // read data from file
    {
        s.showData(); // call showData() function to display student details
    }
    {
        s.showData(); // call showData() function to display student details
    }
    fin.close();                                                  // close file
    cout << "\n\nData Reading from File Successfully Done....\n"; // display message
}

void searchData()
{
    int n, flag = 0;                                 // declare variables
    ifstream fin;                                    // create object of ifstream class
    fin.open("Students.dat", ios::in | ios::binary); // open file in binary mode for reading
    cout << "Enter Student Number you want to search : ";
    cin >> n; // input student number to search
    cin >> n; // input student number to search

    while (fin.read((char *)&s, sizeof(s)))
    {
        if (n == s.getStdno())
        {
            cout << "The Details of Student No. " << n << " are shown here:\n"; // display message
            s.showData();
            flag++;
        }
    }
    fin.close();                                                  // close file
    if (flag == 0)                                                // if flag is 0 then student number not found
        cout << "The Student No. " << n << " not found....\n\n";  // display message
    cout << "\n\nData Reading from File Successfully Done....\n"; // display message
}

void deleteData()
{
    int n, flag = 0;     // declare variables
    ifstream fin;        // create object of ifstream class
    ofstream fout, tout; // create object of ofstream class

    fin.open("Students.dat", ios::in | ios::binary);               // open file in binary mode for reading
    fout.open("TempStud.dat", ios::out | ios::app | ios::binary);  // open file in binary mode for writing
    tout.open("TrashStud.dat", ios::out | ios::app | ios::binary); // open file in binary mode for writing

    cout << "Enter Student Number you want to move to Trash : ";
    cin >> n; // input student number to move to Trash

    while (fin.read((char *)&s, sizeof(s)))
    {
        if (n == s.getStdno())
        {
            cout << "The Following Student No. " << n << " has been moved to Trash:\n"; // display message
            s.showData();                                                               // call showData() function to display student details
            tout.write((char *)&s, sizeof(s));                                          // write student details in Trash file
            flag++;                                                                     // increment flag
        }
        else
        {
            fout.write((char *)&s, sizeof(s));
        }
    }
    fout.close();
    tout.close();
    fin.close();
    if (flag == 0)
        cout << "The Student No. " << n << " not found....\n\n";
    remove("Students.dat");
    rename("tempStud.dat", "Students.dat");
}

void getTrash()
{
    ifstream fin;
    fin.open("TrashStud.dat", ios::in | ios::binary);
    while (fin.read((char *)&s, sizeof(s)))
    {
        s.showData();
    }
    fin.close();
    cout << "\n\nData Reading from Trash File Successfully Done....\n";
}

void modifyData()
{
    int n, flag = 0, pos;
    fstream fio;

    fio.open("Students.dat", ios::in | ios::out | ios::binary);

    cout << "Enter Student Number you want to Modify : ";
    cin >> n;

    while (fio.read((char *)&s, sizeof(s)))
    {
        pos = fio.tellg();
        if (n == s.getStdno())
        {
            cout << "The Following Student No. " << n << " will be modified with new data:\n";
            s.showData();
            cout << "\n\nNow Enter the New Details....\n";
            s.getData();
            fio.seekg(pos - sizeof(s));
            fio.write((char *)&s, sizeof(s));
            flag++;
        }
    }
    fio.close();

    if (flag == 0)
        cout << "The Student No. " << n << " not found....\n\n";
}

void project()
{
    int ch;

    do
    {
        system("cls");
        cout << "...............STUDENT MARKS SYSTEM..............\n";
        cout << "======================================================\n";
        cout << "\n0. Exit from Program\n";
        cout << "1. Record Student Information\n";
        cout << "2. Read Student Information\n";
        cout << "3. Search Student Information\n";
        cout << "4. Delete Student Information\n";
        cout << "5. Get Deleted Records from Trash\n";
        cout << "6. Modify Student Information\n";
        cout << "\nEnter your choice  : ";
        cin >> ch;
        system("cls"); // clear screen
        switch (ch)
        {
        case 1:
            addData();
            break;
        case 2:
            displayData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            getTrash();
            break;
        case 6:
            modifyData();
            break;
        }
        system("pause"); // pause the screen
    } while (ch);        // loop will run until user enter 0
}

int main() // main function
{
    project(); // call project() function
    return 0;  // return 0 to operating system
}
