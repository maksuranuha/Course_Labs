#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to evaluate f(x) = e^x
double f(double x) {
    return exp(x);
}

double simpsonsOneThird(double a, double b, int n) {
    // Step size
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    // Sum the terms according to Simpson's 1/3 rule
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);  // Coefficient 2 for even terms
        } else {
            sum += 4 * f(x);  // Coefficient 4 for odd terms
        }
    }

    // Multiply the sum by h/3
    return (h / 3) * sum;
}

int main() {
    // Define the limits and the number of subintervals
    double a = 0.0, b = 0.6;
    int n = 6; // Number of subintervals (must be even)

    // Compute the integral using Simpson's 1/3 rule
    double result = simpsonsOneThird(a, b, n);

    // Output the result with 6 decimal places
    cout << fixed << setprecision(6);
    cout << "The integral result is: " << result << endl;

    return 0;
}
