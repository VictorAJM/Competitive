
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
const int N=0;

void precalc()
{

}
ll a[15],b[15];
void solve(int Case)
{
    long long n,k;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    k++;
    for (int i=0;i<n;i++) b[i] = 0;
    for (int i=0;i<n-1;i++) {
        ll di = a[i+1] - a[i];
        ll  dif = 1ll;
        while (di--) dif *= 10;
        dif--;
        if (dif <= k) {
            b[i] = dif;
            k -= dif;
        } else {
            b[i] = k;
            k = 0;
        }
    }
    if (k>0) b[n-1] = k;
    for (int i=n-1;i>=0;i--) if (b[i] > 0) cout << b[i];
    cout << "\n";
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
