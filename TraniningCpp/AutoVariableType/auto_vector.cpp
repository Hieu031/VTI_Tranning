#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v =  {1, 2, 3, 5, 4};

    cout << "Loop by range for loop:" << endl;
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
    cout << "---------------------------------------" << endl;

    cout << "Loop by iterator: " << endl;
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }

    return 0;
}