#include<iostream>

using namespace std;

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    
    int *pa = a;

    pa += 15;

    for(int i = 0; i < 5; i++){
        cout << *(pa + i) << " ";
    }

    delete[] pa;

    return 0;
}    