#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
double f(double x, double y)
{
    return 1 - y;
}

int main() {
    double x0, y0, h, x_end;
    cout << "Enter the initial value of x (x0): ";
    cin >> x0;
    cout << "Enter the initial value of y (y0): ";
    cin >> y0;
    cout << "Enter the step size (h): ";
    cin >> h;
    cout << "Enter the value of x where you want to stop (x_end): ";
    cin >> x_end;

    double x = x0, y = y0;
    vector<pair<double, double>> results;
    cout << "\nEuler's Method:\n";
    cout << setw(10) << "x" << setw(15) << "y" << endl;
    cout << "--------------------------------" << endl;

    results.push_back({x, y});
    while (x <= x_end)
    {
        cout << setw(10) << x << setw(15) << y << endl;
        y = y + h * f(x, y);
        x = x + h;
        results.push_back({x, y});
    }
    cout << "\nTabulated Results:\n";
    cout << setw(10) << "x" << setw(15) << "y" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < results.size(); i++) {
        cout << setw(10) << results[i].first << setw(15) << results[i].second << endl;
    }
    return 0;
}
