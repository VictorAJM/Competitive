
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
const int N=105;
const ld EPS = 1e-9;
int n,k[N],p[N],nt[N];
void precalc()
{

}
void solve(int Case)
{
    cin >> n;
    for (int i=1;i<=n;i++) {
        cout << "? ";
        for (int j=1;j<=n;j++) if (j==i) cout << "2 ";
        else cout << "1 ";
        cout << endl;
        cin >> k[i];
    }
    for (int i=1;i<=n;i++) {
        cout << "? ";
        for (int j=1;j<=n;j++) if (j==i) cout << "1 ";
        else cout << "2 ";
        cout << endl;
        cin >> p[i];
    }
    for (int i=1;i<=n;i++) {
        if (k[i] == 0) nt[i] = 0;
        else if (k[i] < i) nt[i] = k[i];
    }

    for (int i=1;i<=n;i++) {
        if (p[i] == 0) nt[0] = i;
        else if (p[i] < i) nt[p[i]] = i;
    }    
    int x = nt[0];
    cout << "! ";
    int y=1;
    do {
        p[x] = y;
        y++;
        x = nt[x];
    } while (x != 0);
    for (int i=1;i<=n;i++) cout << p[i] <<  " ";
    cout << endl;
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
