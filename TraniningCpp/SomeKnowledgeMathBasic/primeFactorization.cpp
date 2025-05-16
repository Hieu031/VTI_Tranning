#include<iostream>
#include<math.h>

#define for(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

/*
This lesson use Trial division:
    1.Browser i from 2 to sqrt(n)
    2.If n divisible i, divive until undivisible
    3.After browser end, if n > 1 => n is the last prime need found.
*/
void factorization(int n);

int main(){
    factorization(60);
    return 0;
}

void factorization(int n){
    for(i, 2, sqrt(n)){
        while(n % i == 0){
            cout << i << " ";
            n /= i;
        }
    }    
    if(n > 1){
        cout << n;
    }
}

// #include<iostream>
// #include<math.h>

// using namespace std;

// void run_case(long long n){
// for(long long i = 2;i <= sqrt(n);i++){
// long long dem = 0;
// if(n % i == 0){
// cout << i << " ";
// while(n % i == 0){
// ++dem;
// n /= i;
// }
// cout << dem << "\n";
// dem = 0;
// }
// }
// if(n != 1) cout << n << " " << 1;
// }


// int main(){
// long long n; cin >> n;
// run_case(n);
// }