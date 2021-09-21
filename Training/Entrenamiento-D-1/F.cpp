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
map<ll,ll> h;
bool t[N];
vi g;
long long mysqrt(long long x) {
  assert(x > 0);
  long long y = (long long) (sqrtl((long double) x) + 0.5);
  while (y * y < x) {
    y++;
  }
  while (y * y > x) {
    y--;
  }
  if (y * y == x) {
    return y;
  }
  return -1;
}
 
long long mycrt(long long x) {
  assert(x > 0);
  long long y = (long long) (powl((long double) x, 1.0 / 3.0) + 0.5);
  while (y * y * y < x) {
    y++;
  }
  while (y * y * y > x) {
    y--;
  }
  if (y * y * y == x) {
    return y;
  }
  return -1;
}
void solve()
{
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    long long d = mycrt(a);
    if (d != -1) {
      h[d] += 3;
      continue;
    }
    long long b = mysqrt(a);
    if (b != -1) {
      long long c = mysqrt(b);
      if (c != -1) {
        h[c] += 4;
      } else {
        h[b] += 2;
      }
    } else {
      g.push_back(a);
    }
  }
    n = g.size();
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (g[i] != g[j]) {
        ll pp = __gcd(g[i],g[j]);
        if (pp>1) {
            h[pp] = h[pp];
        }
    }
    ll res = 1;
    vi se;
    for (auto v : h) se.push_back(v.F);
    for (int i=0;i<n;i++) {
        bool xs = false;
        for (auto v : se) {
            if (g[i]%v == 0) {
                h[v]++;
                h[g[i]/v]++;
                xs = true;
                break;
            }
        }
        if (!xs) {
            h[g[i]]--;
        }
    }
    for (auto v : h) {
        if (v.S > 0) {
                ll aux = 1 + v.S;
                res *= aux;
                res %= mod;
         } else {
             ll aux = 1 - v.S;
             res *= aux;
             res %= mod;
             res *= aux;
             res %= mod;
             
        }
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
