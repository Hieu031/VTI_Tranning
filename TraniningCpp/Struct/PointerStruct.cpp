#include<iostream>
#include<string.h>
#include<cstdlib> //this library to use system("cls")

using namespace std;

//declare struct
typedef struct {
    int day;
    int month;
    int year;
}date;

typedef struct employee{
    char name[20];
    date birthday; // type struct variable
    char role[20];
    int salary; 
}employee;

//declare function prototype
void InitStruct(employee *e);
void DisplayEmploy(employee *e);

int main(){ 
    system("cls"); // clear screen

    employee *e = new employee; // allocate memory for struct employee

    InitStruct(e); // call function to input data for struct employee
    DisplayEmploy(e); // call function to display data of struct employee
    
    delete e; // free memory for struct employee
    //Note: when e is allocated by command: new, we can delete e;
    //if assign e to a address such as: e = &e1; we can't delete e;
    //because e1 is a local variable, when we delete e, e1 will be deleted too.
    e = NULL; // set pointer to NULL to avoid dangling pointer

    return 0;
}

void InitStruct(employee *e){
    // e = new employee; // allocate memory for struct employee
    //type name employee
    cout << "Name: "; cin.getline(e->name, 20);
    //type birthday employee
    cout << "Birthday\n";   
    cout << "Day: "; cin >> e->birthday.day;
    cout << "Month: "; cin >> e->birthday.month;
    cout << "Year: "; cin >> e->birthday.year;
    cin.ignore(); // ignore enter character in buffer

    //type role employee
    cout << "Role: "; cin.getline(e->role, 20);

    //type salary employee
    cout << "Salary: "; cin >> e->salary;
}

void DisplayEmploy(employee *e){
    cout << "Name: " << e->name << endl;
    cout << "Birthday: " << e->birthday.day << "/" << e->birthday.month << "/" << e->birthday.year << endl;
    cout << "Role: " << e->role << endl;
    cout << "Salary: " << e->salary << endl;
}