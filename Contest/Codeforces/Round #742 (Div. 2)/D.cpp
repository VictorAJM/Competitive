#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=4e5+5;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
ll x,y;
ll w(ll u)
{
    ll hh = 1;
    while (hh < u) hh *= 10;
    hh /= 10;
    if (hh==0) hh=1;
    return hh;  
}
ll q(ll u)
{
        ll hh = 1;
    while (hh <= u) hh *= 10;
    hh /= 10;

    return hh;  
}
ll p(ll u) 
{
    return u - w(u);
}
void solve()
{
    vi res;
    cin >> x >> y;
    while (y) {
        if (y==1) {
            res.push_back(x);
            x=0;
            y--;
        } else {
            if (y-1 <= x - q(x)) {
                res.push_back(q(x));
                x -= q(x);
                y--;
            } else if (y-1 <= p(x)){
                res.push_back(w(x));
                x -= w(x);
                y--;
                } else {
                vi aux;
                for (ll i=0;i<y;i++) {
                    aux.push_back(x/y);
                }
                x %= y;
                for (ll i=0;i<x;i++) aux[i]++;
                for (ll u : aux) res.push_back(u);
                y = 0;
            }
        }
    }
    for (ll u : res) cout << u << " ";
    cout << "\n";
}

int main()
{
    fast_io;
    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
