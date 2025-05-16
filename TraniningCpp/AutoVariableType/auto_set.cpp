#include<iostream>
#include<set>

using namespace std;

int main(){
    set<string> s = {"hieu", "Long", "huan", "lam"};
    
    cout << "Loop by range-base for loop using auto: " << endl;
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;

    auto pos = s.find("hieu");

    if(pos == s.end()){
        cout << "NOT FOUND!" << endl;
    }else{
        cout << "FOUND!" << endl;
    }

    return 0;
}
