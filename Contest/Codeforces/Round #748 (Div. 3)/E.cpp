#include <bits/stdc++.h>
#define F first
#define S second
#define watch(x) cerr << #x << " " << x << "\n";
#define sz(a) (int)a.size()

using namespace std;

const int MOD = 0;
const int N = 4e5+5;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vi2;
int t,n,k,a,b;
vi g[N];
int deg[N];
int cnt;
bool vs[N];
queue<pair<int,int> > q;

void solve()
{
    cin >> n >> k;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<=n;i++) deg[i]=0;
    for (int i=1;i<=n;i++) vs[i] = 0;
    for (int i=1;i<n;i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;i++) if (deg[i]<= 1) q.push({i,1});
    cnt = 0;
    while (!q.empty()) {
        auto x = q.front();
        if (vs[x.F] == false) {
            vs[x.F] = true;
            q.pop();
            if (x.S <= k) {
                for (int u : g[x.F]) if (!vs[u]) deg[u]--,deg[x.F]--;
                cnt++;
                for (int u : g[x.F]) if (deg[u] <= 1 && !vs[u]) q.push({u,x.S+1}); 
            }
        }
    }
    cout << n - cnt << "\n";
}


int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
