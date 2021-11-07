
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
typedef pair<i2,int> i3;
const int mod=0;
const int N=2e5+5;

void precalc()
{

}
int n,a[N],res[N];
i3 b[N];
void solve(int Case)
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    if (n%2==0) {
        for (int i=0;i<n;i+=2) {
            cout << a[i+1] << " ";
            ll x = a[i] * a[i+1];
            cout << a[i] * -1 << " " ;
        }
        cout << "\n";
        return;
    } else {
        map<int,int> h;
        for (int i=0;i<n;i++) { b[i].F.F = a[i]; b[i].F.S = 0; b[i].S = i; }
        for (int i=0;i<n;i++) h[b[i].F.F]++;
        for (int i=0;i<n;i++) {
            if (h[b[i].F.F]>1) b[i].F.S = 1;
            else b[i].F.S = 0;
        }
        sort(b,b+n,[&](i3 u,i3 v) {
            if (u.F.S > v.F.S) return false;
            return (u.F.F < v.F.F);
        });
        for (int i=0;i<n-1;i+=2) {
            res[b[i].S] = b[i+1].F.F;
            res[b[i+1].S] = b[i].F.F * -1;
        }
        if (b[n-1].F.S == 1) {
            int j = n-2;
            while (b[j].F.F != b[n-1].F.F) j--;
            if (res[b[j].S] != -1) {
                res[b[j].S]++;
                res[b[n-1].S] = -1;
            } else  {
                res[b[j].S]--;
                res[b[n-1].S] = 1;
            }
        } else {
           for (int i=0;i<n-1;i+=2) {
               res[b[i].S] = b[i+1].F.F;
               res[b[i+1].S] = b[i].F.F*-1;
           }
           if (res[b[n-2].S] != b[n-1].F.F) {
                res[b[n-2].S] -= b[n-1].F.F;
                res[b[n-1].S] = b[n-2].F.F;
           } else {
               res[b[n-2].S] += b[n-1].F.F;
               res[b[n-1].S] = b[n-2].F.F*-1;
           }
        }
        for (int i=0;i<n;i++) cout << res[i] << " " ;
        cout << "\n";
        return;
    }
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
