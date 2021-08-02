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

ll n,m,a,d,f,c; // declaramos las variables como en la descripcion del problema

ll mcm(ll x,ll y) 
{
    return x*y/__gcd(x,y);
}

void solve()
{
    cin >> n >> m;
    cin >> a >> d;
    cin >> f >> c;
    ll fila = f;
    ll pasosFilas = 0;
    do {
        pasosFilas++;
        fila += a;
        fila %= n;
        if (fila == 0) fila += n;
    } while (fila != f); // con este do while y 2 variables locales, 
    // contamos el tiempo que toma regresar a la posicion original

    ll columna = c;
    ll pasosColumna = 0;
    do {
        pasosColumna++;
        columna += d;
        columna %= m;
        if (columna == 0) columna += m;
    } while (columna != c); // mismo procedimiento para las columnas

    ll respuesta = mcm(pasosFilas,pasosColumna); 
    // el menor tiempo en el que estos 2 valores concurren es su maximo comun multiplo
    cout << respuesta;
    return;

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