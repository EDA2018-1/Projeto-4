#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UnTempo 5

typedef struct voo{
  char codigo[6]; //identificação do voo. 2 letras maiúsculas, seguidas por 4 números inteiros.
  char evento;// tipo de evento. A(aproximação) ou D(decolagem)
  int combA; // nivel de combustivel. (0 a 12)
  struct voo *prox;

} Voo;

typedef struct fila{
  Voo *inicio,*fim;
  int tamanho;

} Fila;

typedef struct pista{
  Voo *ocupado;
  int evento_tempo; // tempo de duração do evento, caso esteja ocupado.

} Pista;

typedef struct aeroporto{
  Fila *pousos;
  Fila *decolagens;
  int tempo;

} Aeroporto;

int main(){

  char codigos[64][6] = {"VG3001","JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009",
                         "AZ1008","AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880",
                         "AL0012","TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002",
                         "AZ1002","AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403",
                         "AZ1001","LN7003", "AZ1004", "TG1504", "AZ1005", "TG1502", "GL7601",
                         "TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390","VV3392",
                         "GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920","AZ1065",
                         "LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434","TG1510",
                         "TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609","KL5610", "KL5611"}

}

void horaInicial():
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Data atual do sistema é: %s", asctime (timeinfo) );


/* esta função gera um numero de voos aleátorios entre 20 e 64 e numeros
   de aproximações e decolagens entre 10 e 32*/
void nVoos(int *n_voos,int *n_aproximacoes,int *n_decolagen){

  srand(time(NULL));
  *n_voos = rand() % 64;

  // garante que o numero de voos está entre 20 e 64.
  while(*n_voos < 20){
    *n_voos = rand() % 64;
  }

  *n_aproximacoes = rand() % 32;

  // garante que o numero de voos está entre 10 e 32;
  while(*n_aproximacoes < 10){
    *n_aproximacoes = rand() % 32;
  }

  *n_decolagens = *n_voos - *n_aproximacoes;

  }