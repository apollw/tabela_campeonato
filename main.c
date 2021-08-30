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

/*
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define BTN1 1
#define BTN2 2
#define BTN3 3

static HWND nome, nome2, time1, time2, goal_A, goal_B, resultado;

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

void addMenus(HWND);

HMENU hMenu;

TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    HWND       hwnd;        /* This is the handle for our window */
    //MSG        messages;    /* Here messages to the application are saved */
    //WNDCLASSEX wincl;       /* Data structure for the windowclass */
/*
    wincl.hInstance     = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc   = WindowProcedure;   /* This function is called by windows */
    /*wincl.style         = CS_DBLCLKS;        /* Catch double-clicks */
    /*wincl.cbSize        = sizeof (WNDCLASSEX);

    wincl.hIcon        = LoadIcon (NULL, IDI_QUESTION);
    wincl.hIconSm      = LoadIcon (NULL, IDI_QUESTION);
    wincl.hCursor      = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                   /* No menu */
    /*wincl.cbClsExtra   = 0;                      /* No extra bytes after the window class */
    //wincl.cbWndExtra   = 0;                      /* structure or the window instance */
    //wincl.hbrBackground = GetSysColorBrush(COLOR_ACTIVECAPTION);

    /* Register the window class, and if it fails quit the program */
    /*if (!RegisterClassEx (&wincl))
        return 0;

    hwnd = CreateWindowEx (
        0, szClassName, _T("WORLD SERIES LEAGUE"), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 375,
        HWND_DESKTOP, NULL, hThisInstance, NULL
    );

    /* Make the window visible on the screen */
    //ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    /*while (GetMessage (&messages, NULL, 0, 0)) {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

     return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch(message) {
        case WM_CREATE:
            addMenus(hwnd);

            nome = CreateWindowW(L"static", L"Gerenciador de Tabela do Campeonato",
                                 WS_VISIBLE | WS_CHILD,
                                 10, 20, 260, 20,
                                 hwnd, NULL, NULL, NULL);

            /*CreateWindow(TEXT("button"), TEXT(" -> "), WS_VISIBLE | WS_CHILD,
                         10, 90, 80, 40, hwnd, (HMENU) BTN1, NULL, NULL);*/

            /*CreateWindow(TEXT("button"), TEXT("Site"), WS_VISIBLE | WS_CHILD,
                         110, 90, 160, 40,
                         hwnd, (HMENU) BTN2, NULL, NULL);*/

            /*nome2 = CreateWindowW(L"static", L"Criado por: Leanderson Silva",
                          WS_VISIBLE | WS_CHILD,
                          10, 70, 260, 20,
                          hwnd, NULL, NULL, NULL);

            CreateWindow(TEXT("static")," ", WS_VISIBLE | WS_CHILD,
                         320, 20, 180, 80,
                         hwnd, NULL, NULL, NULL);

            CreateWindowW(L"static", L"Time A",
                          WS_VISIBLE | WS_CHILD,
                          10, 140, 50, 20,
                          hwnd, NULL, NULL, NULL);

            time1 = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
                         74, 140, 80, 20,
                         hwnd, NULL, NULL, NULL);

            CreateWindowW(L"static", L"Time B",
                          WS_VISIBLE | WS_CHILD,
                          170, 140, 50, 20,
                          hwnd, NULL, NULL, NULL);

            time2 = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
                         230, 140, 80, 20,
                         hwnd, NULL, NULL, NULL);

            goal_A = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
                         322, 140, 50, 20,
                         hwnd, NULL, NULL, NULL);

            CreateWindowW(L"static", L"      X",
                          WS_VISIBLE | WS_CHILD,
                          386, 140, 60, 20,
                          hwnd, NULL, NULL, NULL);

            goal_B = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
                         452, 140, 50, 20,
                         hwnd, NULL, NULL, NULL);

            CreateWindow(TEXT("button"), TEXT("Adicionar Resultado"), WS_VISIBLE | WS_CHILD | WS_BORDER,
                         10, 240, 140, 20,
                         hwnd, (HMENU) BTN3, NULL, NULL);

            CreateWindow(TEXT("static"), TEXT("Dados dos Times:"), WS_VISIBLE | WS_CHILD,
                         160, 210, 100, 50,
                         hwnd, NULL, NULL, NULL);

            resultado = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD,
                         280, 180, 200, 140,
                         hwnd, NULL, NULL, NULL);
            break;
        case WM_COMMAND:
            if(LOWORD(wParam)==BTN1) {
                int len = GetWindowTextLength(nome)+1;
                static char title[500];
                GetWindowText(nome, title, len);
                MessageBox(NULL, title, "", MB_OK);
                return 0;
            }
            if(LOWORD(wParam)==BTN2) {
                int com = GetWindowTextLength(nome)+1;
                static char titulo[500];
                GetWindowText(nome2, titulo, com);
                MessageBox(NULL, titulo, "", MB_OK);
                return 0;}

            if(LOWORD(wParam)==BTN3) { /**Armazenando os valores*/
/*
                char n1 = GetWindowTextLength(time1);
                char n2 = GetWindowTextLength(time2);
                int n3 = GetWindowTextLength(goal_A)+1;
                int n4 = GetWindowTextLength(goal_B)+1;

                static char t1[50], t2[50], t3[50], t4[50];

                GetWindowText(time1, t1, n1);
                GetWindowText(time2, t2, n2);
                GetWindowText(goal_A, t3, n3);
                GetWindowText(goal_B, t4, n4);

                //float res = (atof(t1)+atof(t2)+atof(t3)+atof(t4))/4;

                char tam[30];

                //sprintf(tam, "%s", Imprimir_tudo());

                //ltoa(res, tam, 10);

                SetWindowText(resultado, tam);

                FILE *arq;
                arq=fopen("Teste.txt", "w+");
                fwrite(tam, sizeof(arq),10,arq);
                fclose(arq);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            //break;
        //default:                      /* for messages that we don't deal with */
            /*return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addMenus(HWND hwnd) {

    hMenu = CreateMenu();

    HMENU hFileMenu = CreateMenu();

    AppendMenu(hMenu, MF_STRING, NULL, "Arquivo");
    AppendMenu(hMenu, MF_STRING, NULL, "Ajuda");
    AppendMenu(hMenu, MF_STRING, NULL, "Propriedade");
    AppendMenu(hMenu, MF_STRING, NULL, "Restart");
    AppendMenu(hMenu, MF_STRING, NULL, "Keyboard");

    SetMenu(hwnd, hMenu);

}
*/

