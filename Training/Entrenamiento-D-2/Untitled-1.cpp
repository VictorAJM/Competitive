

#include <stdio.h>

int main() {
  unsigned int x;
  char* p;
  scanf("%i",&x);
  // Vea lo que dice el compilador si quita (char*)
  // de la siguiente línea
  p = (char*)&x; 
  printf("%c%c%c%c",p[0],p[1],p[2],p[3]);
  return 0;
}