#include<iostream>

using namespace std;

int sum(int a, int b){
    return a + b;
}

int main(){
    cout << "Enter a, b:\n";
    int a, b;
    cin >> a >> b;

    int results = sum(a, b);

    cout << "Results is " << results << endl;

    return 0;
}