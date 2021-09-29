// Problem: F. Array Stabilization (AND version)
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/F
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
const int N=1e6+5;
const ld EPS = 1e-9;
int n,d,a[N],res[N];
bool s[N];
void solve(int Case)
{
	cin >> n >> d;
	forn(i,0,n) cin >> a[i];
	forn(i,0,n) s[i] = 0;
	queue<i2> q;
	forn(i,0,n) if (a[i] == 0) q.push({i,0});
	wh (!q.empty()) {
		i2 x = q.front();
		q.pop();
		if (!s[x.F]){ 
		s[x.F] = 1;
		res[x.F] = x.S;
		x.S++;
		x.F += d;
		x.F %= n;
		q.push(x); }
	} 
	forn(i,0,n) if (!s[i]) {cout << "-1\n"; re;}
	int x=0;
	forn(i,0,n) x = max(x,res[i]);
	cout << x << "\n";
}

TACOSDECHASKA(TEST);
//TEST
//ALL(n)
//ONLYONE
