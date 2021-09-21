// Problem: K - Light Switching
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/K
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
const int N=1e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,q,t,a,b,r;
int st[4*N],lz[4*N];
void upd(int no,int i,int f)
{
	if (lz[no]) {
		st[no] = (f-i+1) - st[no];
		lz[no*2+1] ^= lz[no];
		lz[no*2+2] ^= lz[no];
		lz[no] = 0;
	}
	if (f < a || i > b) return;
	if (a <= i && f <= b) {
		st[no] = (f-i+1) - st[no];
		if (i != f) {
			lz[no*2+1] ^= 1;
			lz[no*2+2] ^= 1;
		}
		return;
	}
	int m = (i+f)/2;
	upd(no*2+1,i,m); upd(no*2+2,m+1,f);
	st[no] = st[no*2+1] + st[no*2+2];
}
void get(int no,int i,int f)
{
	if (lz[no]) {
		st[no] = (f-i+1) - st[no];
		lz[no*2+1] ^= lz[no];
		lz[no*2+2] ^= lz[no];
		lz[no] = 0;
	}
	if (f < a || i > b) return;
	if (a <= i && f <= b) {
		r += st[no];
		return;
	}
	int m = (i+f)/2;
	get(no*2+1,i,m); get(no*2+2,m+1,f);
	st[no] = st[no*2+1] + st[no*2+2];
}
void solve()
{
	cin >> n >> q;
	while (q--) {
		cin >> t >> a >> b;
		if (t==0) {
			upd(0,1,n);
		} else {
			r = 0;
			get(0,1,n);
			cout << r << "\n";
		}
	}
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
