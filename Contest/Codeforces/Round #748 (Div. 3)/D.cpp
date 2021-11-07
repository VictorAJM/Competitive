#include <bits/stdc++.h>
#define F first
#define S second
#define watch(x) cerr << #x << " " << x << "\n";
#define sz(a) (int)a.size()

using namespace std;

const int MOD = 0;
const int N = 0;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vi2;
int n,a[45];
void solve()
{
    cin >> n ;
    for (int i=0;i<n;i++) cin >> a[i];
    int y=-1;
    int z = *min_element(a,a+n);
    if (z<0) for (int i=0;i<n;i++) a[i] -= z;
    bool t = true;
    for (int i=0;i<n-1;i++) if (a[i] != a[i+1]) t = false;
    if (t==1) {cout << "-1\n"; return 0; }
    for (int i=1;i<=2000000;i++) {

    }
    cout << y << "\n";
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
