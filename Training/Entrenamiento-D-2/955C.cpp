// Problem: C. Sad powers
// Contest: Codeforces - Codeforces Round #471 (Div. 2)
// URL: https://codeforces.com/problemset/problem/955/C
// Memory Limit: 256 MB
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
vl pot;
int n;
ll L,R;

ll Mysqrt(ll u){
    ll a = 0;
    ll b = u;
    while (a < b) {
        ll m = (a+b)/2;
        if (m < u/m) a = m+1;
        else b = m;
    }
    if (u==0) re 0;
    //watch(a);
    if (a > u/a) re a-1;
    else if (a*a == u) re a;
    else re a;
}
bool p[1000005];
void precalc()
{
	fore(i,2,1000000) if (Mysqrt(i)*Mysqrt(i) == i) p[i] = true;
	set<ll> s;
	fore(i,2,1000000) {
		if (!p[i]) {
			ll b=1;
			ll c=0;
			wh (b <= 1000000000000000000ll) {
				b *= i;
				c++;
				if (c%2==1 && c > 1) s.insert(b);
				if (b > 1000000000000000000ll/i) break;
			}
		}
	}
	for (ll u : s) pot.pb(u);
}
ll P(ll u)
{
	ll k = Mysqrt(u);
	ll a = -1; 
	rofe(i,20,0) {
		wh ((1<<i)+a < sz(pot) &&  pot[(1<<i)+a]<=u) a += (1<<i);
	}
	re a+k;
}
void solve(int Case)
{
	cin >> L >> R;
	watch(P(R)); watch(P(L-1));
	cout << P(R) -P(L-1) << "\n";
}

int main()
{
	fast_io;
	precalc();
	TEST;
	re 0;
}
//TEST
//ALL(n)
//ONLYONE
