#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=1e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,m,k,a[N],x,y,z,b[N];
vector<ii> g[N];
int h[505][505];
int d[505][505],cnt;
struct UnionFind {
    int dad,ran;
} uf[N];
bool vs[N];
vector<int> p[N];
int bus(int u)
{
    if (uf[u].dad != u) uf[u].dad = bus(uf[u].dad);
    return uf[u].dad;
}
void dfs(int u,int L,int R)
{
    if (L <= u && u <= R) cnt++;
    vs[u] = true;
    for (int v : p[u]) if (!vs[v]) dfs(v,L,R);
    return;
}
void unir(int u,int v, bool ww)
{
    u = bus(u); v = bus(v);
    if (u != v) {
        if (ww) cnt--;
        if (uf[u].ran > uf[v].ran) {
            uf[v].dad = u;
        } else if (uf[v].ran > uf[u].ran) {
            uf[u].dad = v;
        } else {
            uf[u].dad = v;
            uf[v].ran++;
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i=0;i<k;i++)
        cin >> a[i];
    int q=0;
    for (int i=0;i<k;i++) {
        for (int j=1;j<=a[i];j++) {
            q++;
            b[q] = i+1;
        }
    }
    cnt = n;
    for (int i=1;i<=n;i++) {
        uf[i].dad = i;
        uf[i].ran = 0;
    }
    for (int i=1;i<=k;i++) for (int j=1;j<=k;j++) d[i][j] = -1;
    for (int i=1;i<=k;i++) for (int j=1;j<=k;j++) h[i][j] = -1;
    for (int i=0;i<m;i++) {
        cin >> x >> y >> z;
        if (z==0) {
            p[x].push_back(y);
            p[y].push_back(x);
            unir(x,y,false);
        }  else {

        }
        if (h[b[x]][b[y]] == -1) {
            h[b[x]][b[y]] = z;
            h[b[y]][b[x]] = z;
        } else {
            h[b[x]][b[y]] = min(z,h[b[x]][b[y]]);
            h[b[y]][b[x]] = min(z,h[b[y]][b[x]]);
        }   
    }
    for (int i=1;i<=k;i++) for (int j=1;j<=k;j++) if (h[i][j] != -1) {
        g[i].push_back({j,h[i][j]});
    }
    for (int i=1;i<=k;i++) g[i].push_back({i,0});
    bool t = true;
    int ww = 1;
    for (int i=0;i<k;i++) {
        cnt =0;
        for (int j=1;j<=n;j++) vs[j] = false;
        dfs(ww,ww,ww+a[i]-1);
        if (cnt < a[i]) t = false;
        if (!t) i = k+1; 
        ww += a[i];
    }




    if (!t) {
        cout << "No";
        return;
    }


            priority_queue<ii,vector<ii>,greater<ii>> pq;
    for (int i=1;i<=k;i++) {

        for (auto v : g[i]) pq.push({v.S,v.F});
        for (int j=1;j<=k;j++) vs[j] = false;
        while (!pq.empty()) {
            auto gg = pq.top();
            pq.pop();
            if (!vs[gg.S]) {
                d[i][gg.S] = gg.F;
                vs[gg.S] = true;
                for (auto v : g[gg.S])if (!vs[v.F]) pq.push({v.S+gg.F,v.F});
            }
        }
    }
    cout << "Yes\n";
    for (int i=1;i<=k;i++) {
        for (int j=1;j<=k;j++) cout << d[i][j] << " ";
        cout << "\n";
    }
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