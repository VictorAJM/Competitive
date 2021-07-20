#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod = 1e9+7;
const int N = 2e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,a[N],b[N],sum,p,q,k,acu;
void solve()
{
    k = sum = 0 ;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) cin >> b[i];
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++) sum += a[i];
    int gg = n/4;
    for (int i=1;i<=gg;i++) sum -= a[i];
    for (int i=1;i<=n;i++) sum -= b[i];
    for (int i=1;i<=gg;i++) sum += b[i];
    p = gg;
    while (sum < 0) {
        k++;
        bool t = false;
        if ((n+k)%4==0) {
            gg++;
            if (gg>n) {
                sum -= 100;
                sum += 0;
            } else {
                sum -= a[gg];
                if (p>0) sum += b[p];
                t = true;
            }
        }
        sum += 100;
        if (p>0) sum -= b[p];
        if (!t) p--;
    }
    cout << k << "\n";
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