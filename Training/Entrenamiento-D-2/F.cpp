	// Problem: F - Interval Product
	// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
	// URL: https://vjudge.net/contest/457955#problem/F
	// Memory Limit: 1024 MB
	// Time Limit: 2000 ms
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
	int n,k,f[N],d[N],a[N];
	void add(int u,int cu)
	{
		while (u <= n) {
			f[u] += cu;
			u += u&(-u);
		}
		return;
	}
	bool t1 = false;
	void F(int u,int cu) 
	{
		while (u <= n) {
			d[u] += cu;
			u += u&(-u);
		}
		return;
	}
	int get(int u)
	{
		int r = 0;
		while (u) {
			r += f[u];
			u -= u&(-u);
		}
		return r;
	}
	int G(int u)
	{
		int r = 0;
		while (u) {
			r += d[u];
			u -= u&(-u);
		}
		return r;
	}
	void solve()
	{
		for (int i=0;i<n;i++) cin >> a[i];
		for (int i=0;i<=n;i++) f[i] = 0;
		for (int i=0;i<=n;i++) d[i] = 0;
		for (int i=0;i<n;i++){
			if (a[i] < 0) a[i] = -1;
			else if (a[i] > 0) a[i] = 1;
			if (a[i] == -1) add(i+1,1);
			if (a[i] == 0) F(i+1,1);
		}
		char x;
		int y,z;
		if (t1) ;
		t1 = true;
		while (k--) {
			cin >> x;
			if (x=='C') {
				cin >> y >> z;
				y--;
				if (z < 0) z = -1;
				else if (z > 0) z =	1;
				if (a[y] == -1) add(y+1,-1);
				if (a[y] == 0) F(y+1,-1);
				a[y] = z;
				if (a[y] == -1) add(y+1,1);
				if (a[y] == 0) F(y+1,1);
			} else {
				cin >> y >> z;
				int p = G(z) - G(y-1);
				if (p > 0) cout << "0";
				else {
					int q = get(z) - get(y-1);
					if (q%2==1) cout << "-";
					else cout << "+";
				}
			}
		}
		cout << "\n";
	}
	
	int main()
	{
	    fast_io;
	    while (cin >> n >> k) {
	    	solve();
	    }
	    return 0;
	}
	