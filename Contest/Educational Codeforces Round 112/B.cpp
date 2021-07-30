#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=0;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve()
{
    double W,H;
    double w,h,x1,x2,y1,y2;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    double p,q;
    p = W - x2 ;
    q = H - y2;
    double r = 1000000000.0;
    bool T = false;
    if ((y1 >= h) || (x1 >= w )) {
        cout << 0<<"\n";
        return;
    }
    if (x1 <= w) {
        if ((w-x1) <= p) {
            r = min(r,w-x1);
            T = true;
        }
    }
    if (y1 <= h) if ((h-y1) <= q) { T = true; r = min(r,h-y1);}
    if (!T) cout <<"-1\n";
    else cout <<r<<"\n";
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}