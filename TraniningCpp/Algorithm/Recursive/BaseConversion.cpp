#include<iostream>

using namespace std;
typedef long long ll;

void conversionBinary(ll n);

int main(){
    cout << "Enter n: ";
    int n; cin >> n;

    cout << n << " = "; conversionBinary(n);

    return 0;
}

void conversionBinary(ll n){
    if(n < 2){
        cout << n;
    }
    else{
        conversionBinary(n / 2);
        cout << n % 2;
    }
}