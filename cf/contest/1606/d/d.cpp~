
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
const int N=0;

void precalc()
{

}
int n,m;
vector<vector<int>> a,b;
bool check(int u)
{
    int x = -1,y = -1,X = -1,Y = -1;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        if (j <= u) {
            if (b[i][u] == 1) {
                x = min(x,a[i][j]);
            } else {
                y = min(y,a[i][j]);
            }
        } else {
            if (b[i][u] == 1) {
                X = max(X,a[i][j]);
            } else {
                Y = max(Y,a[i][j]);
            }
        }
    }
    if (x > Y  && Y > y) return true;
    else return false;
}
void solve(int Case)
{
    cin >> n >> m;
    a.assign(n,vector<int>(m,0));
    b.assign(n,vector<int>(m,0));
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
    for (int i=0;i<n;i++) {
        int x = -1;
        int y = 1000000000;
        for (int j=0;j<m;j++) if (a[i][j] < y) { x = j; y = a[i][j]; }
        b[i][x] = 2;
        y = -10000;
        x = -1;
        for (int j=0;j<m;j++) if (a[i][j] >= y) { x = j; y = a[i][j]; }
        b[i][x] = 1;
    }
    for (int i=0;i<m-1;i++) {
        int t = 0;
        for (int j=0;j<n;j++) {
            if (b[j][i] == 1 || b[j][i] == 2) t++;
        }
        if (t==n) {
            if (check(i)) {
                cout << "YES\n";
                for (int j=0;j<n;j++) {
                    if (b[j][i] == 1) cout <<"R";
                    else cout << "B";
                }
                cout << " "<<i+1<<"\n";
                return;
            } 
        }
    }
    cout <<"NO\n";
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
