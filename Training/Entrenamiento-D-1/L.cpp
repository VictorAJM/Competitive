#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=2e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,k,a[N];
vector<int> g[N];
void solve()
{
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        g[a[i]].push_back(i+1);
    }
    if (g[0].size() != 1){
        cout << "-1";
        return;
    }
    bool t = true;
    if (g[1].size() > k) t = false;
    for (int i=2;i<n;i++) {
        ll p = (k-1);
        p *= (ll)g[i-1].size();
        if (g[i].size() > p) t = false;
    }
    if (!t) {
        cout << "-1";
        return;
    }

    int rt = g[0][0];
    vector<ii> res;
    for (int u : g[1]) res.push_back({rt,u});
    for (int i=2;i<n;i++) {
        int j = 0;
        for (int u : g[i-1]) {
            int q = k-1;
            while (q>0 && j<g[i].size()) {
                res.push_back({u,g[i][j]});
                q--;
                j++;
            }
        }
    }
    cout << res.size() <<"\n";
    for (ii u : res) cout << u.F << " "<<u.S<<"\n";
    
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
