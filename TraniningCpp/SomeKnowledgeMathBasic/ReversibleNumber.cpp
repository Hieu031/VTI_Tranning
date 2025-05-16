#include<iostream>
using namespace std;

int ReversibleNumber(int n){
    int m, tmp;
    tmp = n;

    while(n != 0){
        m = m * 10 + n % 10;
        n /= 10;
    }

    if(m == tmp){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    while(1){
        int a;
        cout << "Enter a: ";
        cin >> a;

        if(ReversibleNumber(a)){
            cout << "Ok!" << endl;
        }else{
            cout << "Not OK!" << endl;
        }

        if(a == 0) {break;}
    }

    return 0;
}