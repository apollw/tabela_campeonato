#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "team_struct.h"

void Inserir_Time(char t[]){

Equipe *temp1 = (Equipe*)malloc(sizeof(Equipe));

strcpy(temp1->Nome,t);
temp1->Vitorias=0;
temp1->Derrotas=0;
temp1->Empates=0;
temp1->Pontuacao=0;
temp1->prox = NULL;

if(cabeca_do_node!=NULL)
    temp1->prox = cabeca_do_node;
cabeca_do_node = temp1;

}

void Imprimir(){

Equipe *temp = cabeca_do_node;
printf("Os times sao:\n");

while(temp!=NULL){
    printf(" Nome: %s\n",temp->Nome);

    temp = temp->prox;
}
printf("\n");
}

void Ordenar_Tabela(){

Equipe* L = cabeca_do_node;
Equipe* p;
Equipe* r;
int aux;

for(p=L;p!=NULL;p=p->prox){
	for(r=L->prox;r!=NULL;r=r->prox){
		if(p->Pontuacao<r->Pontuacao){
			aux=p->Pontuacao;
			printf("%d\n",aux);
			p->Pontuacao=r->Pontuacao;
			printf("p->info - %d\nr->info - %d\n",p->Pontuacao,r->Pontuacao);
			r->Pontuacao=aux;
			printf("%d\n",r->Pontuacao);
		}
	}
}

}

void Imprimir_Tabela(){

Equipe *temp = cabeca_do_node;

while(temp!=NULL){
    printf("Time: %s\t",temp->Nome);
    printf("Pontos: %d\n",temp->Pontuacao);
    temp = temp->prox;
}
printf("\n");
}

void Imprimir_tudo(){

Equipe *temp = cabeca_do_node;
printf("Os times sao:\n");

while(temp!=NULL){
    printf(" Nome: %s\n",temp->Nome);
        printf(" Pontuacao: %d\n",temp->Pontuacao);

    printf(" Vitorias: %d\n",temp->Vitorias);
    printf(" Empates: %d\n",temp->Empates);
    printf(" Derrotas: %d\n",temp->Derrotas);
    temp = temp->prox;
    printf("\n\n");
}
printf("\n");
}

void Inserir_Resultados(char time1[], char time2[]){

int placar1, placar2;
int verif1=0, verif2=0;
Equipe *temp = cabeca_do_node;


//Busca dos times na lista
    while(temp!=NULL){
        if(strcmp(temp->Nome,time1) == 0){
            verif1 = 1;
            break;
        }
        temp = temp->prox;
    }

//Reiniciando temp para fazer a segunda busca
temp = cabeca_do_node;

    while(temp!=NULL){
        if(strcmp(temp->Nome,time2) == 0){
            verif2 = 1;
            break;
        }
        temp = temp->prox;
    }
temp = cabeca_do_node;

//Comparando placares e atribuindo respectivos dados

if(verif1==1&&verif2==1){

    printf("Insira o placar da partida:\n");
    scanf("%d",&placar1);
    scanf("%d",&placar2);

    while(temp!=NULL){
        if(strcmp(temp->Nome,time1) == 0){//Time localizado
            temp->placar_temporario = placar1;
            //Verificar estado da partida
            if(temp->placar_temporario>placar2){
                temp->Vitorias = temp->Vitorias+1;
                temp->Pontuacao = temp->Pontuacao+3;
            }else if(temp->placar_temporario<placar2){
                temp->Derrotas = temp->Derrotas+1;
            }else if(temp->placar_temporario==placar2){
                temp->Empates = temp->Empates+1;
                temp->Pontuacao = temp->Pontuacao+1;
            }
            break;
        }
    temp = temp->prox;
    }

//Renova ponteiro temp
temp = cabeca_do_node;

    while(temp!=NULL){
        if(strcmp(temp->Nome,time2) == 0){//Time localizado
            temp->placar_temporario = placar2;
            //Verificar estado da partida
            if(temp->placar_temporario>placar1){
                temp->Vitorias = temp->Vitorias+1;
                temp->Pontuacao = temp->Pontuacao+3;
            }else if(temp->placar_temporario<placar1){
                temp->Derrotas = temp->Derrotas+1;
            }else if(temp->placar_temporario==placar1){
                temp->Empates = temp->Empates+1;
                temp->Pontuacao = temp->Pontuacao+1;
            }
            break;
        }
        temp = temp->prox;
    }
}else{
    printf("Um dos times ou nenhum dos times existe na lista. Tente novamente");
}

}


//void gerar_vetor_times(int *array, size_t n){

/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */

/* Essa função necessita de um vetor de tamanho definido e
elementos definidos na main, para poder reorganizar esse
vetor de forma randômica.
*/
/*
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
*/

/*void Relacionar_Indices(int vet[]){

int i=0;
Equipe *temp = cabeca_do_node;

while(temp!=NULL){
    temp->indice = vet[i];
    i++;
    temp = temp->prox;
}

}
*/
