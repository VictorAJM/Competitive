
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

#define TEST int tt,Case=0; cin >> n; cin >> tt; wh (tt--) solve(++Case); 
#define ALL(n) int Case=0; wh (cin >> n) solve(++Case);
#define ONLYONE int Case=0; solve(++Case);


using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vii;
typedef vector<ll> vl;
typedef pair<ll,ll> l2;
typedef long double ld;

const int mod=0;
const int N=505;
const int M = 2e4+4;
const ld EPS = 1e-9;

int dp[M],A,T,hh[N],d[N],t[N];
vi g[N];
vii pos[M];
i2 p[505][12];
int main()
{
	fast_io;
	cin >> A >> T;
	forn(i,0,A) {
		cin >> hh[i] >> d[i] >> t[i];
		forn(j,0,t[i]) {
			int x;
			cin >> x;
			g[i].pb(x);
		}
	}
	set<int> s;
	map<int,int> h;
		int q = 0;
	s.insert(T);
	forn(i,0,A) {
		forn(j,0,t[i]) {
			s.insert(g[i][j]);
			s.insert(g[i][j]+d[i]);
		}
	}

	for (int u : s) h[u] = q++;
	forn(i,0,A) forn(j,0,t[i]) {
		p[i][j].F = h[g[i][j]];
		p[i][j].S = h[g[i][j] + d[i]];
	}
	forn(i,0,A) forn(j,0,t[i]) {
		pos[p[i][j].F].pb({p[i][j].S,hh[i]});
		//cerr << p[i][j].F << " "<<p[i][j].S << " "<<hh[i] <<"\n";
	}
	rofe(i,q,0) {
		dp[i] = dp[i+1];
		while (!pos[i].empty()) {
			auto x = pos[i][sz(pos[i])-1];
			pos[i].pop_back();
			dp[i] = max(dp[i],x.S + dp[x.F]);
		}
	}
	cout << dp[0] << "\n";
}
