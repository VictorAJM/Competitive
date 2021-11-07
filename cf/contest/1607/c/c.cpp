
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
const int N=2e5+5;
int n,a[N];
void precalc()
{

}
void solve(int Case)
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    if (n==1) {
        cout << a[0] << "\n";
        return;
    }
    sort(a,a+n);
    if (a[0] < 0) {
        int k = a[0] * -1;
        for (int i=0;i<n;i++) a[i] += k;
    }
    int x = 0;
    int res = 0;
    for (int i=0;i<n;i++) {
        res = max(res,a[i]-x);
        x = a[i];
    }
    cout << res << "\n";
}
int main()
{
    fast_io;
    precalc();
    int tt = 1, Case = 0;
    cin >> tt;
    while (tt--) solve(++Case);
    return 0;
}
