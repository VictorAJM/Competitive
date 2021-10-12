    #include <iostream>
    using namespace std;
    const int maxn=1e6+5;
    struct SEGTREE {
        int izq,der,med;
    };
    string s;
    int m,a[maxn],b[maxn],n;
    SEGTREE ST[4*maxn];
    void ini(int node,int in,int fin)
    {
        if (in==fin) {
            if (s[in]=='(') { ST[node].izq=1; ST[node].med=ST[node].der=0; }
            if (s[in]==')') { ST[node].der=1; ST[node].med=ST[node].izq=0; }
            return;
        }
        int mid=(in+fin)/2;
        ini(node*2+1,in,mid);
        ini(node*2+2,mid+1,fin);
        int I,D,h;
        I=node*2+1; D=node*2+2;
        ST[node].med=ST[I].med+ST[D].med;
        h=min(ST[I].izq,ST[D].der);
        ST[node].med+=h*2;
        ST[node].izq=ST[I].izq+ST[D].izq-h;
        ST[node].der=ST[I].der+ST[D].der-h;
        return;
    }
    SEGTREE aux;
    void que(int node,int in,int fin,int x,int y)
    {
        if (fin<x || in>y) return;
        if (x<=in && fin<=y) {
            int h;
            h=min(aux.izq,ST[node].der);
            aux.med+=ST[node].med;
            aux.med+=2*h;
            aux.izq-=h;
            aux.izq+=ST[node].izq;
            aux.der+=ST[node].der;
            return;
        }
        int mid=(in+fin)/2;
        que(node*2+1,in,mid,x,y);
        que(node*2+2,mid+1,fin,x,y);
        return;
    }
    int main()
    {
        cin.tie(0); cout.tie(0);
        ios_base::sync_with_stdio(0);
        cin>>s>>m;
        for (int i=0;i<m;i++) cin>>a[i]>>b[i];
        n=s.size();
        ini(0,0,n-1);
        for (int i=0;i<m;i++) {
            a[i]--; b[i]--;
            aux.izq=aux.med=aux.der=0;
            que(0,0,n-1,a[i],b[i]);
            cout<<aux.med<<"\n";
        }
        return 0;
    }