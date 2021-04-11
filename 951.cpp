#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const long double PI = 3.141592653589793;
typedef long double ld;
typedef pair<ld, ld> pld;
vector<int> used;
vector<vector<int> > G;
vector<int> top_sort;
void dfs(int v){
    used [v]=1;
    for (auto to : G[v])
        if (!used[to])
            dfs(to);
    top_sort.push_back(v);
}
 
int main(){
    //ifstream cin("input.txt");
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    vector <pair<int, int>> v(k);
    for (int i=0;i<k;i++){
        cin>>v[i].x>>v[i].y;
    }
    int mx=-1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
                int mn=1e9;
            for (int c=0;c<k;c++){
                    int r=abs(i-v[c].x)+abs(j-v[c].y);
                    mn=min(r,mn);
                    }
                mx=max(mx,mn);
            }
        }
        cout<<mx;
    }
