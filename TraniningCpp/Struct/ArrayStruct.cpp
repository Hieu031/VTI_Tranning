#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

/*
We can use arrays of struct to store data of struct. This action will manage 
structs in a more convenient way. 

*/

//Declare struct
struct employee{
    char name[20];
    int age;
    char role[20];
    int salary;
};

//declare function prototype
void InitEmploy(employee *e, int length);
void DisplayEmploy(employee *e, int length);
void DisplaySingleEmploy(employee *e); //show max, min employee salary
employee SearchSalaryMax(employee *e, int length);
employee SearchSalaryMin(employee *e, int length);

int main(){
    // //Declare array static struct
    // employee e[5]; //decalre a array struct employee with 5 elements

    cout << "Enter number of employee: ";
    int n; cin >> n;

    //Declare array dynamic struct
    employee *e1; // allocate memory for array struct employee
    //Note: this declaration has both two meaning: 
    //1. e1 is a pointer to struct employee
    //2. e1 is a pointer to array of struct employee
    e1 = new employee[n]; // allocate memory for array struct employee with 5 elements

    InitEmploy(e1, n); // call function to input data for array struct employee
    DisplayEmploy(e1, n); // call function to display data of array struct employee
    cout << "======================" << endl;

    employee max =  SearchSalaryMax(e1, n); // call function to search max salary of array struct employee
    employee min =  SearchSalaryMin(e1, n); // call function to search min salary of array struct employee
    
    cout<< "Max employee: " << endl;
    DisplaySingleEmploy(&max); // call function to display data of array struct employee
    cout << "======================" << endl;

    cout << "Min employee: " << endl;
    DisplaySingleEmploy(&min); // call function to display data of array struct employee
    cout << "======================" << endl;


    delete[] e1; //free array memory for struct employee
    return 0;
}

void InitEmploy(employee *e, int length){
    for (int i = 0; i < length; i++) {
        cin.ignore(); // Clear input buffer before getline
        cout << "Name: "; cin.getline(e[i].name, 20);
        cout << "Age: "; cin >> e[i].age;
        cin.ignore(); // Clear input buffer after cin
        cout << "Role: "; cin.getline(e[i].role, 20);
        cout << "Salary: "; cin >> e[i].salary;
        cin.ignore(); // Clear input buffer after cin
        cout << endl;
    }
}

void DisplayEmploy(employee *e, int length){
    //print table header
    cout << left 
    << setw(20) << "Name" 
    << setw(10) << "Age" 
    << setw(20) << "Role" 
    << setw(10) << "Salary" << endl;
    cout << string(60, '-') << endl; // print line

    //print table content
    for(int i = 0; i < length; i++){
        cout << left
        << setw(20) << e[i].name
        << setw(10) << e[i].age
        << setw(20) << e[i].role
        << setw(10) << e[i].salary << endl;
    }
    cout << endl;
}

void DisplaySingleEmploy(employee *e){
    //print table header
    cout << left 
    << setw(20) << "Name" 
    << setw(10) << "Age" 
    << setw(20) << "Role" 
    << setw(10) << "Salary" << endl;
    cout << string(60, '-') << endl; // print line

    //print table content
    cout << left
        << setw(20) << e->name
        << setw(10) << e->age
        << setw(20) << e->role
        << setw(10) << e->salary << endl;
    cout << endl;
}

employee SearchSalaryMax(employee *e, int length){
    int index = 0; // index of max salary
    int max = e[0].salary; // max salary
    for(int i = 0; i < length; i++){
        if(e[i].salary > max){
            max = e[i].salary;
            index = i;
        }
    }
    return e[index]; // return struct employee with max salary
}

employee SearchSalaryMin(employee *e, int length){
    int index = 0; // index of min salary
    int min = e[0].salary; // min salary
    for(int i = 0; i < length; i++){
        if(e[i].salary < min){
            min = e[i].salary;
            index = i;
        }
    }
    return e[index]; // return struct employee with min salary
}

