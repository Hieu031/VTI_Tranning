#include<iostream>
#include<math.h>

using namespace std;

int prime(int n){
    if(n < 2){
        return 0; //remove 0,1 and negative number
    }
    
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0; //remove immediately
        }
    }

    return 1; //is prime
}

int main(){
    int n = 100;

    for(int i = 1; i <= n; i++){
        if(prime(i) == 1){
            cout << i << " ";
        }
    }
    return 0;
}