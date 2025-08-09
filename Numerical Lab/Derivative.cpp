#include <iostream>
using namespace std;

void askN(int &n) {
    cout << "Enter the number of values: ";
    cin >> n;
}

void askX(double x[], int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter X[" << i << "] : ";
        cin >> x[i];
    }
    cout << endl;
}

void askF(double f[][10], int n) {
    for (int j = 0; j < n; j++) {
        cout << "Enter F[" << j << "] : ";
        cin >> f[0][j];
    }
    cout << endl;
}

void askXX(double &XX) {
    cout << "Enter X for which the value is to be found: ";
    cin >> XX;
}

void forwardTable(double f[][10], double x[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            f[i][j] = (f[i - 1][j + 1] - f[i - 1][j]);
            if (f[i][j] < 0.0000009 && f[i][j] > 0 || f[i][j] > -0.0000009 && f[i][j] < 0) {
                f[i][j] = 0;
            }
        }
    }
    cout << endl;
    cout << "Sn\tXi\tf(Xi)\t";
    for (int i = 0; i < n - 1; i++) {
        cout << i + 1 << " diff\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << f[j][i] << "\t";
        }
        cout << endl;
    }
}

void findH(double x[], double &h) {
    h = x[1] - x[0];
}

void findS(double x[], double &XX, double &h, double &u) {
    u = (XX - x[0]) / h;
}

void fillDelF(double delF[], double f[][10], int n) {
    for (int i = 1; i < 10; i++) {
        if (i < n)
            delF[i] = f[i][0];
        else
            delF[i] = 0;
    }
}

void calcd1(double delF[], double h, double u, double &f1) {
    f1 = 1 / h * (delF[1] + 1 / 2.0 * (2 * u - 1) * delF[2] + 1 / (6.0) * (3 * u * u - 6 * u + 2) * delF[3] + 1 / (24.0) * (4 * u * u * u - 18 * u * u + 22 * u - 6) * delF[4]);
}

void calcd2(double delF[], double h, double u, double &f2) {
    f2 = 1 / (h * h) * (delF[2] + 1 / 6.0 * (6 * u - 6) * delF[3] + 1 / 24.0 * (12 * u * u - 36 * u + 22) * delF[4]);
}

int main() {
    int n;
    double XX, x[10], f[10][10], delF[10], h, u, f1, f2;

    askN(n);
    askX(x, n);
    askF(f, n);
    askXX(XX);
    forwardTable(f, x, n);

    findH(x, h);
    findS(x, XX, h, u);
    fillDelF(delF, f, n);
    calcd1(delF, h, u, f1);
    calcd2(delF, h, u, f2);

    cout << endl << "The value of f1 :" << f1;
    cout << endl << "The value of f2 :" << f2;
    cout << endl << endl;

    return 0;
}
