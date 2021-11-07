
// Hasta donde tope

                                            
//    _____  _                  _           
//   /  __ \| |                | |          
//   | /  \/| |__    __ _  ___ | | __  __ _ 
//   | |    | '_ \  / _` |/ __|| |/ / / _` |
//   | \__/\| | | || (_| |\__ \|   < | (_| |
//    \____/|_| |_| \__,_||___/|_|\_\ \__,_|
//                                            
//                                            

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
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

const int mod=0;
const int N=5e5+5;

void precalc()
{

}
int n,m;
i2 a[N];
void solve(int Case)
{
	cin >> n >> m;
	for (int i=0;i<n;i++) cin >> a[i].F >> a[i].S;
	sort(a,a+n,[&](i2 u, i2 v) {
		if (v.F > u.S) { return true; }
		if (v.S < u.F) return false;
		return (u.S < v.S);
	});
	int cnt = 0;
	for (int i=0;i<n;i++) {
		if (a[i].F < m) continue;
		cnt++;
		m = max(m,a[i].S);
	}
	cout << cnt << "\n";
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