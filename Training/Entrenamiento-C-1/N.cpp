    #include <bits/stdc++.h>

    #define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    #define F first
    #define S second

    using namespace std;

    const int mod=1e9+7;
    const int N=3e5+5;

    typedef long long ll;
    typedef pair<int,int> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    int n,m,x[N],y[N];
    map<int,int> h;
    set<int> s;
    ll dp[N];
    vector<int> g[N];
    ll f[N];
    void solve()
    {
        cin >> n >> m;
        for (int i=0;i<m;i++) cin >> x[i] >> y[i];
        s.insert(n);
        s.insert(0);
        for (int i=0;i<m;i++) {s.insert(x[i]); s.insert(y[i]);}
        int _=1;for (int u : s) h[u] =_++;
        for (int i=0;i<m;i++) { x[i] = h[x[i]]; y[i] = h[y[i]]; }
        _--;
        dp[_] =1;
        for (int i=0;i<m;i++) g[x[i]-1].push_back(y[i]);
        for (int i=0;i<m;i++) f[y[i]-1]++;
        ll act=0;
        for (int i=_-1;i>=1;i--) {
            ll aux = f[i]*dp[i+1];
            aux %= mod;
            act += aux;
            act %= mod;
            for (int u : g[i]) {
                act -= dp[u];
                if (act < 0) act += mod; }
                act %= mod;
            dp[i] = act;
        }
        cout << dp[1];
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
