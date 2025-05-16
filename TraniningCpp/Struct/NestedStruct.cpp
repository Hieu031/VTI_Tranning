#include<iostream>

using namespace std;

// //Example declare implicit
// typedef struct {
//     int day;
//     int month;
//     int year;
// }date;

//This is a substruct
struct date {
    int day;
    int month;
    int year;
};
//Note: Substruct must be declared before parent struct.

//This is a struct parent
struct employee{
    char name[20];
    int age;
    date birthday; // type struct variable
    char role[20];
};

//declare function prototype
void DisplayEmploy(employee e);

int main(){
    //Way to create value struct
    employee e1 = {
        "Nguyen Hieu", 23,
        {27, 12, 2002}, "DevC++" 
        //creata var for substruct using {a, {b, c}, d};
    };

    //Show information employ before change
    DisplayEmploy(e1);
    cout << endl;

    //Change value of struct
    cout << "Name: "; cin.getline(e1.name, 20);;
    cout << "Age: "; cin >> e1.age;
    cout << "Birthday\n"; 
    cout << "Day: "; cin >> e1.birthday.day;
    cout << "Month: "; cin >> e1.birthday.month;
    cout << "Year: "; cin >> e1.birthday.year;
    cin.ignore(); // ignore enter character in buffer
    cout << "Role: "; cin >> e1.role;

    cout << endl;

    //Show information employ after change
    DisplayEmploy(e1);
    cout << endl;

    return 0;
}

void DisplayEmploy(employee e){
    cout << "Name: " << e.name << endl;
    cout << "Age: " << e.age << endl;
    cout << "Birthday: " << e.birthday.day << "/" << e.birthday.month << "/" << e.birthday.year << endl;
    cout << "Role: " << e.role << endl;
}
