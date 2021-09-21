// Problem: I - Counting Primes
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/I
// Memory Limit: 1572 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=2e4+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int Case,n,q,x,y,z,ty,o,p,a[N],st[4*N],lz[4*N],r;
bool P(int u)
{
	for (int i=2;i*i<=u;i++) if (u%i==0) return false;
	return true;
}
void get(int no,int i,int f)
{
	if (lz[no] != 0) {
		if (lz[no] == 1) st[no] = 0;
		else st[no] = f-i+1;
		if (i != f) {
			lz[no*2+1] = lz[no*2+2] = lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
	}
	if (f < x || i > y) return;
	if (x <= i && f <= y) {
		r += st[no];
		return;
	}
	int m = (i+f)/2;
	get(no*2+1,i,m); get(no*2+2,m+1,f);
	st[no] = st[no*2+1] + st[no*2+2];
	return;
}
void add(int no,int i,int f)
{
	if (lz[no] != 0) {
		if (lz[no] == 1) st[no] = 0;
		else st[no] = f-i+1;
		lz[no*2+1] = lz[no*2+2] = lz[no];
		lz[no] = 0;
	}
	if (f < x || i > y) return;
	if (x <= i && f <= y) {
		if (z==1) lz[no] = 2;
		else lz[no] = 1;
		if (lz[no] == 1) st[no] = 0;
		else st[no] = f-i+1;
		if (i != f) {
			lz[no*2+1] = lz[no*2+2] = lz[no];
			lz[no] = 0;
		} else lz[no] = 0;
		return;
	}
	int m = (i+f)/2;
	add(no*2+1,i,m); add(no*2+2,m+1,f);
	st[no] = st[no*2+1] + st[no*2+2];
	return;
}
void solve()
{
	cin >> n >> q;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<4*n;i++) st[i] = lz[i] = 0;

	for (int i=0;i<n;i++) if (P(a[i])){x=y=i; z=1; add(0,0,n-1);}

	cout << "Case "<<Case<<":\n";
	while (q--) {
		cin >> ty >> o >> p;
		if (ty==1) {
			r = 0;
			x = o-1; y = p-1;
			get(0,0,n-1);
			cout << r << "\n";
		} else {
			cin >> z;
			x = o-1; y = p-1;
			z = P(z);
			add(0,0,n-1);
		}
	}
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
    	++Case;
        solve();
    }
    return 0;
}
