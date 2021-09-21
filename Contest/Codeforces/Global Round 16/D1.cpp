#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=305+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int m,n,a[N][N],f[100005];

int ff[100005];
int b[N][N],c[N][N],bin[N][N];
vector<vector<int>> g;
bool cmp(ii u,ii v)
{
    if (u.S != v.S)
        return (u.S > v.S);
    return (u.F < v.F);
}
void add(int u,int v,int cu)
{
    while (v <= m) {
        bin[u][v] += cu;
        v += v&(-v);
    }
    return;
}
int get(int u,int v)
{
    int r = 0;
    while (v>0) {
        r += bin[u][v];
        v -= v&(-v);
    }
    return r;
}
int X[90005],Y[90005];
void solve()
{
    cin >> n >> m;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
    set<int> s;
    map<int,int> h;
    g.clear();
    for (int i=0;i<n;i++) for (int j=0;j<m;j++)s.insert(a[i][j]);
    int q = 0;
    for (int u : s) h[u] = ++q;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[i][j] = h[a[i][j]];
    for (int i=0;i<=q;i++) f[i] = ff[i] = 0;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) f[a[i][j]]++;
    for (int i=1;i<=q;i++) f[i] += f[i-1];

    for (int ii=0;ii<=q;ii++)
    for (int i=0;i<n;i++)  g[ii].push_back({});
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        int  p = f[a[i][j]-1] + ff[a[i][j]];
        ff[a[i][j]]++;
        b[i][j] = p/m;
        c[i][j] = p%m;
        g[a[i][j]][b[i][j]].push_back(p%m);
    }
    ll res = 0;
    for (int i=0;i<n;i++) for (int j=0;j<=m;j++) bin[i][j] = 0;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        add(i,j+1,1);
    }
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        int x=-1;
        int y=n*m;
        int z = a[i][j];
        for (int ii=0;ii<n;ii++) {
            if (!g[z][ii].empty()) {
                int  p = g[z][ii][g[a[i][j]][ii].size()-1];
                int gg = get(ii,m) - get(ii,p+1);
                if (gg < y) {
                    x = ii;
                    y = gg;
                } 
            }
        }
        add(x,g[a[i][j]][x][g[a[i][j]][x].size()-1]+1,-1);
        res += y;
        g[a[i][j]][x].pop_back();
    }
    cout << res << "\n";
    return;
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
