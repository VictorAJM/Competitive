
// Hasta donde tope

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define wh while
#define re return
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define watch(x) cerr<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define rofn(i,a,b) for (int i=(a);i>(b);i--) 
#define rofe(i,a,b) for (int i=(a);i>=(b);i--)
#define setp(x,a) cout<<fixed<<setprecision(x)<<a

#define TEST int tt,Case=0; cin >> tt; wh (tt--) solve(++Case); 
#define ALL(n) int Case=0; wh (cin >> n) solve(++Case);
#define ONLYONE int Case=0; solve(++Case);

#define TACOSDECHASKA(n) int main() {fast_io; n; return 0;}
using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vii;
typedef vector<ll> vl;
typedef pair<ll,ll> l2;
typedef long double ld;

const int mod=0;
const int N=1005;
const ld EPS = 1e-9;
int n,m;
char a[N][N];
vii p[200];
int dp[N][N],z;
void check(i2 u)
{
	int x = u.F; int y = u.S;
	if (x > 0 && y > 0) if (a[x-1][y-1] == a[x][y]+1) 
	dp[x][y] = max(dp[x][y],dp[x-1][y-1]+1);
		if (x > 0 && y < m-1) if (a[x-1][y+1] == a[x][y]+1) 
	dp[x][y] = max(dp[x][y],dp[x-1][y+1]+1);
		if (x > 0 ) if (a[x-1][y] == a[x][y]+1) 
	dp[x][y] = max(dp[x][y],dp[x-1][y]+1);
	
		if ( y > 0) if (a[x][y-1] == a[x][y]+1) 
	dp[x][y] = max(dp[x][y],dp[x][y-1]+1);
			if ( y < m-1) if (a[x][y+1] == a[x][y]+1) 
	dp[x][y] = max(dp[x][y],dp[x][y+1]+1);
	
		if (x < n-1 && y > 0) if (a[x+1][y-1] == a[x][y]+1) 
	dp[x][y] = max(dp[x][y],dp[x+1][y-1]+1);
		if (x < n-1 && y < m-1) if (a[x+1][y+1] == a[x][y]+1) 
	dp[x][y] = max(dp[x][y],dp[x+1][y+1]+1);
		if (x < n-1 ) if (a[x+1][y] == a[x][y]+1) 
	dp[x][y] = max(dp[x][y],dp[x+1][y]+1);
	z = max(z,dp[x][y]);
	re;
	
}
void solve(int Case)
{
	cin >> n >> m;
	forn(i,0,n) forn(j,0,m) cin >> a[i][j];
	forn(i,0,n) forn(j,0,m) p[a[i][j]-'A'].pb({i,j});
	rofe(i,'Z','A') for(i2 u : p[i-'A']) check(u);
	cout << z+1 << "\n";
}

TACOSDECHASKA(ONLYONE);
//TEST
//ALL(n)
//ONLYONE
