#include<iostream>
#include<math.h>

using namespace std;

/*
C(n, 0) = 1 and C(n, n) = 1

C(n, k) = C(n -1, k - 1) + C(n - 1, k)
*/

int C(int n, int k);

int main(){
    cout << C(12, 2) << endl;
    return 0;
}

int C(int n, int k){
    if(n == 0 || k == 0){
        return 1;
    }
    else{
        return C(n - 1, k - 1) + C(n - 1, k);
    }
}