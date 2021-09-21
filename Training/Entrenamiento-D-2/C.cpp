// Problem: C - Sad powers
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/C
// Memory Limit: 262 MB
// Time Limit: 2000 ms
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
set<int> s;
void m(ll u,ll i)
{
	ll pq = i;
	int  p =1;
	while (pq <= u) {
		s.insert(pq);
		pq *= i;
	} 
}
ll P(ll u)
{
	ll res = 0;
	if (u==0) return 0;
	res += sqrt(u);
	for (int i=2;i<=1000000;i++) {
		int k = m(u,i);
	}
	res += s.size();
	return res;
}
void solve()
{
	ll x,y;
	cin >> x >> y;
	x--;
	x = P(x);
	s.clear();
	y = P(y);
	cout << y - x << "\n";
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    dp[1] = 1;
    for (int i=2;i<=64;i++) dp[i] = div(i);
    while (t--) {
        solve();
    }
    return 0;
}
