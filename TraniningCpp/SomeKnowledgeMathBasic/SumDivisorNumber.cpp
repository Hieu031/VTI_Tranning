#include<iostream>
#include<math.h>

using namespace std;

int SumDivisor(int n){
    int sum = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i; // divisor 1
            if(i != n / i){
                sum += n / i; //remain divisor responeding to divisor 1.
            }
        }
    }
    return sum;
}

int main(){
    while(1){
        cout << "Enter n: ";
        int n;
        cin >> n;
        cout << "Sum divisor of n: " << SumDivisor(n) << endl;

        if(n == 0) break;
    }
    return 0;
}