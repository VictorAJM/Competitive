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
typedef pair<l2,ll> l3;
const int mod=0;
const int N=2e5;
const ld EPS = 1e-9;

ll a[N],n,m,cnt[N],sum,res[N],p;
l3 b[N];
void solve(int Case)
{
	cin >> n;
	forn(i,0,n) cin >> a[i];
	sort(a,a+n);
	cin >> m;
	forn(i,0,m) {cin >> b[i].F.F >> b[i].F.S; b[i].S = i; }
	sort(b,b+m);
	forn(i,0,n) sum += a[i];
	forn(i,0,n) cnt[i] = sum - a[i];
	forn(i,0,m) {
		wh (p+1<n && a[p] < b[i].F.F) p++;
		ll k = max(0ll,b[i].F.F-a[p]) + max(b[i].F.S-cnt[p],0ll);
		if (p>0) {
			ll l = max(0ll,b[i].F.F-a[p-1]) + max(b[i].F.S-cnt[p-1],0ll);
			k = min(k,l);
		}
		res[b[i].S] = k;
	}
	forn(i,0,m) cout << res[i] << "\n";
}

TACOSDECHASKA(ONLYONE);
//TEST
//ALL(n)
//ONLYONE
