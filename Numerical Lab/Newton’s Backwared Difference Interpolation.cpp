#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
using namespace std;

ll fact(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++)
        res *= i;
    return res;
}

//u term
double u_term(double u, int n) {
    double temp = u;
    for (int i = 1; i < n; i++)
        temp *= (u + i);
    return temp;
}

//backward formula
double newtonBackward(double x[], double y[], double value, int n) {
    // backward difference table
    double diff[20][20];
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    // Display the backward difference table
    cout << "Backward Difference Table:" << nl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << diff[i][j] << "\t"; // Print each entry with a tab for spacing
        }
        cout << nl; // New line after each row
    }

    // initializing
    double u = (value - x[n - 1]) / (x[1] - x[0]);
    double result = diff[n - 1][0];

    for (int i = 1; i < n; i++) {
        result += (u_term(u, i) * diff[n - 1][i]) / fact(i);
    }

    return result;
}

int main() {
    int n;
    cout << "Number of data points (n): ";
    cin >> n;

    double x[10], y[10];
    cout << " x :" << nl;
    // 0 1 2 3 4
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    } //1, 0, 1, 1, 10
    cout << " y :" << nl;
    for (int i = 0; i < n; i++) {
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }
    double value;
    cout << "Enter the value of x to interpolate: ";
    cin >> value;

    cout << "Interpolated value at x = " << value << " is " << newtonBackward(x, y, value, n) << nl;
}
