//Struct de Equipe
struct Equipe{

char Nome[20];
int Pontuacao;
int Vitorias;
int Empates;
int Derrotas;
int placar_temporario;
//int indice;

struct Equipe *prox;

};typedef struct Equipe Equipe;
Equipe *cabeca_do_node;

//*************Declara��es de fun��es************//

//Fun��o Inserir Time
void Inserir_Time();
//Fun��o Imprimir Nomes
void Imprimir();
//Fun��o Ordenar Tabela
void Ordenar_Tabela();
//Fun��o Imprimir Tabela
void Imprimir_Tabela();
//Imprimir Tudo
void Imprimir_tudo();
//Inserir Resultados
//void Inserir_Resultados(char time1[], char time2[]);
void Inserir_Resultados(char time1[],char time2[]);


//Gerar tabela aleatoriamente
//void gerar_vetor_times(int *array, size_t n);
//Relacionar �ndices
//void Relacionar_Indices(int vet[]);




