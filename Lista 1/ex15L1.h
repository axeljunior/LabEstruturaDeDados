#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
15) Considere a lista de clientes da livraria contendo nome e código de identificação de 20 clientes,Tem que os elementos estão ordenados. Escreva um programa que contenha funções para:
	(a) Inserir um cliente na lista;
	(b) Imprimir os dados da lista;
	(c) Ler um código de identificação e buscar o cliente (usar busca binária);
	(d) Retirar um cliente da lista.
	(e) Sair
*/

#define TAM 100
// =========== LISTA SEQ.ORDENADA =========== //
struct tno {
	int idCod;
	char nome[50];
};
typedef struct tlista_ord {
	int qtnos;
	struct tno lista[TAM];
}LISTAn;

void inicializa_lista(struct tlista_ord *);
int lista_vazia(struct tlista_ord *);
int lista_cheia(struct tlista_ord *);
void exibe_lista(struct tlista_ord *,int);

int busca_seq(struct tlista_ord *, int elem, int *pos);
int insere_listaOrd(struct tlista_ord *, int ,char []);
int remove_listaOrd(struct tlista_ord *, int);

// =========== LISTA SEQ.ORDENADA =========== //
//---
// =========== Insertion Sort =========== //
void troca(int *, int *);
void troca_float(float *,float *);
void troca_string(char [],char []);
void inserction_sort(struct tlista_ord *, int);
// =========== Insertion Sort =========== //
//---
// =========== Busca Binaria =========== //
int buscaBinaria (struct tlista_ord *,int, int);
// =========== Busca Binaria =========== //

void menu(struct tlista_ord *pl);

int main(){
	LISTAn lista;
	inicializa_lista(&lista);

	insere_listaOrd(&lista,3,"Axel Junior");
	insere_listaOrd(&lista,2,"Jordy F");
	insere_listaOrd(&lista,1,"Dre P");
	insere_listaOrd(&lista,4,"David D");
	insere_listaOrd(&lista,0,"Josh Joestar");

	int i;
	for(i=5; i<20; i++){
		insere_listaOrd(&lista, i, "Fulano");
	}
	menu(&lista);	
}

void menu(struct tlista_ord *lista){
	int opt=0,run = 1;
	/*
	(X) - (a) Inserir um cliente na lista; 1
	(X) - (b) Imprimir os dados da lista; 4
	(X) - (c) Ler um código de identificação e buscar o cliente (usar busca binária);
	(X) - (d) Retirar um cliente da lista. 2
	(X) - (e) Sair 5
	*/
	int idCod,index;
	float media;
	char nome[50];
	while(run){
		printf("Escolha uma opção:\n (1) - Inserir cliente\n (2) - Remover cliente\n (3) - Buscar cliente\n (4) - Exibir os clientes cadastrados\n (5) - Sair\n ==> ");
		scanf("%d",&opt);
		printf("=================================\n");
		switch(opt){
			case 1:
				printf("\nNome do Cliente\n ==> ");
				fgetc(stdin);
				gets(nome);
				printf("\nInforme a Codigo de identificação\n ==> ");
				scanf("%d",&idCod);
				insere_listaOrd(lista, idCod, nome);
				break;
			case 2:
				printf("\nInforme o Codigo de identificação do cliente que deseja remover\n ==> ");
				scanf("%d",&idCod);
				remove_listaOrd(lista, idCod);
				break;
			case 3:
				printf("\nInforme o Codigo de identificação do cliente que deseja buscar\n ==> ");
				scanf("%d",&idCod);
				busca_seq(lista,idCod,&index);
				if(index != -1)
					exibe_lista(lista,index);
				else
					printf("\nCodigo de identificação não encontrado\n");
				break;
			case 4:
				exibe_lista(lista,-1);
				break;
			case 5:
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
void inicializa_lista(struct tlista_ord *pl) {
 pl -> qtnos = 0;
}
// (2) Testar lista vazia
int lista_vazia(struct tlista_ord *pl) {
	if(pl -> qtnos == 0)
		return 1;
	return 0;
}
// (3) Testar tlista_ord cheia
int lista_cheia(struct tlista_ord *pl) {
	if(pl ->qtnos==TAM)
		return 1;
	return 0;
}
// (4) Exibir
void exibe_lista(struct tlista_ord *pl,int index) { 
	if(index>0){
		printf("\n-------\nNome do Cliente: %s\nCodigo de identificação: %d\n-------\n", pl->lista[index].nome,pl->lista[index].idCod);
	}else{
		int i;
		for(i=0; i < pl->qtnos; i++){
			printf("\n-------\nNome do Cliente: %s\nCodigo de identificação: %d\n-------\n", pl->lista[i].nome,pl->lista[i].idCod);	
		}
	}
}
// (5) Busca Sequencial Ordenada
int busca_seq(struct tlista_ord *pl, int elem, int *pos){
	int i;
	for(i=0; i < pl -> qtnos && elem > pl -> lista[i].idCod; i++);
	*pos=i;
	if((i == pl -> qtnos) || (elem != pl -> lista[i].idCod))
		return 0; //não achou
	return 1; //achou
}
// (6) Inserção
int insere_listaOrd(struct tlista_ord *pl, int id,char nome[]){
	int i, posicao;
	if(pl->qtnos == TAM){
		printf("\nSem espaço na lista\n");
		return 0;
	}
	if(busca_seq(pl, id, &posicao)){ //se achou o vatlista_ordlor na lista
		printf("\n %d - Esse Codigo de identificação já esta cadastrada\n",id);
		return -1;
	}
	for(i=pl -> qtnos; i>posicao; i--){
		pl->lista[i].idCod = pl->lista[i-1].idCod;
		strcpy(pl->lista[i].nome, pl->lista[i-1].nome);
	}
	pl->lista[posicao].idCod = id;
	strcpy(pl->lista[posicao].nome, nome);
	pl->qtnos++;
	return 1;
}
// (7) Remoção
int remove_listaOrd(struct tlista_ord *pl, int elem){
	int i, posicao;
	if(pl->qtnos==0)
		return 0;
	if(!busca_seq(pl, elem, &posicao)){
		printf("\nNão existe cliente com este Codigo de identificação\n");
		return -1;
	}
	for(i=posicao; i< pl ->qtnos-1; i++){
		pl->lista[i].idCod = pl->lista[i+1].idCod;
		strcpy(pl->lista[i].nome, pl->lista[i+1].nome);
	}
	pl->qtnos--;
	return 1;
}
// =========== LISTA SEQ. N' ORDENADA =========== //
// =========== Insertion Sort =========== //
void troca(int *elementoA,int *elementoB){
	int aux;
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
void inserction_sort(struct tlista_ord *pl, int tam){
	int i,j;
	for(j=1; j<tam; j++) {
		for(i=j; i>0 && pl->lista[i-1].idCod > pl->lista[i].idCod; i--){

			troca(&pl->lista[i-1].idCod, &pl->lista[i].idCod);
			troca_string(pl->lista[i-1].nome, pl->lista[i].nome);
		}
	}
}
// =========== Busca Binaria =========== //
int buscaBinaria (struct tlista_ord *pl,int tamanho_vetor, int valAlvo){
	int fim, meio,ini=0;
	fim=tamanho_vetor-1;
	while(ini <= fim){
		meio=(ini+fim)/2;
		if(valAlvo == pl->lista[meio].idCod)
			return meio;
		if (valAlvo < pl->lista[meio].idCod)
			fim = meio-1;
		else
			ini = meio+1;
	}
	return -1;
}