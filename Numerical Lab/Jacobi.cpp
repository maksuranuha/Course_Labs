#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void jacobiMethod(int n, vector<vector<double>>& A, vector<double>& b, vector<double>& x, int maxIter, double tol)
{
    vector<double> xOld(n, 0);

    for (int iter = 0; iter < maxIter; ++iter)
        {
        xOld = x;

        for (int i = 0; i < n; ++i)
            {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j) //diagonal elem check
                {
                    sum += A[i][j] * xOld[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        double error = 0; //converged naki check
        for (int i = 0; i < n; ++i) {
            error += abs(x[i] - xOld[i]);
        }
        if (error < tol) {
            cout << "Solution converged after " << iter + 1 << " iterations.\n";
            return;
        }
    }
    cout << "Solution did not converge after " << maxIter << " iterations.\n";
}

int main()
{
    int n;
    cout << "Number of equations: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), x(n, 0); // x to zeros

    cout << "coefficient matrix, A: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "constant matrix b: \n";
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    int maxIter;
    double tol;
    cout << "maximum iterations: ";
    cin >> maxIter;
    cout << "tolerance value: ";
    cin >> tol;

    jacobiMethod(n, A, b, x, maxIter, tol);

    cout << "\n Approximate solution vector x: \n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

}
