#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=2e6+6;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int nodos; // cantidad de nodos
int apunta[N]; // cada apunta[i] es el nodo al que apunta el nodo i
int estado[N]; // para marcar los nodos durante la dfs los marcamos con uno de 3 estados
// 0: No ha sido visitado
// 1: Ya lo hemos recorrido pero no por completo
// 2: Ya esta completamente visitado
int longitud[N]; // cantidad de espias a las que puede llegar el espia i

stack<int> pila; // pila para marcar los ciclos

void dfs(int nodo) // 
{
    pila.push(nodo);
    estado[nodo] = 1;
    int siguiente = apunta[nodo];
    if (estado[siguiente] == 0) {// el siguiente nodo no ha sido visitado
        dfs(siguiente); // calculamos la longitud del siguiente nodo
        longitud[nodo] = longitud[siguiente] + 1; // tenemos la longitud del nodo actual 
    } else if (estado[siguiente] == 1) {

    } else { // el estado es 2

    }
}

void solve()
{
    cin >> nodos;
    for (int i=1;i<=nodos;i++) 
        cin >> apunta[i];

    for (int i=1;i<=nodos;i++) if (estado[i] == 0) { // si no ha sido visitado checamos este nodo
        dfs(i);
    }
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