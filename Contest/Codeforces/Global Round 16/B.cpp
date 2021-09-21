#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=2e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
string s,r;
bool b[N];int n,cnt;
void solve()
{  
    cin >> n;
    cin >> s >> r;
    n = s.size();
    cnt=0;
for (int i=0;i<n;i++) b[i] = true;
    for (int i=0;i<n;i++) {
        if (s[i]=='0' & r[i] == '0') cnt++;
        if (s[i]=='0' && r[i]=='1') {b[i] = false;cnt += 2;}
        if (s[i]=='1' && r[i]=='0') {b[i] = false;cnt += 2;}
       
    } 

    for (int i=0;i<n-1;i++) {
        int a,c;
        a=c=0;
        if (s[i]=='0' || r[i]=='0' || s[i+1]=='0' || r[i+1]=='0') a=1;
        if (s[i]=='1' || r[i]=='1' || s[i+1]=='1' || r[i+1]=='1') c=1;
        if (b[i] && b[i+1] && a==1 && c==1)cnt++;
        if (b[i] && b[i+1] && a==1 && c==1) b[i] = b[i+1] = false;
    }
    cout << cnt << "\n";
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
