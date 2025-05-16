// #include<iostream>
// #include <math.h>

// using namespace std;

// /*
// According to Euclid, UCLN of two interge a and b:
// UCLN not change when change greater num by greater - least
// Redo unitl greater = least

// BCNN(a, b) = a * b / UCLN(a, b) 

// Can update Euclid algorithm: instead (a -  b) with (a % b)
// Example: UCLN(a, b) = UCLN(a, a % b); 
//             This progress will reagain until one of both = 0
//             and remain num will UCLN
// */

// int UCLN(int a, int b);
// int BCNN(int a, int b);

// int main(){
//     int a = 10;
//     int b = 35;

//     cout << "UCLN(10, 35): " << UCLN(a, b) << endl;
//     cout << "BCNN(10, 35): " << BCNN(a, b) << endl;

//     return 0;
// }

// int UCLN(int a, int b){
//     while(b != 0){
//         int r = a % b;
//         a = b;
//         b = r;
//     }
//     return a;
// }

// int BCNN(int a, int b){
//     return (a * b) / UCLN(a, b);
// }

#include <iostream>
using namespace std;

typedef long long ll;

ll UCLN(ll a, ll b);
ll BCNN(ll a, ll b);

int main() {
	// your code goes here
	ll a, b;
	
	
	while(1){
		cin >> a >> b;
		if(a == 0 && b == 0){
			break;
		}
		
		cout << UCLN(a, b) << " " <<BCNN(a, b) << endl;
	}
	
	return 0;
}

//use Euclid algorithm
ll UCLL(ll a, ll b){
	while(b != 0){
		ll r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

ll BCNN(ll a, ll b){
	return (a * b) / UCLN(a, b); 
}