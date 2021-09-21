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
int n;
vi g[N];
int rt;
bool hijos[N];
int tam[N];
bool vs[N];
bool bud[N],tt[N];
int r;
void dfs(int u)
{
    vs[u] = true;
    tam[u] = 1;
    if (u != rt) bud[u] = true; 
    for (int v : g[u]) if (!vs[v]) {
        dfs(v);
        tam[u] += tam[v];
        hijos[u] = true;
        tt[u] = true;
        if (hijos[v]==true) bud[u] = false;
    }
    if (!tt[u] || !hijos[u]) bud[u] = false;
    if (bud[u]) {
        //cout << u << " ";
        r = max(r,tam[u]-1);}
}
void solve()
{
    cin >> n;
    for (int i=0;i<=n;i++) g[i].clear();
    for (int i=1;i<=n;i++) {
        bud[i] = vs[i] = tt[i] = hijos[i] = false;
        tam[i] = 0;
    }
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    rt = 1;
    r=1;
    dfs(1);
    cout << r<<"\n";
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
