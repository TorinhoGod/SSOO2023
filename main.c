/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_USUARIOS 5

// Recursos compartidos
sem_t lugar_disponible, seleccionar_sabor_sem, decidir_hielo_sem;
pthread_mutex_t mutex_sabor, mutex_hielo;

// Función para simular la selección del sabor
void seleccionar_sabor(int usuario_id) {
    int sabor;
    pthread_mutex_lock(&mutex_sabor);
    printf("Usuario %d: Seleccione el sabor (1 - Manzana, 2 - Naranja, 3 - Uva):\n", usuario_id);
    scanf("%d", &sabor);
    switch (sabor) {
        case 1:
            printf("Usuario %d: Sabor seleccionado: Manzana.\n", usuario_id);
            break;
        case 2:
            printf("Usuario %d: Sabor seleccionado: Naranja.\n", usuario_id);
            break;
        case 3:
            printf("Usuario %d: Sabor seleccionado: Uva.\n", usuario_id);
            break;
        default:
            printf("Usuario %d: Opción no válida. Sabor predeterminado: Manzana.\n", usuario_id);
    }
    pthread_mutex_unlock(&mutex_sabor);
    sem_post(&decidir_hielo_sem);
}

// Función para simular la decisión sobre el hielo
void decidir_hielo(int usuario_id) {
    int decision_hielo;
    sem_wait(&decidir_hielo_sem);
    pthread_mutex_lock(&mutex_hielo);
    printf("Usuario %d: ¿Desea agregar hielo? (1 - Sí, 0 - No):\n", usuario_id);
    scanf("%d", &decision_hielo);
    if (decision_hielo == 1) {
        printf("Usuario %d: Hielo agregado.\n", usuario_id);
    } else {
        printf("Usuario %d: Sin hielo.\n", usuario_id);
    }
    pthread_mutex_unlock(&mutex_hielo);
}

// Función para simular el proceso de hacer jugo
void *hacer_jugo(void *arg) {
    int usuario_id = *(int *)arg;

    sem_wait(&lugar_disponible); // Esperar por un lugar disponible

    printf("Usuario %d: Colocando el vaso.\n", usuario_id);
    sleep(1); // Simulación de colocar el vaso

    seleccionar_sabor(usuario_id);
    decidir_hielo(usuario_id);

    printf("Usuario %d: Sirviendo el jugo.\n", usuario_id);
    sleep(1); // Simulación de servir el jugo

    sem_post(&lugar_disponible); // Liberar el lugar

    printf("Usuario %d: Jugo listo. Saliendo.\n", usuario_id);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_USUARIOS];
    int ids[NUM_USUARIOS];

    // Inicialización de semáforos y mutex
    sem_init(&lugar_disponible, 0, 2); // Dos lugares disponibles
    sem_init(&seleccionar_sabor_sem, 0, 0);
    sem_init(&decidir_hielo_sem, 0, 0);
    pthread_mutex_init(&mutex_sabor, NULL);
    pthread_mutex_init(&mutex_hielo, NULL);

    // Crear hilos para representar usuarios que solicitan jugo
    for (int i = 0; i < NUM_USUARIOS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, hacer_jugo, &ids[i]);
        sleep(1); // Añadir un pequeño retraso entre la creación de hilos
    }

    // Esperar a que los hilos terminen
    for (int i = 0; i < NUM_USUARIOS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destruir semáforos y mutex
    sem_destroy(&lugar_disponible);
    sem_destroy(&seleccionar_sabor_sem);
    sem_destroy(&decidir_hielo_sem);
    pthread_mutex_destroy(&mutex_sabor);
    pthread_mutex_destroy(&mutex_hielo);

    return 0;
}


