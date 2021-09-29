
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
const int N=0;
const ld EPS = 1e-9;
ll c,r,s;
ll cuanto(ll a,ll b,ll d)
{
	ll k ;
	b %= d;
	k = b;
	if (a + b <= d) return 0;
	else {
		if (k>0) a -= d - k;
		a += d-1;
		return a/d;
	}
}
void solve(int Case)
{
	cin >> c >> r >> s;
	ll p = (r+c+s-1);
	p /= s;
	
	ll t = r+s-1;
	t /= s;
	
	p -= t;
		cout << p << " ";
		
	ll q = (r+c+s-1);
	q /= s;
	if (r >= q) cout << "0\n";
	else cout << q-r<<"\n";
}

TACOSDECHASKA(TEST);
//TEST
//ALL(n)
//ONLYONE
