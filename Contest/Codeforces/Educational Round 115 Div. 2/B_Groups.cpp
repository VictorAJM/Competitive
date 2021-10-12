#include <bits/stdc++.h>
using namespace std;
int dp[7],dd[7][7],a[7],n,t;
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int j=0;j<5;j++) dp[j] = 0;
        for (int j=0;j<5;j++) for (int k=j+1;k<5;k++) dd[j][k] = 0;
        for (int i=0;i<n;i++) {
            
            for (int j=0;j<5;j++) cin >> a[j];
            for (int j=0;j<5;j++) dp[j] += a[j];
            for (int j=0;j<5;j++) for (int k=j+1;k<5;k++) if (a[j] && a[k]) dd[j][k]++;
        }
        bool can = false;
        for (int j=0;j<5;j++) for (int k=j+1;k<5;k++) {
            int x = dp[j] - dd[j][k];
            int y = dp[k] - dd[j][k];
            if (x+y+dd[j][k] == n && x <= n/2 && y <= n/2) {
                can = true;
            }
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}