
#include <bits/stdc++.h>
#define usar using
#define nombreespacio namespace
#define entero int
#define largo long
#define caracter char
#define principal main
#define lee cin
#define imprime cout
#define regresa return
#define para for
#define si if
#define mientras while
#define hacer do
#define boleano bool
#define rompe break
#define doble double
#define continuar continue
#define tamDe sizeof
#define sinsigno unsigned 
#define constante const
#define sino else
#define corto short
#define Estructura struct
#define Cola queue
#define Pila stack
#define ColaDePrioridad  priority_queue
#define Par pair
#define primero first
#define segundo second
#define empuja push
#define quita pop
#define atras back
#define empujaAtras push_back
#define frente front
#define empujaFrente push_front
#define ordena sort
#define siguientePermutacion next_permutation
#define intercambia swap
#define estandar std
#define inicio begin
#define fin end
#define rInicio rbegin
#define rFin rend
#define todo(x) x.inicio(),x.fin()
#define todoReversa(x) x.rInicio(),x.rFin()
#define tupla tuple
#define mapa map
#define lista list
#define conjunto set
#define BiCola deque
#define tama size
#define tam(x) (entero)x.tama()
#define plantilla template
#define operador operator

usar nombreespacio estandar;

entero principal()
{   
    entero n;
    Par<entero,entero> par[10003];
    Cola<entero> cola[1003];
    lee >> n;
    para (entero i = 0 ; i < n ; i++){
        entero a,b;
        lee >> a >> b;
        par[i].primero = a;
        par[i].segundo = b;
    }
    para (entero i=0;i<n;i++) {
        entero a,b,c;
        lee >> a >> b >> c;
        cola[i].empuja(a);
        cola[i].empuja(b);
        si (b==0) cola[i].quita();
        cola[i].empuja(c);
    }
    regresa 0;
}



