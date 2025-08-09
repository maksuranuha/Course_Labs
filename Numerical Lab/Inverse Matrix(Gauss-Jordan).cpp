#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 10
//Gauss-Jordan elimination
bool gaussJordan(float a[MAX][MAX], float inv[MAX][MAX], int n) {
    //augmented matrix [a | I]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = (i == j) ? 1.0 : 0.0; // Identity matrix
        }
    }

    //Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Find the pivot element
        float pivot = a[i][i];
        if (pivot == 0) {
            cout << "Matrix is singular, cannot find inverse" << endl;
            return false; // Singular matrix
        }

        //divide row by pivot element
        for (int j = 0; j < n; j++) {
            a[i][j] /= pivot;
            inv[i][j] /= pivot;
        }

        for (int j = 0; j < n; j++) {
            if (j != i) {
                float factor = a[j][i];
                for (int k = 0; k < n; k++) {
                    a[j][k] -= factor * a[i][k];
                    inv[j][k] -= factor * inv[i][k];
                }
            }
        }
    }

    return true;
}

// display matrix
void displayMatrix(float matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    float a[MAX][MAX], inv[MAX][MAX];

    cout << "Enter the elements of the matrix (A):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    float b[MAX];
    cout << "Enter the elements of the constants vector (B):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (gaussJordan(a, inv, n)) {
        cout << "\nThe inverse matrix is:" << endl;
        displayMatrix(inv, n);

        // x = A^-1 * B
        float x[MAX] = {0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                x[i] += inv[i][j] * b[j];
            }
        }

        cout << "\nThe solution vector (x) is:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    }

    return 0;
}
