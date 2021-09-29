// Problem: D. The Strongest Build
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int N=12;
const ld EPS = 1e-9;

set<vl> s;
int n,m,b[100005][N],a[N][200005],c[N];
ll ojito(vl caca)
{
	ll ret = 0;
	forn(i,0,sz(caca)) ret += a[i][caca[i]];
	re ret;
}
void solve(int Case)
{
	cin >> n;
	forn(i,0,n) {
		cin >> c[i];
		fore(j,1,c[i]) cin >> a[i][j];
	}
	cin >> m;
	forn(i,0,m) forn(j,0,n) cin >> b[i][j];
	forn(i,0,m) {
		vl x;
		forn(j,0,n) x.pb(b[i][j]);
		s.insert(x);
	}
	vl res;
	forn(i,0,n) res.pb(c[i]);
	vl rere;
	if (s.count(res) == 0) {
			for (int u : res) cout << u << " ";
			exit(0);
	}
	forn(i,0,m) {
		vl x;
		forn(j,0,n) {
			x.clear();
			forn(k,0,n) if (k != j) x.pb(b[i][k]);
						else if (b[i][k]>1) x.pb(b[i][k]-1);
			if (sz(x) == n && s.count(x) == 0)
				if (ojito(x) > ojito(rere)) rere = x; 
		}
		forn(j,0,n) {
			x.clear();
			forn(k,0,n) if (k != j) x.pb(b[i][k]);
						else if (b[i][k]<c[k]) x.pb(b[i][k]+1);
			if (sz(x) == n && s.count(x) == 0) 
				if (ojito(x) > ojito(rere)) rere = x; 
		}
	}  
	for (int u : rere) cout << u << " ";
	re;
}

TACOSDECHASKA(ONLYONE);
//TEST
//ALL(n)
//ONLYONE
