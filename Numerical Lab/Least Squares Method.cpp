#include <iostream>
#include <vector>
#include <iomanip>
#define nl '\n'
#define ll long long
using namespace std;

void leastSquares(const vector<ll>& x, const vector<ll>& y, double& a, double& b) {
    int n = x.size();
    ll sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    cout << "\nX\tY\tX^2\tXY\n";
    for (int i = 0; i < n; ++i)
    {
        ll x2 = x[i] * x[i];
        ll xy = x[i] * y[i];

        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x2;
        sum_xy += xy;

        cout << x[i] << "\t" << y[i] << "\t" << x2 << "\t" << xy << nl;
    }

    cout << "---------------------------------"<<nl;
    cout << sum_x << "\t" << sum_y << "\t" << sum_x2 << "\t" << sum_xy << "\n\n";

    b = (double)(n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (double)(sum_y - b * sum_x) / n;
}

int main() {
    int n;
    cout << "Number of data points: ";
    cin >> n;

    vector<ll> x(n), y(n);
    cout << "X values: ";
    for (int i = 0; i < n; ++i)//0 2 5 7
    {
        cin >> x[i];
    }

    cout << "Y values: ";
    for (int i = 0; i < n; ++i) //-1 5 12 20
    {
        cin >> y[i];
    }

    double a, b;
    leastSquares(x, y, a, b);

    cout << "Calculated values for a & b"<<nl;
    cout << "a = " << a << nl;
    cout << "b = " << b << nl;

    return 0;
}
