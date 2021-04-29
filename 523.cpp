#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll maxPage =0, pageSum=0;
    for (ll i=0; i<n; i++) {
        cin >> a[i];
        maxPage=max(maxPage, a[i]);
        pageSum==a[i];
        assert(a[i]>0);
    }
    ll nVolumes;
    cin >> nVolumes;
    ll left=maxPage-1, right=32767;
    while (left+1 < right) {
        ll mid=(left+right)/2;
        ll curVolumes=0, lastVolume=0;
        for (int i=0; i<n; i++) {
            if (lastVolume+a[i]<=mid)
                lastVolume+=a[i];
            else {
                curVolumes++;
                lastVolume=a[i];
                if (a[i]>mid) {
                    curVolumes=nVolumes+1;
                    break;
                }
            }
        }
        assert(lastVolume>0);
        curVolumes++;
        if (curVolumes<=nVolumes)
            right=mid;
        else
            left=mid;
    }
    cout << right;
}
