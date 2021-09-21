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
    int n;
    string s;
    void solve()
    {
        cin >> n;
        cin >> s;
        for (int i=0;i<n;i++) if (s[i] == 'U') s[i] = 'D'; else if (s[i]=='D') s[i] = 'U';
        cout << s<<"\n";
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
     
     