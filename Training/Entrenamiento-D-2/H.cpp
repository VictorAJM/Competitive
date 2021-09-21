// Problem: H - Halt The War
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/H
// Memory Limit: 1572 MB
// Time Limit: 301 ms
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
ll n,q,Case,st[4*N],lz[4*N],x,y,r;
string s;
void get(int no,int i,int f)
{
	if (lz[no] > 0 ){
		st[no] += lz[no]*(f-i+1);
		if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
		}
		lz[no] = 0;
	}
	if (f < x || i > y) return;
	if (x <= i && f <= y) {
		//cout << no << " "<<st[no] <<"\n";
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
	if (lz[no] > 0 ){
		st[no] += lz[no]*(f-i+1);
		if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
		}
		lz[no] = 0;
	}
	if (f < x || i > y) return;
	if (x <= i && f <= y) {
		
		lz[no]++;
	//	cout << st[no];
		st[no] += lz[no]*(f-i+1);
		//cout << lz[no]*(f-i+1) << st[no];
		if (i != f) {
			lz[no*2+1] += lz[no];
			lz[no*2+2] += lz[no];
		}
		
		lz[no] = 0;
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
	cout << "Scenario #"<<Case<<":\n";
	for (int i=0;i<4*n;i++) st[i] = lz[i] = 0;
	while (q--) {
		cin >> s >> x >> y;
		if (s[0]=='a') {
			r = 0;
			get(0,1,n);
			cout << r << "\n";
		} else { //cout << x << " "<<y<< " ";
			add(0,1,n);
			cout << "OK\n";
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
