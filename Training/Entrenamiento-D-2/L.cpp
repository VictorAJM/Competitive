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
const int N=2e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

ll n,q,a,b,d,aa[N];
char c;
ll r=0;
vi st,lz;


void add(ll no,ll i,ll f)
{

	if (f < a || i > b) {
		st[no] += lz[no];
			if (i != f) {
			ll m = (i+f)/2;
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	if (a <= i && f <= b) {
		ll kk = d ;
		lz[no] += d;
		st[no] += lz[no];
		if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	ll m = (i+f)/2;
	st[no] += lz[no];
	lz[no*2+1] += lz[no];
	lz[no*2+2] += lz[no];
	lz[no] = 0;
	add(no*2+1,i,m);
	add(no*2+2,m+1,f);
	st[no] = min(st[no*2+1] , st[no*2+2]);
	return;
}


void get(ll no,ll i,ll f)
{
	if (f < a || i > b) {
		st[no] += lz[no];
			if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	if (a <= i && f <= b) {
		st[no] += lz[no];
		//cout << st[no] << " ";
		r = min(r,st[no]);
		if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	ll m = (i+f)/2;
	st[no] += lz[no];
	lz[no*2+1] += lz[no];
	lz[no*2+2] += lz[no];
	lz[no] = 0;
	get(no*2+1,i,m);
	get(no*2+2,m+1,f);
	st[no] = min(st[no*2+1] , st[no*2+2]);
	return;
}


void ini(int no,int i ,int f)
{
	if (i == f) {
		st[no] = aa[i];
		return;
	}
	int m = (i+f)/2;
	ini(no*2+1,i,m);
	ini(no*2+2,m+1,f);
	st[no] = min(st[no*2+1] , st[no*2+2]);
}
ll ojo(string ua)
{
	int j = 0;
	ll re=0;
	while (ua[j] ==' ') j++;
	bool tt = false;
	if (ua[j] == '-') {j++;tt = true;}
	while (j < ua.size() &&'0'<= ua[j] &&ua[j] <= '9') {
		re *= 10;
		re += ua[j] -'0';
		j++;
	}
	if (tt) re *= -1ll;
	return re;
}
void solve()
{
	
	cin >> n;
	for (int i=0;i<n;i++) cin >> aa[i];
	st.assign(4*n+5,0);
	lz.assign(4*n+5,0);
	ini(0,0,n-1);
	cin >> q;
	c=' ';
	d=-1;
	while (q--) {
		cin >> a >> b;
		string s;
		getline(cin,s);
		
		if (s.size()>0) {
			d = ojo(s);
			//cout << a << b << " ";
			if (a <= b) {
				add(0,0,n-1);
			} else {
				int x = b;
				b = n-1;
				add(0,0,n-1);
				b = x;
				a = 0;
				add(0,0,n-1);
			}
			} else {
				// get
		
				
			r = 1e18;
			if (a <= b) {
				get(0,0,n-1);
				cout << r << "\n";
			} else {
				int x = b;
				b = n-1;
				get(0,0,n-1);
				b = x;
				a = 0;
				get(0,0,n-1);
				cout << r << "\n";
			}
		}
	}
}

int main()
{
    fast_io;
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}