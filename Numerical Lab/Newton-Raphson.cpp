#include <bits/stdc++.h>
using namespace std;

// f(x) = x^2 - 3x + 2
double f(double x) {
    return x * x - 3 * x + 2;
}

// f'(x) = 2x - 3
double df(double x) {
    return 2 * x - 3;
}

int main() {
    double x0, x1, tolerance;
    int maxIter;

    cout << "Enter the initial guess (x0): ";
    cin >> x0;
    cout << "Enter the desired tolerance: "; // 0.0001
    cin >> tolerance;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    int iterationCounter = 0;

    cout << fixed << setprecision(4);
    cout << "Find the root of the equation f(x) = x^2 - 3x + 2" << endl;
    cout << "The output:" << endl;

    //NewtonRaphson
    while (iterationCounter < maxIter) {
        double fx0 = f(x0);
        double dfx0 = df(x0);
        if (dfx0 == 0)
        {
            cout << "Derivative is zero. No solution found." << endl;
            return 1;
        }
        x1 = x0 - fx0 / dfx0;

        cout << "x" << iterationCounter + 1 << " = " << x0 << " - (" << fx0 << " / " << dfx0 << ") = " << x1 << endl;

        //stopping criteria
        if (fabs(x1 - x0) < tolerance) {
            cout << "\nRoot found at: " << x1 << " after " << iterationCounter + 1 << " iterations." << endl;
            return 0; // Successful exit
        }

        //update
        x0 = x1;
        iterationCounter++;
    }
    cout << "No root found within " << maxIter << " iterations. Try again with different parameters." << endl;
    return 0;
}
