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
	int n,a[N],dp[N][23];
		set<int> s[N];
	void solve(int Case)
	{
		forn(i,0,n) cin >> a[i];
		forn(i,0,n+1) s[i].clear();
		a[n] = -1;
		fore(i,0,20) dp[n][i] = -1;
		//watch(dp[n][0]);
		rofe(i,n-1,0) {
			dp[i][0] = min(a[i],a[i+1]);
			fore(j,1,20) {
				if (i+(1<<j) >= n) dp[i][j] = -1;
				else dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
				//watch(dp[i][j]);
			}
		}
		int res = 0;
		forn(i,0,n) if (a[i] > 0){
			int  p = i;
			rofe(j,20,0) if (dp[p][j] >= a[i]) p += (1<<j);
			p++;
			//watch(p);
			res -= sz(s[p]);
			s[p].insert(a[i]);
			res += sz(s[p]);
		}
		cout <<"Case "<<Case<<": "<< res << "\n";
		re;
	}
	
	TACOSDECHASKA(ALL(n));
	//TEST
	//ALL(n)
	//ONLYONE
	