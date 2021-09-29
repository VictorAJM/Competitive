// Problem: G. Minimal Coverage
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int N=2e5+54;
const ld EPS = 1e-9;
int n,a[N],f[N];
void add(int u,int m)
{
	wh (u <= m) {
		f[u]++;
		u += u&(-u);
	}
	re;
}
int get(int u) 
{
	int r = 0;
	wh (u) {
		r += f[u];
		u -= u&(-u);
	}
	re r;
}
void solve(int Case)
{
	cin >> n;
	forn(i,0,n) cin >> a[i];
	map<int,int> h;
	int q=1; 
	set<int> s;
	forn(i,0,n) s.insert(a[i]);
	for (int u : s) h[u] = q++;
	forn(i,0,n) a[i] = h[a[i]];
	fore(i,0,q) f[i] = 0;
	ll cnt = 0;
	forn(i,0,n) {
		int x = get(a[i]-1);
		int y = get(q) - get(a[i]);
		add(a[i],q);
		cnt += min(x,y);
	}
	cout << cnt << "\n";
}

TACOSDECHASKA(TEST);
//TEST
//ALL(n)
//ONLYONE
