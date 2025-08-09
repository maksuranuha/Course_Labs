//Taylor's Series Method
#include <iostream>
#include <iomanip>

using namespace std;

// Function definitions for derivatives based on the example
double f(double x, double y) {
    return x + y; // dy/dx = x + y
}

double f1(double x, double y, double y1) {
    return 1 + y1; // d²y/dx² = 1 + y'
}

double f2(double y2) {
    return y2; // d³y/dx³ = y''
}

double f3(double y3) {
    return y3; // d⁴y/dx⁴ = y'''
}

int main() {
    double x0 = 1.0, y0 = 0.0; // Initial conditions
    double h = 0.1;           // Step size
    double xn = 1.2;          // Target x value
    int steps = (xn - x0) / h;

    cout << fixed << setprecision(6);

    for (int i = 0; i < steps; i++) {
        double y1 = f(x0, y0);
        double y2 = f1(x0, y0, y1);
        double y3 = f2(y2);
        double y4 = f3(y3);

        // Taylor series formula
        double y_next = y0 + h * y1 + (h * h / 2) * y2 + (h * h * h / 6) * y3 + (h * h * h * h / 24) * y4;

        x0 += h;
        y0 = y_next;

        cout << "At x = " << x0 << ", y = " << y0 << endl;
    }

    return 0;
}
