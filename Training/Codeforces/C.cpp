// Problem: J - Horrible Queries
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/J
// Memory Limit: 1572 MB
// Time Limit: 2329 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=1e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
ll n,q,a,b,c,d;
ll r=0;
vi st,lz;
void add(ll no,ll i,ll f)
{

	if (f < b || i > c) {
		st[no] += lz[no]*(f-i+1);
			if (i != f) {
			ll m = (i+f)/2;
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	if (b <= i && f <= c) {
		ll kk = d * (f-i+1);
		lz[no] += d;
		st[no] += lz[no]*(f-i+1);
		if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	ll m = (i+f)/2;
	st[no] += lz[no]*(f-i+1);
	lz[no*2+1] += lz[no];
	lz[no*2+2] += lz[no];
	lz[no] = 0;
	add(no*2+1,i,m);
	add(no*2+2,m+1,f);
	st[no] = st[no*2+1] + st[no*2+2];
	return;
}
void get(ll no,ll i,ll f)
{
	if (f < b || i > c) {
		st[no] += lz[no]*(f-i+1);
			if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	if (b <= i && f <= c) {
		st[no] += lz[no]*(f-i+1);
		r += st[no];
		if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	ll m = (i+f)/2;
	st[no] += lz[no]*(f-i+1);
	lz[no*2+1] += lz[no];
	lz[no*2+2] += lz[no];
	lz[no] = 0;
	get(no*2+1,i,m);
	get(no*2+2,m+1,f);
	st[no] = st[no*2+1] + st[no*2+2];
	return;
}
void solve()
{
	
	cin >> n >> q;
		st.assign(4*n+5,0);
	lz.assign(4*n+5,0);
	for (int i=0;i<n;i++) {
		b=c=i;
		cin >> d;
		add(0,0,n-1);
	}

	while (q--) {
		cin >> a >> b >> c;
		if (a==0) cin >> d;
		if (a==0) {
			b--;
			c--;
			add(0,0,n-1);
			} else {
			r = 0;
			b--;
			c--;
			get(0,0,n-1);
			cout << r << "\n";
		}
	}
}

int main()
{
    fast_io;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
