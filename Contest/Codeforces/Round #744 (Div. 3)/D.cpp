// Problem: D. Productive Meeting
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/D
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
const int N=2e5+5;
const ld EPS = 1e-9;
int n,a[N];
priority_queue<i2> pq;
void solve(int Case)
{
	cin >> n;
	forn(i,0,n) cin >> a[i];
	forn(i,0,n) if (a[i] > 0 )pq.push({a[i],i});
	vii res;
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		if (!pq.empty()) {
			auto y = pq.top();
			pq.pop();
			res.pb({x.S+1,y.S+1});
			x.F--; y.F--;
			if (x.F > 0)pq.push(x);if (y.F>0) pq.push(y);
		}
	}
	cout << sz(res) << "\n";
	for (auto u : res) cout << u.F << " "<<u.S <<"\n";
}

TACOSDECHASKA(TEST);
//TEST
//ALL(n)
//ONLYONE
