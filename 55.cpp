#include <bits/stdc++.h>
#define PI 3.141592653589793
using namespace std;
int main() {
    long double x1, x2, y1, y2, r, s;
    cin >> x1 >> y1 >> x2 >> y2 >> r >> s;

    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))/2;
    double S = PI * r * r * 2;

    if (d < r) {
        double t=2*acos(d/r);
        S-=r*r*(t-sin(t));
    }
    if (S > s)
        cout << "YES";
    else
        cout << "NO";
}