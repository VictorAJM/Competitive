#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=105;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int a,b,c,d,n,p[N],x,y,t;
char m[N][N];
void solve()
{
    cin >> a >> b >> c >> d >> n;
    for (int i=0;i<n;i++) cin >> p[i];
    y = a+c;
    x = d;
    t = c%2;
    if (c%2==0) x = 1;
    for (int i=0;i<n;i++) while (p[i]--) {
        m[x][y] = 'a'+i;
        if (t==0) {
            x++;
            if (y>a) {
                if (x>d) {
                    x = d;
                    y--;
                    t = 1;
                }
            } else {
                if (x>b) {
                    x = b;
                    y--;
                    t = 1;
                }
            }
        } else {
            x--;
            if (x==0) {
                x=1;
                y--;
                t = 0;
            }
        }
    }
    cout << "YES\n";
    for (int i=1;i<=max(b,d);i++) {
        for (int j=1;j<=a+c;j++) {
            if (j<=a) {
                if (i>b) cout <<".";
                else cout << m[i][j];
            } else {
                if (i>d) cout << ".";
                else cout << m[i][j];
            }
        }
        cout << "\n";
    }
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
