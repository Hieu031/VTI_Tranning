#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

/*
Normally, function is not a variable so not have a address defination.
But during running, funtion in C++ also have a specified memory area so
C++ allow to use pointer to point function.
pointer function used to pass parameter have function type.
*/

/*
Way to declare:
    Example: int (*calcu)(int a, int b); 
        This is a function pointer, has type int, and two parameters also type int
        Note: "(*calcu)" is necessary because if we declare as this:
                    int *calcu(int a, int b);
                C++ will mean that this is a function which return a pointer.
*/

//function use a function pointer as a parameter 
void Display(char str[], int (*Xtype) (int c));

int main(){
    char input[500];
    cout << "Enter the string: ";
    cin >> input;
    char reply;
    cout << "Display the string in uppercase or lowercase (u,l): ";
    cin >> reply;
    if(reply == 'l') // show type lowercase
        Display(input, tolower);
    else // show type uppercase
        Display(input, toupper);
    return 0;
}

void Display(char str[], int (*Xtype)(int c)){
    int index = 0;
    while(str[index] != '\0'){
        cout << (*Xtype)(str[index]); // Sử dụng con trỏ hàm
        index ++;
    }
    cout << endl;
 }
    