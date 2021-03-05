#include <bits/stdc++.h>
using namespace std;

double sq(double x, double y, double z) {
    if (x > (y+z))
        return 0;
    double p = (x + y + z) / 2;
    return sqrt(p * (p-x) * (p-y) * (p-z));
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    double r = 0;
    for (int i=0; i<n-2; i++)
    {
        double s = sq(a[i], a[i+1], a[i+2]);
        r = max(r, s);
    }
    if (r>0)
        printf("%.3f", r);
    else
        printf("0");
}
