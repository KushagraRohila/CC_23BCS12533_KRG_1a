#include <bits/stdc++.h>
using namespace std;


long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    long long a = 30, b = 20;
    long long x, y;

    long long g = extendedGCD(a, b, x, y);

    cout << "GCD: " << g << "\n";
    cout << "x: " << x << ", y: " << y << "\n";
    cout << a << "*" << x << " + " << b << "*" << y << " = " << g << "\n";

    return 0;
}
