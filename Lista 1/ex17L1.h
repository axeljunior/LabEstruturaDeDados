#include <stdio.h>
#include <stdlib.h>

#include "Outros/pontResumo.h"

/*
17) Escreva uma função para as seguintes operações adicionais para uma Lista Sequencial L1:
(X) - Verificar se uma Lista L1 está ordenada (em ordem crescente ou decrescente);
(X) - Copiar uma Lista L1 para uma outra L2. Use necessariamente a função insere();
(X) - Copiar uma Lista L1 para uma Lista L2 eliminando elementos repetidos. Use a função insere();
(X) - Inverter uma lista L1;
(X) - Intercalar L1 com L2 gerando L3 sem elementos repetidos (considere L1 e L2 ordenadas);
(X) - A partir de L1 e L2, gere L4 considerando os elementos repetidos em ambas as listas
(considere L1 e L2 ordenadas).
*/

#define TAM 100
// ========== PILHA ========== //
typedef struct tpilha {
	int topo;
	char pilha[TAM];
}PILHA;

void inicializaPilha(struct tpilha *);
int pilhaVazia(struct tpilha *);
int pilhaCheia(struct tpilha *);
int empilha(struct tpilha *, int);
int desempilha (struct tpilha *, int *);
// ========== PILHA ========== //

// = ========= LISTA SEQ. N'ORDENADA ========= = //
struct tno {
	int chave;
};
typedef struct tlista_ord {
	int qtnos;
	int crescente;
	struct tno lista[TAM];
}LISTAs;

void inicializa_lista(struct tlista_ord *);
int lista_vazia(struct tlista_ord *);
int lista_cheia(struct tlista_ord *);
void percurso(struct tlista_ord *);
int busca(struct tlista_ord *, int);
int insere_lista(struct tlista_ord *, int);
int insere_lista2(struct tlista_ord *, int);
int remove_lista(struct tlista_ord *, int);

int verifica_ord(struct tlista_ord*,int); // 1
int copia_lista(struct tlista_ord *,struct tlista_ord *); // 2
int copia_listaNrept(struct tlista_ord *, struct tlista_ord *); // 3
void inverte_lista(struct tlista_ord *pl); // 4
int intercala_elementos(struct tlista_ord *, struct tlista_ord *, struct tlista_ord *); //5
int interc_elementos(struct tlista_ord *, struct tlista_ord *, struct tlista_ord *); //6
// =========== LISTA SEQ. N'ORDENADA =========== //

void troca(int *elementoA,int *elementoB);
void inserction_sort(struct tlista_ord *pl, int tam);

int main(){
	///* TESTES
	LISTAs L1,L2,L3,L4;
	inicializa_lista(&L1);
	inicializa_lista(&L2);
	inicializa_lista(&L3);
	inicializa_lista(&L4);
	
	for(int i=1; i<9; i++)
		insere_lista(&L1, 9-i);
	
	for(int i=5; i<15; i++)
		insere_lista(&L2, i);

	printf("\nExibindo lista 1\n");
	percurso(&L1);
	inverte_lista(&L1);
	printf("\nExibindo lista 1\n");
	percurso(&L1);
	
	intercala_elementos(&L1,&L2,&L3);
	interc_elementos(&L1, &L2, &L4);
	
	copia_listaNrept(&L1, &L2);

	printf("\nExibindo lista 1\n");
	percurso(&L1);
	printf("\nExibindo lista 2\n");
	percurso(&L2);
	printf("\nExibindo lista 3\n");
	percurso(&L3);
	printf("\nExibindo lista 4\n");
	percurso(&L4);

	if(verifica_ord(&L1,L1.qtnos))
		printf("\n\n== Ordenada ==\n");
	else
		printf("\n\n== Não Ordenada ==\n");

	if(verifica_ord(&L2,L2.qtnos))
		printf("\n\n== Ordenada ==\n");
	else
		printf("\n\n== Não Ordenada ==\n");
	
	//*/
	
}
// =========== LISTA SEQ. N'ORDENADA =========== //
// (1) Inicialização da lista
void inicializa_lista(struct tlista_ord *pl) {
	pl->qtnos = 0;
	pl->crescente = 1;
}
// (2) Testar lista vazia
int lista_vazia(struct tlista_ord *pl) {
	if(pl -> qtnos == 0)
		return 1;
	return 0;
}
// (3) Testar lista cheia
int lista_cheia(struct tlista_ord *pl) {
	if(pl->qtnos==TAM)
		return 1;
	return 0;
}
// (4) Percurso
void percurso(struct tlista_ord *pl) {
	printf("----------");
	if(lista_vazia(pl))
		printf("\nA lista esta vazia");
	int i;

	for(i=0; i< pl -> qtnos; i++)
		printf("\n%d", pl -> lista[i].chave);
	printf("\n----------\n");

}
// (5) Buscar um elemento na lista
int busca(struct tlista_ord *pl, int elem) {
	int i;
	for(i=0; i< pl->qtnos; i++) {
		if(elem == pl->lista[i].chave)
			return i; //achou
	}
	return -1; //não achou
}
// (6) Inserção sem repetição
int insere_lista(struct tlista_ord *pl, int elem) {
	int i;
	if(pl->qtnos == TAM){
		printf("\nSem espaço na lista\n");
		return 0;
	}
	i = busca(pl, elem);
	if(i>=0){ //se achou o valor na lista
		return -1;
	}

	pl->lista[pl->qtnos].chave = elem;

	pl->qtnos++;
	return 1;
}
// (6.2) Inserção com repetição
int insere_lista2(struct tlista_ord *pl, int valor) {
	if(pl -> qtnos == TAM)
		return -1;
	pl->lista[pl->qtnos].chave = valor;
	pl->qtnos++;
	return 1;
}
// (7) Remoção
int remove_lista(struct tlista_ord *pl, int valor) {
	int i;
	if(lista_vazia(pl))
		return 0;
	i = busca(pl, valor);
	if(i<0){ //se não achou o valor na lista
		return -1;
	}

	pl->qtnos--;
	pl->lista[i].chave = pl->lista[pl->qtnos].chave;
	return 1;
}
/* (8) Verificar Ordenação

(X) - Verificar se uma Lista L1 está ordenada (em ordem crescente ou decrescente);
*/
int verifica_ord(struct tlista_ord *pl,int tam){
	int i,j;
	int cres=1,decres=1;
	for(i=0; i<pl->qtnos-1; i++){
		if(pl->lista[i].chave > pl->lista[i+1].chave)
			cres = 0; 
		if(pl->lista[i].chave < pl->lista[i+1].chave)
			decres = 0;	
	}
	if(cres || decres)
		return 1;
	return 0;
}
/* (9) Copia o conteudo de uma lista para o final de outra lista

(X) - Copiar uma Lista L1 para uma outra L2. Use necessariamente a função insere();
*/
int copia_lista(struct tlista_ord *pl,struct tlista_ord *pl2) {
	if(pl->qtnos == TAM)
		return 0;
	int i;
	for(i=0; i< pl->qtnos; i++)
		insere_lista(pl2, pl->lista[i].chave);
	return 1;
}
/*(10) Copiar apenas os elementos Unicos

(X) - Copiar uma Lista L1 para uma Lista L2 eliminando elementos repetidos. Use a função insere();
*/
int copia_listaNrept(struct tlista_ord *pl,struct tlista_ord *pl2) {
	if(pl -> qtnos == TAM)
		return -1;
	int i;
	for(i=0; i< pl->qtnos; i++){
		if(busca(pl2, pl->lista[i].chave) < 0)
			insere_lista2(pl2, pl->lista[i].chave);
	}
	return 1;
}
/*(12) Intercalar Elementos

(X) - Intercalar L1 com L2 gerando L3 sem elementos repetidos (considere L1 e L2 ordenadas);
*/
int intercala_elementos(struct tlista_ord *pl, struct tlista_ord *pl2, struct tlista_ord *pl3){
	int tamNecessario,i;
	int plIndex=0,pl2Index=0;

	tamNecessario = pl->qtnos + pl2->qtnos;

	if((TAM - tamNecessario) < 0)
		return -1;

	if(!verifica_ord(pl, pl->qtnos)){
		inserction_sort(pl, pl->qtnos);
		percurso(pl);
	}

	if(!verifica_ord(pl2, pl2->qtnos)){
		inserction_sort(pl2, pl2->qtnos);
		percurso(pl2);
	}
	for(i=0; i<tamNecessario; i++){
		if(plIndex < pl->qtnos){
			insere_lista(pl3, pl->lista[plIndex].chave);
			plIndex++;
		}
		if(pl2Index < pl2->qtnos){
			insere_lista(pl3, pl2->lista[pl2Index].chave);
			pl2Index++;
		}
	}
	return 1;
}
/*(13) interseção de Elementos

(X) - A partir de L1 e L2, gere L4 considerando os elementos repetidos em ambas as listas
(considere L1 e L2 ordenadas).
*/
int interc_elementos(struct tlista_ord *pl, struct tlista_ord *pl2, struct tlista_ord *plDestino){
	int menorLista,i;
	int plIndex=0,pl2Index=0;

	if(!verifica_ord(pl, pl->qtnos))
		inserction_sort(pl, pl->qtnos);

	if(!verifica_ord(pl2, pl2->qtnos))
		inserction_sort(pl2, pl2->qtnos);

	if(pl->qtnos < pl2->qtnos){
		for(i=0; i<pl->qtnos; i++){
			if(busca(pl2, pl->lista[i].chave) >= 0)
				insere_lista2(plDestino, pl->lista[i].chave);
		}
	}
	else{
		for(i=0; i<pl2->qtnos; i++){
			if(busca(pl, pl2->lista[i].chave) >= 0)
				insere_lista2(plDestino, pl2->lista[i].chave);
		}
	}

	return 1;
}

/*(13) Inverte Lista

( ) - Inverter uma lista L1;
*/
void inverte_lista(struct tlista_ord *pl){
	PILHA pilha;
	inicializaPilha(&pilha);

	int i;
	for(i=0; i< pl->qtnos; i++)
		empilha(&pilha, pl->lista[i].chave);

	inicializa_lista(pl);
	while(desempilha(&pilha, &i)){
		insere_lista(pl, i);
	}
}
// =========== LISTA SEQ. N' ORDENADA =========== //


// ========== PILHA ========== //
// (1) Inicializar a pilha:
void inicializaPilha(struct tpilha *ps){
	ps->topo = -1;
}
// (2) Testar pilha vazia
int pilhaVazia(struct tpilha *ps){
	if(ps->topo == -1)
		return 1;
	return 0;
}
// (3) Testar pilha cheia
int pilhaCheia(struct tpilha *ps){
	if(ps->topo == TAM-1)
		return 1;
	return 0;
}
// (4) Empilhamento
int empilha(struct tpilha *ps, int valor){
	if(pilhaCheia(ps))
		return 0;
	ps->topo++;
	ps->pilha[ps -> topo] = valor;
	return 1;
}
// (5) Desempilha
int desempilha(struct tpilha *ps,int *elem){
	if (pilhaVazia(ps)){
		printf("\nPilha Vazia");
		return 0;
	}
	*elem = ps->pilha[ps->topo];
	ps->topo--;
	return 1;
}
// ========== PILHA ========== //

void troca(int *elementoA,int *elementoB){
	int aux;
	aux = *elementoA;
	*elementoA = *elementoB;
	*elementoB = aux;
}
void inserction_sort(struct tlista_ord *pl, int tam){
	int i,j;
	for(j=1; j<tam; j++) {
		for(i=j; i>0 && pl->lista[i-1].chave > pl->lista[i].chave; i--){
			troca(&pl->lista[i-1].chave, &pl->lista[i].chave);
		}
	}
}