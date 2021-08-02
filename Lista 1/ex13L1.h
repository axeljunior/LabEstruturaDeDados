#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
13) Escreva um programa que contenha uma estrutura de lista sequencial não ordenada com dados de 40 alunos (nome, matricula e média) e forneça as seguintes opções:
	(X) (1) Inserir um aluno na lista; (ler nome, matricula e média)
	(X) (2) Excluir um aluno da lista;
	(X) (3) Calcular média da turma;
	(X) (4) Imprimir dados dos alunos acima da média;
	(X) (5) Ordenar a lista;
	(X) (6) Imprimir lista;
	(X) (7) Sair.
Na implementação da opção 5, deve-se utilizar o algoritmo inserctionSort.
O programa termina quando for digitado a opção 7.
*/

#define TAM 40
#define MEDIA 7.0

// =========== LISTA SEQ. N' ORDENADA =========== //
struct tno {
	int matricula;
	int naMedia;
	char nome[50];
	float media;
};
typedef struct tlista_nord {
	int qtnos;
	struct tno lista[TAM];
}LISTAn;

void inicializa_lista(struct tlista_nord *);
int lista_vazia(struct tlista_nord *);
int lista_cheia(struct tlista_nord *);
void exibe_lista(struct tlista_nord *,int);
void calcula_media(struct tlista_nord *);
int busca(struct tlista_nord *, int);
int insere_lista(struct tlista_nord *, int ,char [],float);
int remove_lista(struct tlista_nord *, int);

// =========== LISTA SEQ. N' ORDENADA =========== //

void menu(struct tlista_nord *pl);

void troca(int *, int *);
void troca_float(float *,float *);
void troca_string(char [],char []);
void inserction_sort(struct tlista_nord *, int);


int main(){
	LISTAn lista;
	inicializa_lista(&lista);

	insere_lista(&lista, 2171,"Axel Junior",8.2200);
	insere_lista(&lista, 2170,"Jordy F",9.1200);
	insere_lista(&lista, 2172,"Dre P",8.7200);
	insere_lista(&lista, 2173,"David D",6.1234);
	insere_lista(&lista, 2174,"Josh Joestar",5.6230);

	int i,matricula;
	char id;
	// Bom, se eu entendi correto, você quer que a lista esteja já esteja preenchida com os dados de 40 alunos.
	for(i=5; i<40; i++){
		insere_lista(&lista, 2177+i, "Fulano", (float) 50/i);
	}
	printf("\n=========== %d ===========\n",lista.qtnos);
	menu(&lista);
/* TESTE
	exibe_lista(&lista,1);
	calcula_media(&lista);
	printf("=================================\n");
	remove_lista(&lista, 2173);
	exibe_lista(&lista,1);
	calcula_media(&lista);
	printf("=================================\n");
	inserction_sort(&lista, lista.qtnos);
	exibe_lista(&lista,1);
	printf("=================================\n");
*/
}

void menu(struct tlista_nord *lista){
	int opt=0,run = 1;
	/*
	(X) (1) Inserir um aluno na lista; (ler nome, matricula e média)
	(X) (2) Excluir um aluno da lista;
	(X) (3) Calcular média da turma;
	(X) (4) Imprimir dados dos alunos acima da média;
	(X) (5) Ordenar a lista;
	(X) (6) Imprimir lista;
	(X) (7) Sair. 
	*/
	int matricula;
	float media;
	char nome[50];
	while(run){
		printf("Escolha uma opção:\n (1) - Inserir Aluno\n (2) - Remover Aluno\n (3) - Calcular Media da Turma\n (4) - Exibir os alunos acima da media\n (5) - ordenar a lista\n (6) - Exibir todos os alunos\n (7) - Sair\n ==> ");
		scanf("%d",&opt);
		printf("=================================\n");
		switch(opt){
			case 1:
				printf("\nInforme o nome do aluno\n");
				fgetc(stdin);
				gets(nome);
				printf("\nInforme a matricula\n");
				scanf("%d",&matricula);
				printf("\nInforme a media\n");
				scanf("%f",&media);
				insere_lista(lista, matricula, nome, media);
				break;
			case 2:
				printf("\nInforme a matricula do aluno que deseja remover\n");
				scanf("%d",&matricula);
				remove_lista(lista, matricula);
				break;
			case 3:
				calcula_media(lista);
				break;
			case 4:
				exibe_lista(lista,0); // 0 Exibe só os alunos acima da media
				break;
			case 5:
				inserction_sort(lista, lista->qtnos);
				break;
			case 6:
				exibe_lista(lista,1); // 0 Exibe todos os alunos
				break;
			case 7:
				printf("Encerrando...");
				run=0;
				break;
			default:
				printf("\nOpção invalida\n");
			
		}
		printf("=================================\n");
	}
}

// =========== LISTA SEQ. N' ORDENADA =========== //
// (1) Inicialização da lista
void inicializa_lista(struct tlista_nord *pl) {
 pl->qtnos = 0;
}
// (2) Testar lista vazia
int lista_vazia(struct tlista_nord *pl) {
	if(pl->qtnos == 0)
		return 1;
	return 0;
}
// (3) Testar lista cheia
int lista_cheia(struct tlista_nord *pl) {
	if(pl->qtnos == TAM)
		return 1;
	return 0;
}
// (4) Exibir
// fullList = 1 - Exibe a Lista toda fullList = 0 Exibe só os alunos acima da media
void exibe_lista(struct tlista_nord *pl,int fullList) { 
	int i;
	for(i=0; i < pl->qtnos; i++){
		if(fullList){
			printf("\n-------\nNome do Aluno: %s\nMatricula: %d\nMédia: %.2f\n-------\n", pl->lista[i].nome,pl->lista[i].matricula,pl->lista[i].media);
		}
		else{
			if(pl->lista[i].media >= MEDIA){
				printf("\n-------\nNome do Aluno: %s\nMatricula: %d\nMédia: %.2f\n -------\n", pl->lista[i].nome,pl->lista[i].matricula,pl->lista[i].media);	
			}
		}
	}
}
// (5) Calcula media da turma
void calcula_media(struct tlista_nord *pl){
	int i,total=0;
	float somat=.0;
	for(i=0; i<pl->qtnos; i++){
		somat = somat + pl->lista[i].media;
		total++;
	}
	printf("\nMédia da turma é: %.2f\n", somat/total);
}

// (6) Buscar um elemento na lista
int busca(struct tlista_nord *pl, int elem) {
	int i;
	for(i=0; i< pl->qtnos; i++) {
		if(elem == pl->lista[i].matricula)
			return i; //achou
	}
	return -1; //não achou
}
// (7) Inserção sem repetição de matricula
int insere_lista(struct tlista_nord *pl, int mat,char nome[],float media) {
	int i;
	if(pl->qtnos == TAM){
		printf("\nSem espaço na lista\n");
		return 0;
	}
	i = busca(pl, mat);
	if(i>=0){ //se achou o valor na lista
		printf("\n %d - Essa matricula já esta cadastrada\n",mat);
		return -1;
	}

	pl->lista[pl->qtnos].matricula = mat;
	strcpy(pl->lista[pl->qtnos].nome, nome);
	pl->lista[pl->qtnos].media = media;
	if(media >= MEDIA)
		pl->lista[pl->qtnos].naMedia = 1;
	else
		pl->lista[pl->qtnos].naMedia = 0;

	pl->qtnos++;
	return 1;
}
// (8) Remoção
int remove_lista(struct tlista_nord *pl, int valor) {
	int i;
	if(lista_vazia(pl))
		return 0;
	i = busca(pl, valor);
	if(i<0){ //se não achou o valor na lista
		printf("\nNão existem alunos com esta matricula\n");
		return -1;
	}
	pl->qtnos--;
	strcpy(pl->lista[i].nome, pl->lista[pl->qtnos].nome);
	pl->lista[i].matricula = pl->lista[pl->qtnos].matricula;
	pl->lista[i].media = pl->lista[pl->qtnos].media;
	pl->lista[i].naMedia = pl->lista[pl->qtnos].naMedia;
	return 1;
}
// =========== LISTA SEQ. N' ORDENADA =========== //

void troca(int *elementoA,int *elementoB){
	int aux;
	aux = *elementoA;
	*elementoA = *elementoB;
	*elementoB = aux;
}
void troca_float(float *elementoA,float *elementoB){
	float aux;
	aux = *elementoA;
	*elementoA = *elementoB;
	*elementoB = aux;
}
void troca_string(char elementoA[],char elementoB[]){
	char aux[50];
	strcpy(aux, elementoA);
	strcpy(elementoA, elementoB);
	strcpy(elementoB, aux);
}
void inserction_sort(struct tlista_nord *pl, int tam){
	int i,j;
	for(j=1; j<tam; j++) {
		for(i=j; i>0 && pl->lista[i-1].matricula > pl->lista[i].matricula; i--){

			troca(&pl->lista[i-1].matricula, &pl->lista[i].matricula);
			troca_string(pl->lista[i-1].nome, pl->lista[i].nome);
			troca_float(&pl->lista[i-1].media, &pl->lista[i].media);
			troca(&pl->lista[i-1].naMedia, &pl->lista[i].naMedia);
		}
	}
}