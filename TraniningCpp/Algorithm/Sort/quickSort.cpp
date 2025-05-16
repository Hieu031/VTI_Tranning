#include <iostream>
#include <algorithm>

using namespace std;

void quickSort(int arr[], int left, int right);

int main(){
    cout << "Enter number element of array: ";
    int n; cin >> n;
    int* arr = new int[n]; //allocate a dynamic array 
    for(int i = 0; i < n; i++){
        cout << "Enter element " << i + 1<< ": ";
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Array after sort: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;

    delete[] arr; //free arrayy after to avoid leak memory

    return 0;
}

void quickSort(int arr[], int left, int right){
    if (left >= right) return; //Exit early function 
    
    int pivot = arr[(left + right) / 2]; //Choose a middle number 

    int i = left, j = right; //Create variable cache to browser and compare

    while (i <= j){
        //browser and compare arr[i], arr[j] to pivot  
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        //swap elements if indices aren't acrossed
        if (i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    //recursive calls to subarrays
    if (left < i){
        quickSort(arr, left, j);
    }
    if (j < right){
        quickSort(arr, i, right);
    }
}