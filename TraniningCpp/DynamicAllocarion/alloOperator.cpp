#include <iostream>

using namespace std;

/*
Dynamic allocation to pointer is a operation which assign pointer a specified 
memory and put it into occupied area which ohters program can't use.


*/

int main(){
    int a[5] = {1, 3, 5, 7, 9};

    int *pa = new int(12); //allocate dynamic pointer pa and assgin value is 12
    //can assign value immediately or not

    delete pa; //releasa memory

    pa = a; //after free, can assign pointer to new variable such array a

    for(int i = 0; i < 5; i++){
        cout << *(pa + i) << " ";
    }

    return 0;

    /*
    Note:
    1. pointer after allocate by "new", must free before pointing 
    a new address or alloacte a new address
    2. If multipple pointer point the same address, free
    a pointer, remaining pointer is also free
    */
}