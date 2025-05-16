#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//assuming that this vector sorted
int binarySearch(vector<int> v, int target);

int main(){
    vector<int> v = {1, 4, 6, 9, 3, 5, 9, 2, 7, 8};
    cout << "Target: ";
    int n; cin >> n; //Enter number need finding

    sort(v.begin(), v.end()); //arange vector before using function binary search

    cout << binarySearch(v, n); //if return -1 meaning not found.

    return 0;
}

int binarySearch(vector<int> v, int target){
    int low = 0, high = v.size() - 1; //create index first and end 

    while (low <= high){
        int mid = low + (high - low) / 2; //use this recipe to avoid overflow  
        if (v[mid] == target){
            return v[mid];
        }else if (v[mid] < target){
            low = mid + 1; //continue searching at right middle
        }else{
            high = mid - 1; //continue searching at left middle
        }
    }

    return -1;
}