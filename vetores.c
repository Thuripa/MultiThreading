/*
Realize uma implementação em sua linguagem de preferência de algoritmo de ordenação de vetores
Bubble sort. O vetor deverá ser de pelo menos 200 posições e deverá ser comparado um sistema
singlethread com um sistema multithread (com pelo menos 2 threads). Além disso, a ordenação deverá
ser na ordem crescente (do maior para o menor) e o vetor de valores deve ser iniciado do maior para o
menor (descrente) não importando o valor das posições, desde que respeita essa regra. Isso gerará o
pior caso de uso do bubble sort.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

// Declara vetor
int vetor[3000];

// Valores de tempo
double tempo1, tempo2;

// Single Thread
void bubblesort_single_thread() {

    tempo1 = (double) clock();            /* Captura tempo inicial */
    tempo1 = tempo1 / CLOCKS_PER_SEC;      /*  Converte em segundos */
    bool swap = true;
    while (swap) {
        swap = false;
        for (int i = 0; i < 2999; i++) {
            int j = i;
            if (vetor[j] > vetor[j+1]){

                swap = true;
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                
            }

        }
    }
    tempo2 = ( ((double) clock()) / CLOCKS_PER_SEC) - tempo1;
    printf("Tempo Decorrido BubbleSort Single Thread: %f segundos\n", tempo2);

}

// Multi Thread
void *bubblesort_multithread(void *param){

    tempo1 = (double) clock();            /* Captura tempo inicial */
    tempo1 = tempo1 / CLOCKS_PER_SEC;      /*  Converte em segundos */

    bool swap = true;

    while (swap) {

        swap = false;
        for (int i = 0; i < 1999; i++) {
            int j = i;
            if (vetor[j] > vetor[j+1]){

                swap = true;
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }

        }
    
    }
    tempo2 = ( ((double) clock()) / CLOCKS_PER_SEC) - tempo1;
    printf("Tempo Decorrido BubbleSort Multi Thread: %f segundos\n", tempo2);

}

void main(){

    // Preenche Vetor    
    int valor = 3000;
    for(int i = 0; i < 3000; i++ ) {

        vetor[i] = valor;
        valor--;

    }

    // Chama BubbleSort Single Thread
    bubblesort_single_thread();

    // Redesordena Vetor
    valor = 3000;
    for(int i = 0; i < 3000; i++ ) {

        vetor[i] = valor;
        valor--;

    }

    // Chama BubbleSort Multi Thread
    pthread_t tidbubble;
    pthread_attr_t attr;

   pthread_attr_init(&attr);

   pthread_create(&tidbubble,&attr,bubblesort_multithread,NULL);

   pthread_join(tidbubble, NULL);
   

}