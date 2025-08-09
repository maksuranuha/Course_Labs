#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y)
{
    return x + y; // Ex dy/dx = x + y
}

double rungeKutta(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    while (x < xn)
    {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;
    }

    return y;
}

int main()
{
    double x0 = 0;
    double y0 = 1;
    double h = 0.1;
    double xn = 1;
    double result = rungeKutta(x0, y0, h, xn);

    cout << "The value of y at x = " << xn << " is " << result << endl;
    return 0;
}
