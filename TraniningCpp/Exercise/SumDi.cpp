#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;

ll divisor(ll n){
    ll sum = 0;
    for(ll i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            sum += i; //divisor 1
            if (i != n / i){
                sum += n / i; //divisor remain after greater sqrt(n)
            }
        }
    }

    return sum;
}


int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll testcase; cin >> testcase;

    while(testcase--){
        cout << "Enter: ";
        ll n; cin >> n;
        cout << divisor(n) << endl;
    }
	
	return 0;
}
