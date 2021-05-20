#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, pos;
    cin >> n >> pos;
    if (pos==1) {
        cout << n;
        return 0;
    }
    int s=0;
    while (pos%2!=0) {
        s+=n/2;
        n-=n/2;
        pos=(pos+1)/2;
    }
    s+=pos/2;
    cout << s;
    return 0;
}