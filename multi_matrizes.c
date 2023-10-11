/*
Realize uma implementação em sua linguagem de preferência de uma multiplicação entre matrizes
utilizando o sistema single thread e multithread (pelo menos duas threads), no qual o último deve ser
feito usando as bibliotecas thread suportada na linguagem escolhida. Realize uma análise
comparativa no quesito tempo de processamento utilizando bibliotecas como time.h (como o exemplo
fornecido no material ou biblioteca equivalente na linguagem escolhida). A operação de
multiplicação deve usar duas abordagens, a multiplicação matricial e a posicional,
e deve ser entre, no mínimo, matrizes quadráticas de 3X3, como no exemplo apresentado
e os números deve estar em float (ponto flutuante):
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// MATRIZES
float matriz_1[3000][3000];
float matriz_2[3000][3000];

// TEMPO
double tempo1, tempo2;

// MATRIZES DE RESULTADOS
float matricial[3000][3000];
float posicional[3000][3000];


// SINLGLE THREAD MATRICIAL
void single_thread_matricial(){

   tempo1 = (double) clock();            /* Captura tempo inicial */
   tempo1 = tempo1 / CLOCKS_PER_SEC;      /*  Converte em segundos */

   // MULTIPLICAÇÃO MATRICIAL
   for (int i = 0; i < 3000; i++) {
      for (int j = 0; j < 3000; j++) {

         matricial[i][j] = matriz_1[i][j] * matriz_2[j][i];

      }
   }

   tempo2 = ( ((double) clock()) / CLOCKS_PER_SEC) - tempo1;

   printf("Tempo Decorrido Single Thread Matricial: %f segundos\n", tempo2);
}

// SINGLE THREAD POSICIONAL
void single_thread_posicional(){

   tempo1 = (double) clock();            /* Captura tempo inicial */
   tempo1 = tempo1 / CLOCKS_PER_SEC;      /*  Converte em segundos */

   // MULTIPLICAÇÃO POSICIONAL
   for (int i = 0; i < 3000; i++) {

      for (int j = 0; j < 3000; j++) {

         posicional[i][j] = matriz_1[i][j] * matriz_2[i][j];

      }
   }

   tempo2 = ( ((double) clock()) / CLOCKS_PER_SEC) - tempo1;

   printf("Tempo Decorrido Single Thread Posicional: %f segundos\n", tempo2);
}

// THREAD MATRICIAL
void *thread_matricial(void *param){

   tempo1 = (double) clock();            /* Captura tempo inicial */
   tempo1 = tempo1 / CLOCKS_PER_SEC;      /*  Converte em segundos */

   // MULTIPLICAÇÃO MATRICIAL
   for (int i = 0; i < 3000; i++) {

      for (int j = 0; j < 3000; j++) {

         matricial[i][j] = matriz_1[i][j] * matriz_2[j][i];

      }
   }

   tempo2 = ( ((double) clock()) / CLOCKS_PER_SEC) - tempo1;

   printf("Tempo Decorrido Matricial: %f segundos\n", tempo2);

}

// THREAD POSICIONAL
void *thread_posicional(void *param){

   tempo1 = (double) clock();            /* Captura tempo inicial */
   tempo1 = tempo1 / CLOCKS_PER_SEC;      /*  Converte em segundos */

   // MULTIPLICAÇÃO POSICIONAL
   for (int i = 0; i < 3000; i++) {

      for (int j = 0; j < 3000; j++) {

         posicional[i][j] = matriz_1[i][j] * matriz_2[i][j];

      }
   }

   tempo2 = ( ((double) clock()) / CLOCKS_PER_SEC) - tempo1;

   printf("Tempo Decorrido Posicional: %f segundos\n", tempo2);

}

void main(){

   // Preenche as Matrizes
   for (int i = 0; i < 3000; i++) {

      for (int j = 0; j < 3000; j++) {

         // Atribui um valor float aleatório entre 0 e 1
         matriz_1[i][j] = (float)rand()/RAND_MAX;     
         matriz_2[i][j] = (float)rand()/RAND_MAX;     

      }
   }

   // Chama as funções single threads
   single_thread_matricial();
   single_thread_posicional();

   // Chama as funções multi threads

   //declarar variáveis e tipos para threads
   pthread_t tid_matricial, tid_posicional;
   pthread_attr_t attr;

   pthread_attr_init(&attr);

   // Cria Thread de Multiplicação Matricial
   pthread_create(&tid_matricial,&attr,thread_matricial,NULL);
   pthread_join(tid_matricial, NULL);
   // Cria Thread de Multiplicação Posicional
   pthread_create(&tid_posicional,&attr,thread_posicional,NULL);
   pthread_join(tid_posicional, NULL);
   // Junta Threads

   

   // Pula linha
   printf("\n");

}