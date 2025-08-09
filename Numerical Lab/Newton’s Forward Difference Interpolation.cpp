#include <iostream>
using namespace std;

// factorial
int factorial(int n) {
  int fact = 1;
  for (int i = 2; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

int main() {

  double x[20], y[20][20], xp, u, h, p;
  int i, j, n;

  cout << "Enter number of data: ";
  cin >> n;

  // x- 0, 1, 2, 3, 4 & y-9, 43, 169, 471
  cout << "Enter data: " << endl;
  for (i = 0; i < n; i++) {
    cout << "x[" << i << "] = ";
    cin >> x[i];
    cout << "y[" << i << "] = ";
    cin >> y[i][0];
  }

  // table
  for (i = 1; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
  }
  cout << endl << "FORWARD DIFFERENCE TABLE" << endl;
  for (i = 0; i < n; i++) {
    cout << x[i];
    for (j = 0; j < n - i; j++) {
      cout << "\t" << y[i][j];
    }
    cout << endl;
  }

  cout << "Enter the value of x for which you want the value of y: ";
  cin >> xp;

  h = x[1] - x[0];
  u = (xp - x[0]) / h;

  p = y[0][0];

  for (i = 1; i < n; i++) {
    double term = u;
    for (j = 1; j < i; j++) {
      term *= (u - j);
    }
    p += (term * y[0][i]) / factorial(i);
  }

  cout << endl
       << "The estimated value of y at x = " << xp << " is " << p << endl;

  return 0;
}
