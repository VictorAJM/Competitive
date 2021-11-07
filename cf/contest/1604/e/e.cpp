
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

const int mod=998244353;
const int N=2e5+5;
int n,a[N];
void precalc()
{

}
ll h(ll u, ll v)
{
    ll aux = 0;
    while (u > v*2) {
        aux++;
        u -= v;
    }
    aux++;
    return aux;
}
ll g(ll u, ll v)
{
    while (u > v*2) {
        u -= v;
    }
    return u/2;
}
void solve(int Case)
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    ll ans = 0;
    for (int i=0;i<n;i++) {
        // here we check 
        ll x = a[i];
        ll res = 0;
        for (int j=i-1;j>=0;j--)  {
        if (a[j] > x) {
            res += h(a[j],x);
            x = g(a[j],x);
            
            ans += res;
            ans %= mod;
        } else {
            x = a[j];
            ans += res;
            ans %= mod;
        }        
        cout <<res << " ";
        } 
        cout << "\n";
    }
    cout << ans << "\n";
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