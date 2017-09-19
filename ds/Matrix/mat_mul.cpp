#include <iostream>
using namespace std;

// Function that takes matrix input
void inMat(int* a, int r, int c) {
    for(int i = 0; i < r;  i++) {
        for(int j = 0; j < c; j++) {
            cin >> *(a+i*c+j);
        }
    }
}

// Function to display the matrix
void disp(int* a, int r, int c) {
    for(int i = 0; i < r; i++) {
        for( int j = 0; j < c; j++) {
            cout << *(a+i*c+j) << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    int r1, c1, r2, c2;  // Number of rows and columns

    cout << "Input the dimension of first matrix 'row column: ";
    cin >> r1 >> c1 ;
    cout << "\nInput the dimension of second matrix 'row column: ";
     cin >> r2 >> c2;

     if(c1 != r2) {  // Check for valid dimension of 2 matrices
        cout << "Matrix cannot be multiplied\n";
        return 1;
     }

     int a[r1][c1], b[r2][c2] ; // Declaring 2 matrices
     cout << "Enter the elements of matrix A\n";
     inMat((int*)a, r1, c1);
     cout << "Enter the elements of matrix B\n";
     inMat((int*)b, r2, c2);

     int c[r1][c2]; // Declaring the output matrix
     for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            int sum = 0;
            for(int k = 0; k < c1 ; k++) {
                sum += a[i][k]*b[k][j];
            }
            c[i][j] = sum;
        }
     }

     cout << "Matrix A: \n";
     disp((int*)a, r1, c1);

     cout << "Matrix B: \n";
     disp((int*)b, r2, c2);

     cout << "Matrix C: \n";
     disp((int*)c, r1, c2);
     return 0;
}
