// Problem: D - Zeroes
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/D
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
const int N=0;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll a,b;
void solve()
{
	ll p,q;

	p = q = 0;
	do {
		b /= 5;
		q += b;
		b = 0;
	} while (b > 0);
	if (a < 5) p = -1;
	else {
		a -= a%5;
		a--;
	}
	do {
		a /= 5;
		p += a;
		a = 0;
	} while (a > 0);
	cout << q - p << "\n";
}

int main()
{
    fast_io;
    cin >> a >> b;
    while (a != 0 && b != 0) {
    	solve();
    	cin >> a >> b;
    }
    return 0;
}
