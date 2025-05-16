#include<iostream>
#include<math.h>

using namespace std;

int isSquare(int n)
{
    int n1 = sqrt(n);
    if(pow(n1, 2) == n){
        return 1; //is square number
    }
    else{
        return 0; // is not sn
    }
}
int main(){

    while (1)
    {
    int n;
    cout << "Enter n: " ;
    cin >> n;

    if(isSquare(n)) {
        cout << n <<  " is square number!" << endl;}
    else {
        cout << n << " is not!" << endl;
    }
    //return 0;
    if(n == 0) {
        break;
    }

    }
    
    
}