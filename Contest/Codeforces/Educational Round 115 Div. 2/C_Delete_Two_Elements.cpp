#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        long long sum = 0;
        for (int i=0;i<n;i++) sum += a[i];
        sum += sum;
        if (sum%n == 0) {
            sum /= n;
            map<int,int> h;
            long long res =0 ;
            for (int i=0;i<n;i++) {
                res += h[sum-a[i]];
                h[a[i]]++;
            }
            cout << res << "\n";
        } else cout << "0\n";
    }
}