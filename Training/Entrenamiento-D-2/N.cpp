// Problem: N - RMQ with Shifts
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/N
// Memory Limit: 1024 MB
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
int st[4*N],a[N],n,q,res;
string s;
void ini(int node,int i,int f)
{
	if (i == f) {
		st[node] = a[i];
		return;
	}
	int m = (i+f)/2;
	ini(node*2+1,i,m);
	ini(node*2+2,m+1,f);
	st[node] = min(st[node*2+1],st[node*2+2]);
	return;
}
void que(int no,int i,int f,int p1,int p2)
{
	if (f < p1 || i > p2) return;
	if (p1 <= i && f <= p2) {
		res = min(st[no],res);
		return;
	}
	int m = (i+f)/2;
	que(no*2+1,i,m,p1,p2);
	que(no*2+2,m+1,f,p1,p2);
	return;
}
void upd(int no,int i,int f,int p1)
{
	if (i == f) {
		st[no] = a[p1];
		return;
	}
	int m = (i+f)/2;
	if (p1 <= m) {
		upd(no*2+1,i,m,p1);
	} else {
		upd(no*2+2,m+1,f,p1);
	}
	st[no] = min(st[no*2+1],st[no*2+2]);
	return;
}
void query(string r)
{
	int p = 6;
	vi data;
	while (p < r.size()) {
		int a = 0;
		while (p < r.size() && '0'<= r[p] && r[p] <= '9') {
			a *= 10;
			a += r[p]-'0';
			p++;
		}
		p++;
		a--;
		data.push_back(a);
	}
	res = 2e5+5;
	que(0,0,n-1,data[0],data[1]);
	cout << res  << "\n";
}
void shift(string r)
{
	int p = 6;
	vi data;
	while (p < r.size()) {
		int a = 0;
		while (p < r.size() && '0'<= r[p] && r[p] <= '9') {
			a *= 10;
			a += r[p]-'0';
			p++;
		}
		p++;
		a--;
		data.push_back(a);
	}
	for (int i=1;i<data.size();i++) {
		swap(a[data[i]],a[data[i-1]]);
	}
	for (int u : data) upd(0,0,n-1,u);
	return;
}
void solve()
{
	cin >> n >> q;
	for (int i=0;i<n;i++) cin >> a[i];
	ini(0,0,n-1);
	while (q--) {
		cin >> s;
		if (s[0]=='q') {
			query(s);
		} else {
			shift(s);
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
