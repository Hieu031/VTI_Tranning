#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int, string> stu;

    //add key and value in map
    stu.insert({1, "Hieu"});
    stu.insert({2, "Long"});
    stu.insert({3, "Lam"});

    cout << "Browser by range-based for loop: " << endl;
    for(auto x : stu){
        cout << x.first << ":" << x.second << endl;
    }
    
    cout << "------------------------------" << endl;
    cout << "Browser by interator: " << endl;
    
    for(auto it = stu.begin(); it != stu.end(); it++){
        cout << it->first << ":" << it->second << endl;
    }
    return 0;
}