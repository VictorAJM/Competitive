// Problem: N - Kompići
// Contest: Virtual Judge - Entrenamiento ICPC D (3)
// URL: https://vjudge.net/contest/460370#problem/N
// Memory Limit: 1572 MB
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
const int N=5e5+5;
const ld EPS = 1e-9;
ll n,a[N],h[N],x,res;
ll b[15];
ll P(ll u)
{
	forn(i,0,10) b[i] = 0;
	wh (u) {
		b[u%10] = 1;
		u /= 10;
	}
	ll x = 0;
	forn(i,0,10) if (b[i]) x += (1<<i);
	re x;
}
void solve(int Case)
{
	cin >> n;
	forn(i,0,n) cin >> a[i];
	forn(i,0,n) a[i] = P(a[i]);
	forn(i,0,n) h[a[i]]++;
	forn(i,0,(1<<10)) forn(j,i+1,(1<<10)) if (!!(i&j))res += h[i]*h[j];
	forn(i,0,(1<<10)) {
		x = h[i]*(h[i]-1);
		x /= 2;
		res += x;
	}
	cout << res;
}

TACOSDECHASKA(ONLYONE);
//TEST
//ALL(n)
//ONLYONE
