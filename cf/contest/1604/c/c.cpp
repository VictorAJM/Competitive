
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

const int mod=1e9+7;
const int N=3e5+5;
ll cc[505],k;
ll n,a[N];
void precalc()
{
    cc[0] = 1;
    for (ll i=1;i<=7000;i++) {
        cc[i] = cc[i-1]*(i+1);
        cc[i] /= __gcd(cc[i-1],i+1);
        if (cc[i] >= mod) { k = i; i = 7005+1; }
    }
}
void solve(int Case)
{
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++) {
        if (i>=k) {
            cout << "YES\n";
            return;
        }  else {
            if (a[i]%cc[i] == 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
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