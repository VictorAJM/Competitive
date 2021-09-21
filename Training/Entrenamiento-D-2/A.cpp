// Problem: A - MegaFactorialDiv2
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=1e9+9;
const int N=0;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class MegaFactorialDiv2{
	public:
		int countDivisors(int _n,int _k) {
			n = _n; 
			k = _k;
			solve();
		}
		vi primes;
int dp[1005][105][1005];
bool v[1005][105][1005];
int n,k;
bool sieve[1005];
void Sieve(int m)
{
	for (int i=2;i<=m;i++) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (int j=i;j<=m;j+=i) sieve[j] = true;
		}
	}
}
int G(int u,int v)
{
	int r = 0;
	while (u%v==0) {
		r++;
		u /= v;
	}
	return r;
}
ll V(int q,int w,int e)
{
	if (v[q][w][e]) return dp[q][w][e];
	v[q][w][e] = true;
	if (w==0) {
		dp[q][w][e] = G(q,e);
		return dp[q][w][e];
	} 
	if (q==0) {
		dp[q][w][e] = 0;
		return 0;
	}
	dp[q][w][e] = V(q-1,w,e) + V(q,w-1,e);
	return dp[q][w][e];
}
void solve()
{
	Sieve(max(n,k));
	ll res = 1;
	for (int u : primes) {
		ll ff = V(n,k,u);
		ff++;
		res *= ff;
		res %= mod;
	}
	cout << res;
	}
}
