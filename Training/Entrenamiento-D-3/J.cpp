// Problem: J - Guess That Car!
// Contest: Virtual Judge - Entrenamiento ICPC D (3)
// URL: https://vjudge.net/contest/460370#problem/J
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
#define forn(i,a,b) for(long long i=(a);i<(b);i++)
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
const int N=1e3+5;
const ld EPS = 1e-9;
int n,m,a[N][N],d[N],s[N];
void solve(int Case)
{
	cin >> n >> m;
	fore(i,1,n) fore(j,1,m) cin >> a[i][j];
	fore(i,1,n) fore(j,1,m) s[i] += a[i][j];
	fore(j,1,m) fore(i,1,n) d[j] += a[i][j];
	ll p = 4e18;
	ll x = -1;
	ll q = 4e18;
	ll y = -1;
	fore(i,0,n) {
		ll res = 0;
		fore(j,1,n) {
			if (j==i+1 || j==i) {
				res += s[j]*(2ll)*(2ll);
			} else {
				if (j<i)res += s[j]*(4ll*abs(i-j)+2ll)*(4ll*abs(i-j)+2ll);
				else res += s[j]*(4ll*abs(i-j)-2ll)*(4ll*abs(i-j)-2ll);
			}
		}
		if (p > res) { p =res; x = i;}
	}
	fore(i,0,m) {
		ll res = 0;
		fore(j,1,m) {
			if (j==i+1 || j==i) {
				res += d[j]*(2ll)*(2ll);
			} else {
				if (j<i) res += d[j]*(4ll*abs(i-j)+2ll)*(4ll*abs(i-j)+2ll);
				else res += d[j]*(4ll*abs(i-j)-2ll)*(4ll*abs(i-j)-2ll);
			}
		}*
		if (q > res) { q =res; y = i;}
	}
	p += q;
	cout << p  << "\n";
	cout << x << " "<<y;
}

TACOSDECHASKA(ONLYONE);
//TEST
//ALL(n)
//ONLYONE
