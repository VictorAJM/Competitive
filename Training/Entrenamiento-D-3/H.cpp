// Problem: H - Maximum Sum
// Contest: Virtual Judge - Entrenamiento ICPC D (3)
// URL: https://vjudge.net/contest/460370#problem/H
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
const int N=1e5+5;
const ld EPS = 1e-9;
i2 st[4*N];
int n,q,a[N],l,r,x,y;
char z;
void ini(int no,int i,int f)
{
	if (i==f) {
		st[no].F = a[i];
		re;
	}
	int m = (i+f)/2;
	ini(no*2+1,i,m); ini(no*2+2,m+1,f);
	vi ojo;
	ojo.pb(st[no*2+1].F);ojo.pb(st[no*2+1].S);
	ojo.pb(st[no*2+2].F);ojo.pb(st[no*2+2].S);
	sort(all(ojo), [&](int u,int v){re u > v;});
	st[no].F = ojo[0];
	st[no].S = ojo[1];
	re;
}
void get(int no,int i,int f)
{
	if (i > r || f < l) re;
	if (l <= i && f <= r) {
		vi ojo;
		ojo.pb(st[no].F);ojo.pb(st[no].S);
		ojo.pb(x); ojo.pb(y);
		sort(all(ojo), [&](int u,int v){re u > v;});
		x = ojo[0]; y = ojo[1];
		re;
	}
	int m = (i+f)/2;
	get(no*2+1,i,m); get(no*2+2,m+1,f);
}
void upd(int no,int i,int f)
{
	if (i > l || f < l) re;
	if (i==f) {
		st[no].F = r;
		re;
	}
	int m = (i+f)/2;
	upd(no*2+1,i,m); upd(no*2+2,m+1,f);
	vi ojo;
	ojo.pb(st[no*2+1].F);ojo.pb(st[no*2+1].S);
	ojo.pb(st[no*2+2].F);ojo.pb(st[no*2+2].S);
	sort(all(ojo), [&](int u,int v){re u > v;});
	st[no].F = ojo[0];
	st[no].S = ojo[1];
	re;
}
void solve(int Case)
{
	cin >> n;
	forn(i,0,n) cin >> a[i];
	cin >> q;	
	ini(0,0,n-1);
	while (q--) {
		cin >> z >> l >> r;
		--l; 
		if (z=='Q') {
			x = 0;
			y = 0;
			--r;
			get(0,0,n-1);
			cout << x+y << "\n";
		} else {
			upd(0,0,n-1);
		}
	}
}

TACOSDECHASKA(ONLYONE);
//TEST
//ALL(n)
//ONLYONE
