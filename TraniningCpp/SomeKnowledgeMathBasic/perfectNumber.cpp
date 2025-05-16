#include <iostream>
#include <math.h>

using namespace std;
//This code only acitivities good with n <= 10^12
// int perfectNum(int n){
//     int sum = 0;

//     for(int i = 1; i <= sqrt(n); i++){
//         if(n % i == 0){
//             sum += i;
//             if(i != n / i){
//                 sum += n / i; 
//             }
//         }
//     }

//     if(sum - n == n){
//         return 1;
//     }
//     return 0;
// }

// int main(){
//     while(1){
//         cout << "Enter n: ";
//         int n;
//         cin >> n;

//         if(perfectNum(n)){
//             cout << "N is perfect number!" << endl;
//         }
//         else{
//             cout << "N is not perfect number!" << endl;
//         }

//         if(n == 0) {
//             break;
//         }
//     }
//     return 0;
// }

//this code help optimate n <= 10^18 (long long)
/*
use theorem Euclid - Euler: 
    if p is a prime number and 2^(p - 1) is also prime number,
    2^(p - 1) * (2^p - 1) is a perfect number.
*/
typedef long long ll;

int isPrime(ll n){
    if(n < 2){
        return 0;
    }

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int perfectNum(ll n){
    //2^(p - 1) * (2^p - 1) ~ 2^(2p) up to 9.10^18 ~ 2^63 
    //=> 2p ~ 6 3=> p ~ 32, 33 is OK.
    for(int p = 1; p <= 33; p++){
        if(isPrime(p)){
            ll tmp1 = (1LL << p) - 1; //2^p - 1
            if(isPrime(tmp1)){
                ll tmp2 = (1LL << (p - 1)); //2^(p - 1)
                if(tmp1 * tmp2 == n){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(perfectNum(i)){
            cout << i << " ";
        }
    }

    return 0;
}