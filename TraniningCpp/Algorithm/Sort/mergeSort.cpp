#include <iostream>
#include <vector>
using namespace std;

// Hàm merge: trộn hai mảng con đã sắp xếp vào mảng gốc arr
void merge(vector<int>& arr, int left, int mid, int right);
// Hàm mergeSort: sắp xếp mảng con của arr từ chỉ số left đến right
void mergeSort(vector<int>& arr, int left, int right);

int main(){
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cout << "Nhap phan tu " << i << ": ";
        cin >> arr[i];
    }
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Mang sau khi sap xep:" << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;   // Kích thước mảng con trái
    int n2 = right - mid;      // Kích thước mảng con phải

    // Tạo các mảng tạm L và R
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Trộn L và R trở lại vào arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy phần còn lại của L (nếu có)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy phần còn lại của R (nếu có)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return; // Nếu mảng chỉ có 1 phần tử, kết thúc đệ quy

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);        // Sắp xếp mảng con bên trái
    mergeSort(arr, mid + 1, right);     // Sắp xếp mảng con bên phải
    merge(arr, left, mid, right);       // Trộn hai mảng con đã sắp xếp lại với nhau
}