// Problem: C. Ticks
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/C
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
#define forn(i,a,b) for (int i=(a);i<(b);i++)
#define fore(i,a,b) for (int i=(a);i<=(b);i++)
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
const int N=22;
const ld EPS = 1e-9;
int n,m,k;
char a[N][N];
bool vs[N][N];
int che(int u,int v)
{
	int x = 1;
	if (u>0 && v > 0&& a[u-1][v-1] == '*') x = max(x,1+che(u-1,v-1));
	re x;
}
int eck(int u,int v)
{
	int x = 1;
	if (v+1<m && u>0&& a[u-1][v+1] == '*') x = max(x,1+eck(u-1,v+1));
	re x;
}
int check(int u,int v)
{
	if (a[u][v] != '*') re 0;
	int x = 10000;
	if (u>0 && v > 0 && a[u-1][v-1] == '*') x = min(x,che(u-1,v-1));
	else x = 0;
	if (v+1<m && u>0&& a[u-1][v+1] == '*') x = min(x,eck(u-1,v+1));
	else x = 0;
	if (x==10000) re 0;
	re x;
}
void paint(int u,int v,int cc,int dir)
{
	if (cc>=0) {
		vs[u][v] = true;
		if (dir==-1) {
			if (u>0 && v > 0 && a[u-1][v-1] == '*') paint(u-1,v-1,cc-1,dir);
			re;
		} else {
			if (v+1<m && u>0&& a[u-1][v+1] == '*')paint(u-1,v+1,cc-1,dir);
			re;
		}
	}else re;
}
void solve(int Case)
{
	cin >> n >> m >> k;
	forn(i,0,n) forn(j,0,m) cin >> a[i][j];
	forn(i,0,n) forn(j,0,m) vs[i][j] = 0;
	forn(i,0,n) forn(j,0,m) if (a[i][j] == '*'){
		int p = check(i,j);
		cerr << p << "\n";
		if (p>=k)vs[i][j] |= 1;
		if (p>=k) {paint(i,j,p,-1); paint(i,j,p,1); }
	
	}
	forn(i,0,n) forn(j,0,m) if (a[i][j] == '*' && !vs[i][j]) {
		cout << "No\n";
		re;
	}
	cout << "Yes\n";
	re;
}

TACOSDECHASKA(TEST);
//TEST
//ALL(n)
//ONLYONE
