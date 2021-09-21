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
map<ll,ll> h;
ll n,u,v,w,ty,k;
ll M(ll a)
{
    ll x = 1;
    while (x <= a) x *= 2;
    x /= 2;
    return x;
}
void meter(ll a,ll b,ll c)
{
    if (a>b) swap(a,b);
    while (M(b) > M(a)) {
        h[b]+=c;
        b /= 2;
    }
    while (a != b) {
        h[a] += c;
        h[b] += c;
        a /= 2;
        b /= 2;
    }
    
    return;
}
void contar(ll a,ll b)
{
    if (a>b) swap(a,b);
    while (M(b) > M(a)) {
        k += h[b];
        b /= 2;
    }
    while (a != b) {
        k += h[a];
        k += h[b];
        a /= 2;
        b /= 2;
    }
    
    return;
}
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> ty;
        cin >> u >> v;
        if (ty==1) cin >> w;
        if (ty==1) {
            meter(u,v,w);
        } else {
            k=0;
            contar(u,v);
            cout << k << "\n";
        }
    }
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
