#include <stdio.h>

int main(void) {
  //Escribe un algoritmo en C que genere la suma de los primero 100 
  // numeros impares
  int i=0, suma=0;
  while (i<100){
    if(i%2 != 0){
      suma=suma+i;
    }
    i++;
  }
  printf("suma de los primeros 100 numeros impares= %d", suma);
  return 0;
}
