
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
string s;
void solve(int Case)
{
    cin >> n >> m;
    cin >> s;
    int x,y,X,Y; x=y=X=Y=0;
    int p,q; p = q = 0;
    for (int i=0;i<s.size();i++) {
        int a,b,c,d;
        a = x; b = y; c = X; d = Y;
        if (s[i] == 'R') {
            p++;
            X = max(X,p);
        }  else if (s[i] == 'L') {
            p--;
            x = min(x,p);
        } else if (s[i] == 'D') {
            q++;
            Y = max(Y,q);
        } else {
            q--;
            y = min(y,q);
        }
        if (X-x >= m || Y-y >= n) {
            i = s.size();
cout << abs(b)+1 << " " << abs(a) + 1 <<" " << i+1 << "\n";
            return;
        } 
    }
    cout << abs(y)+1 << " " << abs(x) + 1 << " "<< s.size()<<"\n";
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
