#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const long long mod=998244353;
const long long N=505;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
ll n,a[N];
map<ll,ll> h;
set<ll> s;
bool t[N];
bool primo(ll u)
{
    for (ll i=2;i*i<=u;i++) if (u%i==0) return false;
    return true;
}
vi g;
    map<ll,ll> d;
    set<ll> as;
void solve()
{
    cin >> n;
    for (ll i=0;i<n;i++) cin >> a[i];
    for (ll i=0;i<n;i++)if (a[i] != 1) {
        ll x = sqrt(a[i]);
        if (x*x == a[i]) {
            if (primo(x)) {
                h[x]+=2;
                s.insert(x);
            } else {
                ll y = sqrt(x);
                h[y]+=4;
                s.insert(y);
            }
        } else {
            ll z = cbrt(a[i]);
            if (z*z*z == a[i]) {
                h[z] += 3;
                s.insert(z);
            } else {
                g.push_back(a[i]);
            }
        }
    }
    // only pq
    
    ll nm = g.size();
    bool ty = true;
    while (ty) {
        ty = false;
        for (ll i=0;i<nm;i++) {
            for (ll u : s) {
                if (g[i]%u==0) {
                    h[u]++;
                    if (s.count(g[i]/u) == 0) {
                        ty = true;
                        s.insert(g[i]/u);
                    }
                    h[g[i]/u]++;
                    g[i] = 1;
                }
            }
        }
    }

    vi f;
    for (ll u : g) if (u>1) f.push_back(u);

    for (ll u : f) { as.insert(u); d[u]++; }
    g.clear();
    for (ll u : as) g.push_back(u);
    nm = g.size();
    ty = true;
                        set<ll> op;
    while (ty) {
        ty = false;
        for (ll i=0;i<nm;i++) {
            for (ll j=i+1;j<nm;j++) {
                ll x = __gcd(g[i],g[j]);
                if (x>1) {

                    op.insert(x);
                    op.insert(g[i]/x);
                    op.insert(g[j]/x);
                }
            }
        }
    }
    for (ll i=0;i<nm;i++) for (ll u : op) if (g[i]%u==0    ) h[u] += d[g[i]];
    for (ll i=0;i<nm;i++) for (ll u : op) if (g[i]%u==0) g[i] =1;
    ll res = 1ll;
    for (ll i=0;i<nm;i++) if (g[i] > 1) {
        d[g[i]]++;
        ll gps = d[g[i]]*d[g[i]];
        gps %= mod;
        res *= gps;
        res %= mod;
    }
    for (ii v : h) {
        v.S++;
        res *= v.S;
        res %= mod;
    }
    cout << res << endl;
    return ;
}

int main()
{
    fast_io;
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
