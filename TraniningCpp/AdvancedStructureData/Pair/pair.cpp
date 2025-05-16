#include<iostream>
#include<utility>

using namespace std;

int main(){
    pair<int, int> p1 = {1, 2};
    pair<int, int> p2 = {3, 4};

    cout << "First: " << endl;
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;

    // cout << endl;
    p1.swap(p2); //use function swap to change value elements in pair 1 and pair 2.

    cout << "After: \n";
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;

    return 0;
}