#include <bits/stdc++.h>
#define trav(a,v) for (auto a : v)
#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
const int N = 5e4+5;
typedef long long ll;
int n,k,a[N],b[N];
vector<int> g[N];
ll dp[N][505];
bool vs[N];
ll res = 0;
void ini(int u)
{
    vs[u] = true;
    trav(v,g[u]) if (!vs[v]) {
        ini(v);
        for (int j=1;j<=k;j++) dp[u][j] += dp[v][j-1];
    }
    dp[u][0]=1;
}
void get(int u)
{
	vs[u] = true;
	//cerr << dp[u][k] << "\n";
	res += dp[u][k]+dp[u][k];
	trav(v,g[u]) if (!vs[v]) {
		get(v);
		for (int j=1;j<k;j++) if (k-j-1>=0){
			res += dp[v][j-1]*(dp[u][k-j]-dp[v][k-j-1]);
			//cerr << dp[v][j-1]*(dp[u][k-j]-dp[v][k-j-1])<<"\n";
		}
	}
	return;
}
int main()
{
    fast_io;
    cin >> n >> k;
    for (int i=0;i<n-1;i++) cin >> a[i] >> b[i];
    for (int i=0;i<n-1;i++) {g[a[i]].push_back(b[i]); g[b[i]].push_back(a[i]); }
    ini(1);
    /*for (int i=1;i<=n;i++) {
        for (int j=0;j<=k;j++) cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    for (int i=1;i<=n;i++) vs[i] = false;
    get(1);
    cout << res/2;
}