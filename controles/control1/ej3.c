int main(void) {
  /* Desarrollar un programa que sea capaz de determinar si un triángulo es equilátero, escaleno o isósceles, según sus lados (valores enteros) que serán ingresados por teclado por
el usuario. */
  int l1,l2,l3;
  printf("Ingrese las medidas de lados del triangulo, ingrese nuevos con     enter\n");
  scanf("%d",&l1);
  scanf("%d",&l2);
  scanf("%d",&l3);
  if(l1==l2 && l1==l3){
    printf("Es equilatero");
  }else{
    if(l1==l2 || l1==l3 || l2==l3){
      printf("Es isoceles");
    }else{
      printf("Es escaleno");
    }
  }  
  
}
