#include <iostream>
#include <iomanip>
#include <cmath>
#define nl '\n'
using namespace std;

int main()
{
    int n;
    cout << "enter n intervals: ";
    cin >> n;

    if (n % 2 != 0)
    {
        cout << "error, it requires an even number of intervals!" << nl;
        return 1;
    }
    double x[10], y[10];
    //0.0 0.1 0.2 0.3 0.4 0.5 0.6
    cout << "Enter " << n + 1 << " values of x:\n";
    for (int i = 0; i <= n; i++)
    {
        cin >> x[i];
    }

    //func of y
    for (int i = 0; i <= n; i++)
    {
        y[i] = exp(x[i]);
    }

    double h = (x[n] - x[0]) / n;
    double integral = y[0] + y[n]; // Init sum

    //table
    cout << "\nStep-by-Step Contributions to the Integral:\n";
    cout << setw(10) << "i" << setw(10) << "x[i]" << setw(10) << "y[i]" << setw(15) << "Multiplier" << setw(15) << "Contribution" << nl;
    cout << string(60, '-') << nl;

    for (int i = 1; i < n; i++) {
        double multiplier = (i % 2 == 0) ? 2 : 4; // 2-even, 4-odd
        double contribution = multiplier * y[i];
        integral += contribution;

        cout << setw(10) << i << setw(10) << x[i] << setw(10) << y[i] << setw(15) << multiplier << setw(15) << contribution << nl;
    }

    integral *= (h / 3);

    cout << fixed << setprecision(5);
    cout << "\nIntegral value using Simpson's 1/3 Rule = " << integral << nl;

    return 0;
}
