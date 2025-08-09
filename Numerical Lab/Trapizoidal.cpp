#include <bits/stdc++.h>
#define nl '\n'
using namespace std;
#define f(x) (x / (1 + x))
int main()
{
    double a, b; //0 1
    int n; //6
    cout << "Enter the lower limit: ";
    cin >> a;
    cout << "Enter the upper limit: ";
    cin >> b;
    cout << "Enter the number of n: ";
    cin >> n;
    double h = (b - a) / n;

    //I=h/2[(y0+yn)+2(y1+y2+...yn-1)]

    double ans = f(a) + f(b);
    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        ans += 2 * f(x);
    }
    double I = ans * h / 2;

    cout << fixed << setprecision(3) << I << nl;

    return 0;
}

