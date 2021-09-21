// Problem: M - A Famous City
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/M
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
const int N=0;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve()
{
	for (int i=0;i<n;i++) cin >> a[i];
	set<int> s;
	map<int,int> h;
	for (int i=0;i<n;i++) s.insert(a[i]);
	s.insert(0);
	for (int u : s) h[u] = q++;
	for (int i=0;i<n;i++) a[i] = h[a[i]];
	for (int i=0;i<=q;i++) nt[i] = -1;
	for(int i=n-1;i>=0;i--) {
		p[a[i]] = nt[a[i]];
		nt[a[i]] = i;
	}
	
}

int main()
{
    fast_io;
    while (cin >> n) {
    	solve();
    }
    return 0;
}
