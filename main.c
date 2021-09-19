#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "team_struct.h"

int main(void)
{
int add=0;
int i;
int opcao=1;//Opção geral do Menu
char time[20];//Variável de inclusão de times
char time1[20],time2[20];//Variáveis de formação de partida
//int random_teams[8]={1,2,3,4,5,6,7,8};

    while (opcao!=0)
    {
        system("cls");
        printf("\n           \t\t      WORLD SERIES LEAGUE ");
        printf("\n          ");
        printf("\n\n    \xC9");
        printf("\n    \xBA               OPCOES                           \xBA    NUMERO DA OPCAO    \xBA\n");
        printf("\n    \xBA INSERIR TIMES DO CAMPEONATO                    \xBA           1           \xBA");
        printf("\n    \xBA MOSTRAR TIMES PARTICIPANTES                    \xBA           2           \xBA");
        printf("\n    \xBA INSERIR RESULTADOS DE PARTIDAS                 \xBA           3           \xBA");
        printf("\n    \xBA MOSTRAR TABELA DO CAMPEONATO                   \xBA           4           \xBA");
        printf("\n    \xBA MOSTRAR DADOS DO TIME                          \xBA           5           \xBA");
        printf("\n    \xC8");
        printf("\n\n                         DIGITE O NUMERO DA OPCAO DESEJADA: ");
        printf ("\n\n                                Escolha uma opcao:  ");
        scanf ("%d", &opcao);
        system("cls");;
        switch (opcao)
        {
        case 1:
                if(add==0){
                    printf("Insira os 8 times participantes do campeonato:\n");
                    fflush(stdin);
                    for(i=0;i<8;i++){
                    gets(time);
                    fflush(stdin);
                    Inserir_Time(time);
                    }
                    add++;
                }
                else{
                    printf("Voce ja adicionou os 8 times do campeonato\n");
                    getch();
                    break;
                }

     //Após receber os nomes dos times, gerar vetor de índices de times aleatoriamente para gerar a tabela do campeonato
                //gerar_vetor_times(random_teams,8);
    //Relacionar índices do vetor random a cada time
                //Relacionar_Indices(random_teams);

            printf("*****TIMES INSERIDOS COM SUCESSO*****");
            printf("\n\nPressiones qualquer teclas para retornar ao menu...");
            getch();

            system("cls");
            break;

        case 2:
                Imprimir();

            printf("\n\nPressiones qualquer teclas para retornar ao menu...");
            getch();

            system("cls");
            break;

        case 3:

            printf("Insira o primeiro time\n");
            fflush(stdin);
            gets(time1);
            printf("Insira o segundo time\n");
            fflush(stdin);
            gets(time2);
            fflush(stdin);

            //Chamando a função de inclusão de placares
            Inserir_Resultados(time1,time2);

            printf("\n\nPressiones qualquer teclas para retornar ao menu...");
            getch();

            system("cls");
            break;


        case 4:

            printf("\n\nPressiones qualquer teclas para retornar ao menu...");
            getch();

            system("cls");
            break;

        case 5:
                Imprimir_tudo();
                fflush(stdin);

            printf("\n\nPressiones qualquer teclas para retornar ao menu...");
            getch();

            system("cls");
            break;

         default:
            system("cls");
            printf("\n\n\n\t\t\t*****FIM*****\n");
            exit(1);

            break;

        }
    }
    printf ("\n\n============================================================================\n\n");
    printf ("\nPressione algo para terminar ...");


system("pause");
return 0;
}
