
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
const int N=2e5+5;

void precalc()
{

}
void solve(int Case)
{

}
int n,a[N];
bool b[N],res[N],c[N];
int main()
{
    fast_io;
    cin >> n;
    for (int i=0;i<n;i++) 
        cin >> a[i];
    int i=0;
    while (i<n) {
        int j = i;
        while (j+1<n && a[j+1] > a[j]) j++;
        for (int p=0;p<=500;p++) b[p] = 0;
        b[0] = 1;
        for (int k=j;k>=i;k--) {
            for (int p=0;p<=500;p++) if (b[p] && (p^a[k])<=500) { c[p] = c[p^a[k]] = 1; }
            for (int p=0;p<=500;p++) {
                b[p] = c[p];
                c[p] = 0;
            }
        }
        for (int p=0;p<=500;p++) res[p] |= b[p];
        i = j+1;
    }
    int cnt = 0;
    for (int p=0;p<=500;p++) if (res[p]) cnt++;
    cout << cnt << "\n";
    for (int p=0;p<=500;p++) if (res[p]) cout << p << " ";
    return 0;
}
