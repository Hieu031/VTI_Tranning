#include <iostream>

using namespace std;

/*
A array 2D is apointer point to a pointer. So need allocate memory according to 
dimention of array.

*/

//Declare function prototype 
void InitArray(int **&a, int row, int colum);
void AddArray(int **a, int **b, int row, int colum);
void DisplayArray(int **a, int row, int colum);
void DeleteArray(int **a, int row);

int main(){
    // int **a;

    // const int length = 10;

    // a = new int*[length]; //alloacte memory for numbers row of matrix
    // //use int* to C++ allow to allocate a pointer int type

    // //allocate memory for each element of each row
    // for(int i = 0; i < 10; i++){
    //     a[i] = new int(length);
    // }

    // //Above operation: allocate memory for a matric 10x10;

    // for(int i = 0; i < length; i++){
    //     delete[] a[i]; //free memory each row
    // }

    // delete[] a; //free memory matrix
    int **a = nullptr, **b = nullptr;

    cout << "Enter row and colum: " << "\n";
    int row, colum;
    cin >> row >> colum;

    cout << "Initialize a: " << endl;
    InitArray(a, row, colum);

    //Init matrix a and display
    // DisplayArray(a, row, colum);
    cout << endl;
    //Init matrix b and display
    cout << "Initialize b: " << endl;
    InitArray(b, row, colum);
    // DisplayArray(b, row, colum);
    cout << endl;

    //Sum two matrix
    cout << "Sum of matrix a and b: " << endl;
    AddArray(a, b, row, colum);
    DisplayArray(a, row, colum);

    //Free memory matrix
    DeleteArray(a, row);
    DeleteArray(b, row);

    return 0;
}

void InitArray(int **&a, int row, int colum){
    a = new int*[row]; //allocate memory new array 2D 

    for(int i = 0; i < row; i++){
        a[i] = new int[colum]; //allocate memory each row
        for(int j = 0; j < colum; j++){
            cout << "Element [" << i <<"]" <<"[" << j << "] = ";
            cin >> a[i][j]; //Type value element of matrix
        }
    }
}

void AddArray(int **a, int **b, int row, int colum){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < colum; j++){
            a[i][j] += b[i][j]; //Sum two matrix
        }
    }
}

void DisplayArray(int **a, int row, int colum){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < colum; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n"; //line break to create a new row
    }
    return;
}

void DeleteArray(int **a, int row){
    for(int i = 0; i < row; i++){
        delete[] a[i]; //free row
    }
    delete[] a; //free matrix
    return;
}