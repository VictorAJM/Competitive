#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=1005;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
struct UnionFind {
    int ran,pad;
} uf[N],pf[N];
int n,a,b,x,y;

int bus(int u,bool cual)
{
    if (cual == 0) {
        if (uf[u].pad != u) uf[u].pad = bus(uf[u].pad,0);
        return uf[u].pad;
    } else {
        if (pf[u].pad != u) pf[u].pad = bus(pf[u].pad,1);
        return pf[u].pad;
    }
}
void unir(int u,int v,int c)
{
    u = bus(u,c);
    v = bus(v,c);
    if (c==0) {
        if (uf[u].ran > uf[v].ran) {
            uf[v].pad = u;
        } else if (uf[v].ran > uf[u].ran) {
            uf[u].pad = v;
        } else {
            uf[u].pad = v;
            uf[v].ran++;
        }
    } else {
        if (pf[u].ran > pf[v].ran) {
            pf[v].pad = u;
        } else if (pf[v].ran > pf[u].ran) {
            pf[u].pad = v;
        } else {
            pf[u].pad = v;
            pf[v].ran++;
        }
    }
}
void solve()
{
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++) uf[i].pad = pf[i].pad = i;
    for (int i=1;i<=n;i++) uf[i].ran = pf[i].ran = 0;
    for (int i=1;i<=a;i++) {
        cin >> x >> y;
        unir(x,y,0);
    } 
    for (int i=1;i<=b;i++) {
        cin >> x >> y;
        unir(x,y,1);
    } 
    vector<ii> res;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) 
        if (bus(i,0) != bus(j,0) && bus(i,1) != bus(j,1)) {
            unir(i,j,0);
            unir(i,j,1);
            res.push_back(make_pair(i,j));
        }
        cout << res.size() << "\n";
        for (auto u : res) cout << u.F <<" " <<  u.S << "\n";
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
