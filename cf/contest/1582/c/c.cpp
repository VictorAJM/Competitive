
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
void solve(int Case)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = 0;
    int q = n-1;
    while (p<=q && s[p] == s[q]) p++,q--;
    char x,y;
    if (p>q) {
        cout <<"0\n";
        return;
    }
    x = s[p]; y = s[q];
    int r1,r2;
    r1 = r2 = 0;
    int a1,a2;
    a1 = p; a2 = q;
    while (a1 <= a2) {
        if (s[a1] == s[a2]) {
            a1++; a2--;
        } else {
            if (s[a1] == x) {
                r1++;
                a1++;
            } else if (s[a2] == x) {
                r1++;
                a2--;
            } else {
                r1 = 10000000;
                a1 = a2+1;
            }
        }
    }
    a1 = p; a2 = q;
    r2 = r1;
    r1 = 0;
    x = y;
    while (a1 <= a2) {
        if (s[a1] == s[a2]) {
            a1++; a2--;
        } else {
            if (s[a1] == x) {
                r1++;
                a1++;
            } else if (s[a2] == x) {
                r1++;
                a2--;
            } else {
                r1 = 10000000;
                a1 = a2+1;
            }
        }
    }
    r2 = min(r2,r1);
    if (r2==10000000) cout << "-1\n";
    else cout << r2 <<"\n";
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
