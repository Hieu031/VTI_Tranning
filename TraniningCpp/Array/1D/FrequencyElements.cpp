#include<iostream>
#include<math.h>

using namespace std;

int countFreApear(int a[], int b[], int n);

int main(){
    int a[10] = {1, 2, 4, 5, 2, 3, 3, 1, 4, 5};
    int b[10] = {0};
    int n = 10;
    countFreApear(a, b, n);

    return 0;
}

int countFreApear(int a[], int b[], int n){
//    arr[10] = {1, 3, 4, 6, 7, 2, 3, 4, 1, 5};
    for(int i = 0; i < n; i++){
        if(b[i] == 0){
            int count = 1;
            for(int j = i + 1; j < n; j++){
                if(a[i] == a[j]){
                    count++;
                    b[j] = 1;//tick appeared
                }
            }
            cout << a[i] << " appeared " << count << " times." << endl;
        }
    }
    return 0;
}