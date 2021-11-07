#include <iostream>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=1e6+6;

typedef long long ll;

int nodos; // cantidad de nodos
int apunta[N]; // cada apunta[i] es el nodo al que apunta el nodo i
short estado[N]; // para marcar los nodos durante la dfs los marcamos con uno de 3 estados
// 0: No ha sido visitado
// 1: Ya lo hemos recorrido pero no por completo
// 2: Ya esta completamente visitado
int longitud[N]; // cantidad de espias a las que puede llegar el espia i
int momento[N]; // el momento en el tiempo en el que llegamos al nodo i
int tiempo; // variable que cuenta el tiempo en el que estamos
int tiempoCiclo; // al encontrar un ciclo, marcara el tiempo a partir del cual los nodos son parte del ciclo
int tamanoCiclo; // al encontrar el ciclo, contamos el tamaño del ciclo

void dfs(int nodo) // con esta funcion haremos la busqueda para calcular la respuesta iniciando en cada nodo
{
    estado[nodo] = 1; // cambiamos del estado 0 al 1
    momento[nodo] = tiempo; // en este momento llegamos al nodo actual por primera vez
    tiempo++; 
    int siguiente = apunta[nodo]; 
    if (estado[siguiente] == 0) {// el siguiente nodo no ha sido visitado
        // dfs(siguiente); // calculamos la l  ongitud del siguiente nodo
        if (momento[nodo] >= tiempoCiclo) { // si el momento del nodo actual es mayor a tiempoCiclo,
            longitud[nodo] = tamanoCiclo;   // este nodo pertene al ciclo
        } else { // en caso que no, tomamos la respuesta del siguiente nodo y le sumamos el nodo actual
            longitud[nodo] = longitud[siguiente] + 1;
            tiempoCiclo = 2e6+6; // marcamos el tiempo del ciclo como un numero grande para evitar problemas 
        }
    } else if (estado[siguiente] == 1) {
        tiempoCiclo = momento[siguiente]; // tomamos el tiempo del inicio del ciclo
        tamanoCiclo = tiempo - tiempoCiclo; // calculamos el tamaño del ciclo

        if (momento[nodo] >= tiempoCiclo) // sabemos que somos parte del ciclo
            longitud[nodo] = tamanoCiclo;

    } else { // el estado es 2
        longitud[nodo] = longitud[siguiente] + 1; // ya tenemos calculada la respuesta 
        // en el siguiente nodo, solo tomamos este precalculo y le sumamos el nodo actual
    }
    estado[nodo] = 2; // aqui ya obtuvimos la respuesta del nodo actual, cambiamos el estado a 2
    return;
}


int main()
{
    fast_io;
    cin >> nodos;
    for (int i=1;i<=nodos;i++) 
        cin >> apunta[i];

    for (int i=1;i<=nodos;i++) if (estado[i] == 0) { // si no ha sido visitado checamos este nodo
        dfs(i);
    }
    int respuesta = 0;
    for (int i=1;i<=nodos;i++) // tomamos la mayor respuesta posible entre todos los nodos
        respuesta = max(longitud[i],respuesta);

    cout << respuesta;
    return 0;
}