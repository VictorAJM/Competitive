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
int n,k,a[400005];
void solve()
{
    cin >> n >> k;
    for (int i=0;i<k;i++) cin >> a[i];
    sort(a,a+k,[&](int u,int v) {return (u > v); });
    int cnt = 0;
    for (long long i=0,j=0;i<k;i++) {
        if (a[i] > j) {
            cnt++;
            j += n-a[i];
        }
    }
    cout << cnt << "\n";
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
