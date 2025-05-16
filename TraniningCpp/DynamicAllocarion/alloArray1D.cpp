#include <iostreaM>

using namespace std;

int main(){
    //allocate dynamic array 1D
    int *pa = new int[5]; //attend "[]" and "()" when allocate pointer

    delete[] pa; //free array pointer

    return 0;
}