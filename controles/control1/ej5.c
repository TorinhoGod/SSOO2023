#include <stdio.h>

int main(void) {
  //Desarrollar un programa que solicite 4 notas en punto flotante por 
  //pantalla y se obtenga el promedio simple.
  float promedio, n1, n2, n3, n4;
  printf("Ingrese las 4 notas una por una cambiando con enter: \n");
  scanf("%f", &n1);
  scanf("%f", &n2);
  scanf("%f", &n3);
  scanf("%f", &n4);
  promedio=(n1+n2+n3+n4)/4;
  printf("promedio= %.2f;", promedio);
}
