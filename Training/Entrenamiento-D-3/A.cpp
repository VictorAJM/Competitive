// Problem: A - R2D2 and Droid Army
// Contest: Virtual Judge - Entrenamiento ICPC D (3)
// URL: https://vjudge.net/contest/460370#problem/A
// Memory Limit: 262 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<ll> vi;
typedef vector<i2> vii;
typedef vector<ll> vl;
typedef pair<ll,ll> l2;
typedef long double ld;

const int mod=0;
const int N=2e5+5e4+5;
const ld EPS = 1e-9;
const int INF = 1e9+9;

ll n,m,k,a[N][6],dp[N][19][6],p;
void precalc()
{
	
}
void solve(int Case)
{
	cin >> n >> m >> p;
	forn(i,0,n) forn(j,0,m) cin >> a[i][j];
	forn(i,0,n) fore(j,0,18) forn(k,0,m) dp[i][j][k] = 0;
	forn(i,0,n) forn(k,0,m) dp[i][0][k] = a[i][k];
	fore(j,1,18) forn(i,0,n)  forn(k,0,m) 
		dp[i][j][k] = max(dp[i][j-1][k],dp[i+(1<<(j-1))][j-1][k]);
	vi pp(m);
	forn(k,0,m) pp[k] = 0;
	ll ojo=0;
	forn(i,0,n) {
		vi res;
		forn(j,0,m) res.pb(0);
		ll pt = i;
		rofe(j,18,0) {
			vi comp;
			forn(k,0,m) comp.pb(res[k]);
			forn(k,0,m) comp[k] = max(comp[k],dp[pt][j][k]);
			ll x = 0;
			forn(k,0,m) x += comp[k];
			if (x <= p) {
				pt += (1<<j);
				pt = min(pt,n);
				//cerr << x << " ";
				forn(k,0,m) res[k] = comp[k];
			}
		}
		
		pt = min(n,pt);
		//cerr << pt << " "<<i << "\n";
		if (pt - i > ojo) {
			ojo = pt - i;
			//forn(k,0,m) cerr << res[k] << " ";
			//cerr << "\n";
			forn(k,0,m) pp[k] = res[k];
		}
	}
	for (ll u : pp) cout << u << " ";
}

int main()
{
	fast_io;
	precalc();
	int _t =1,_Case=0;
	//cin >> _t;
	while (_t--) solve(++_Case);
}
