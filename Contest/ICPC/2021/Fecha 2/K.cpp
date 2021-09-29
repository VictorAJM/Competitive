
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

#define TACOSDECHASKA(n) int main() {fast_io; precalc(); n; return 0;}
using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vii;
typedef vector<ll> vl;
typedef pair<ll,ll> l2;
typedef long double ld;

const int mod=1e9+7;
const int N=1e6+5;
const ld EPS = 1e-9;
ll a[N],b[N];
void precalc()
{
	ll cnt=0;
	a[1] = 2; 
	ll p = 4;
	for (int i=2;i<=1000000;i++) {
		a[i] = p;
		p *= 2;
		p %= mod;
	}
	for (int i=1;i<=1000000;i++) {
		a[i] = a[i] - b[i];
		for (int j=i+i;j<=1000000;j+=i) {b[j] += a[i]; b[j] %= mod; }
	}
}
void solve(int Case)
{
	ll k;
	cin >> k;
	k = b[k];
	if (k < 0) k += mod;
	cout << k << "\n";
}

TACOSDECHASKA(TEST);
//TEST
//ALL(n)
//ONLYONE
