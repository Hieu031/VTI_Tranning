#include <iostream>
#include <math.h>

using namespace std;
using ll = long long;

int fibonaci(ll n);

int main(){
    ll n = 87;

    if(fibonaci(n)){
        cout << "This is a fibonaci number.\n";
    }else{
        cout << "This is not a fibonaci number.\n";
    }
}

int fibonaci(ll n){
    if(n <= 1){
        return 1;
    }
    ll f1 = 1, f0 = 0, fn;
    for(int i = 2; i <= 100; i++){
        fn = f1 + f0;
    
        if(fn == n){
            return 1;
        }

        f0 = f1;
        f1 = fn;
    }
    return 0;
}