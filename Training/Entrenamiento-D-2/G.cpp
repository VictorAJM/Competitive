// Problem: G - Potentiometers
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/G
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
typedef vector<int> vi;
typedef vector<ii> vii;
int cas,n;
string s;
int st[4*N],x,y,a[N],r;
void ini(int no,int i,int f)
{
	if (i == f) {
		st[no] = a[i];
		return;
	}
	int m = (i+f)/2;
	ini(no*2+1,i,m);
	ini(no*2+2,m+1,f);
	st[no] = st[no*2+1] + st[no*2+2];
	return;
}
void get(int no,int i,int f)
{
	if (f < x || i > y) return;
	if (x <= i && f <= y) {
		r += st[no];
		return;
	}
	int m = (i+f)/2;
	get(no*2+1,i,m); get(no*2+2,m+1,f);
	return;
}
void upd(int no,int i,int f)
{
	if (f < x || i > x) return;
	if (i == f) {
		st[no] = a[i] = y;
		return;
	}
	int m = (i+f)/2;
	upd(no*2+1,i,m); upd(no*2+2,m+1,f);
	st[no] = st[no*2+1] + st[no*2+2];
	return; 
}
void solve()
{
	for (int i=0;i<n;i++) cin >> a[i];
	ini(0,0,n-1);
	if (cas > 1) cout << "\n";
	cout << "Case "<<cas<<":\n";
	do {
		cin >> s;
		if (s != "END") {
			cin >> x >> y;
			x--;
			if (s[0] == 'M') {
				y--;
				r = 0;
				get(0,0,n-1);
				cout << r << "\n";
			} else {
				upd(0,0,n-1);
			}
		}
	} while (s != "END");
	return;
}

int main()
{
    fast_io;
    cin >> n;
    while (n > 0) {
    	cas++;
    	solve();
    	cin >> n;
    }
    return 0;
}
