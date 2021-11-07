#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
struct Matrix {
    int n,m;
    vector<vector<int>> a;
    Matrix() { }
    Matrix(int _n, int _m) { n = _n; m = _m; a.assign(n, vector<int>(m,0)); }
    Matrix(vector<vector<int> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }

    inline void make_unit() {
        assert(n == m);
        for (int i=0;i<n;i++) 
            for (int j=0;j<n;j++) 
                a[i][j] = (i==j);
    }
    inline Matrix operator + (const Matrix &b) {
        assert(n == b.n && m == b.m);
        Matrix matrix = Matrix(n,m);
        for (int i=0;i<n;i++) 
            for (int j=0;j<m;j++) 
                matrix.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
        return matrix;
    }
    inline Matrix operator - (const Matrix &b) {
        assert(n == b.n && m == b.m);
        Matrix matrix = Matrix(n,m);
        for (int i=0;i<n;i++) 
            for (int j=0;j<m;j++)
                matrix.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
        return matrix;
    }
    inline Matrix operator * (const Matrix &b) {
        assert(m == b.n);
        Matrix matrix = Matrix(n,b.m);
        for (int i=0;i<n;i++) 
            for (int j=0;j<b.m;j++)
                for (int k=0;k<m;k++) 
                    matrix.a[i][j] = (matrix.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
        return matrix;
    }
    inline Matrix pow(long long k) {
        assert(n == m);
        Matrix matrix(n,n), matrixPower = a; matrix.make_unit();
        while (k) {
            if (k & 1) matrix *= matrixPower;
            matrixPower *= matrixPower;
            k >>= 1;
        }
        return matrix;
    }
    inline Matrix& operator += (const Matrix& b) { return *this = (*this) + b; }
    inline Matrix& operator -= (const Matrix& b) { return *this = (*this) - b; }
    inline Matrix& operator *= (const Matrix& b) { return *this = (*this) * b; }
    inline bool operator == (const Matrix& b) { return a == b.a; }
    inline bool operator != (const Matrix& b) { return a != b.a; }
};


int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    Matrix matrix(n,m);
    for (int i=0;i<n;i++) 
        for (int j=0;j<k;j++)
            cin >> matrix.a[i][j];
    Matrix matrix2(m,k);
    for (int i=0;i<n;i++) 
        for (int j=0;j<k;j++)
            cin >> matrix2.a[i][j];
    Matrix matrixProduct = matrix * matrix2;
    for (int i=0;i<n;i++) {
        for (int j=0;j<k;j++) 
            cout << matrixProduct.a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
