// Problem: B - typo
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// Hasta donde tope

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
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define rofn(i,a,b) for (int i=(a);i>(b);i--) 
#define rofe(i,a,b) for (int i=(a);i>=(b);i--)

using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vi2;
typedef vector<ll> vl;
typedef pair<ll,ll> l2;
typedef long double ld;

const int mod=0;
const int N=0;
const ld EPS = 1e-9;

void precalc()
{

}
void solve(int Case)
{
	string a,b;
	cin >> a >> b;
	int n = sz(b);
	if (a==b) {
		cout << "Yes";
		return;
	}
	for (int i=0;i<n-1;i++) {
		swap(b[i],b[i+1]);
		if (a==b) {
			cout << "Yes";
			return;
		}
		swap(b[i],b[i+1]);
	}
	cout << "No";
}
int main()
{
    fast_io;
    precalc();
    int tt = 1, Case = 0;
    // cin >> tt;
    while (tt--) solve(++Case);
    return 0;
}