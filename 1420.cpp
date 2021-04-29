#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    //6 3 2 5 7 11 15 20
    for (int i=0; i<n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int left = 0;
    int right =a.back()-a[0]+1;
    while (left < right) {
        int mid = (left + right) / 2, cows=1, last=a[0];
        for (ll i=1; i<a.capacity(); i++) {
            if (a[i]-last>mid) {
                cows+=1;
                last=a[i];
            }
        }
        if (cows>=k)
            left=mid+1;
        else
            right=mid;
    }
    cout << left;
}
