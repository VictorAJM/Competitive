
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
const int N=205;
const ld EPS = 1e-9;
int n,a[N],s;
bool p(int u)
{
    for (int i=2;i*i<=u;i++) if (u%i==0) return true;
    return false;
}
void solve(int Case)
{
    cin >> n;
    s=0;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) s += a[i];
    if (!p(s)) {
        for (int i=0;i<n;i++) if (p(s-a[i])) {
            cout << n-1 << "\n";
            for (int j=1;j<=n;j++) if (j != i+1) cout << j <<  " ";
            cout << "\n";
            return ;
        }
        for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (p(s-a[i]-a[j])) {
            cout << n-2 << "\n";
            for (int k=1;k<=n;k++) if (k != i+1 && k != j+1) cout << k <<  " ";
            cout << "\n";
        }
    } else {
        cout << n << "\n";
        for (int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
        return ;
    }
}
int main()
{
    fast_io;
  //  precalc();
    int tt = 1, Case = 0;
    cin >> tt;
    while (tt--) solve(++Case);
    return 0;
}