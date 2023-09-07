#include <stdio.h>

int main(void) {
  /* Crear un algoritmo capaz de solicitar 3 notas de un estudiante por pantalla y obtener el promedio ponderado. Este promedio ponderado es de la siguiente forma:
Nota 1 = 40%
Nota 2 = 30%
Nota 3 = 30%
inferior a 3.95 se debe imprimir por pantalla que ha reprobado la asignatura, si obtuvo un promedio entre 3.95 a 4.94 el estudiante va a examen.
Si la nota es igual o superior a 4.95 el alumno se exime de la asignatura.*/
   float ponderado, n1, n2, n3, n4;
  printf("Ingrese las 4 notas una por una cambiando con enter: \n");
  scanf("%f", &n1);
  scanf("%f", &n2);
  scanf("%f", &n3);
  scanf("%f", &n4);
  ponderado=(n1*0.4)+(n2*0.3)+(n3*0.3);
  printf("promedio= %.2f; \n", ponderado);
  if(ponderado<3.95){
    printf("El alumno ha reprobado \n");
  }
  if(3.95<ponderado && ponderado<4.94){
    printf("El alumno va a examen \n");
  }
  if(ponderado>=4.95){
    printf("El alumno se exime");
  }
}
