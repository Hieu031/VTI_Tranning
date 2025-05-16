// A array is a constain pointer so we can't calculate via itself.
// But We can assign a pointer as that array and calculate via that new pointer
// Example:
#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int *pt1 = arr; // the same: int pt1* = &arr[0];
    /*
    pt1 will point to arr[0]'s address and 
    it's value also is arr[0]'s value
    */
    cout << "address of pt1: " << pt1 << endl;
    
    pt1++; //this operation will shift right address of pt1 1 unit.
    cout << "address and value of pt1 after above operation: " << pt1 << " " << *pt1 << endl;

    *pt1++; // this operaton will increase value of memory address pointing 1 unit.
    cout << "value after: " << *pt1 << endl;

    return 0;
}   