// aun no termino este

#include <stdio.h>

int main() {
    /*Realizar un programa que solicite por teclado los valores de dos matrices de 2x2, y mostrar el resultado de la suma de las dos matrices por pantalla.*/
    int i, j, a, b, x, y;
    int matriz1[2][2], matriz2[2][2], suma[2][2];
    // INGRESA MATRIZ 1
    printf("Ingresa los valores para la matriz 1 (presionando enter para agregar nueva) \n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&matriz1[i][j]);
        }
    }
    printf("\n\n La matriz ingresada es:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }
    //MATRIZ 2
    printf("\nIngresa los valores para la matriz 2 (presionando enter para agregar nueva) \n");
    for(a=0;a<2;a++){
        for(b=0;b<2;b++){
            scanf("%d",&matriz2[a][b]);
        }
    }
    printf("\n La matriz ingresada es:\n");
    for(a=0;a<2;a++){
        for(b=0;b<2;b++){
            printf("%d ", matriz2[a][b]);
        }
        printf("\n");
    }
    //SUMAR LAS MATRICES
    for(x=0;x<2;x++){
        for(y=0;y<2;y++){
            suma[x][y]=matriz1[i][j]+matriz2[a][b];
            printf("%d + %d = %d \n", matriz1[i][j], matriz2[a][b], suma[x][y]);
        }
    }
    printf("\nLa suma de las matrices es: \n");
    for(x=0;x<2;x++){
        for(y=0;y<2;y++){
            printf("%d ", suma[x][y]);
        }
        printf("\n");
    }
    return 0;
}
