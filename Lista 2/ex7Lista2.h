#include <stdio.h>
#include <stdlib.h>

/*
(7) 
Faça um programa que leia números inteiros e insira-os numa Lista Simplesmente Encadeada Circular. 
Imprima a lista. 
Imprima o número de nós da lista. 
Em seguida, chame uma função que receba a Lista Simplesmente Encadeada Circular e o valor do k-ésimo nó (lido e testado na main) e divida a lista no k-ésimo nó. 
Retorne ponteiro para o final da primeira parte da lista. Não esqueça de tratar o ponteiro do final da lista restante.
Protótipo: struct lista *divideKlsec(struct lista *p, int k);
*/

struct lista_LSEC{
	int info;
	struct lista_LSEC *prox;
};

// ======================  Funções da Lista ====================== // 
// =============================================================== // 
// Imprime os elementos da lista:
int exibe(struct lista_LSEC *positFinal){
	struct lista_LSEC *positAtual;

	if(!positFinal)
		return 0;

	positAtual = positFinal->prox;
	printf("\n");
	while(positAtual != positFinal){
		printf("%d\t", positAtual->info);
		positAtual = positAtual->prox;
	}

	if(positAtual == positFinal)
		printf("%d\t", positFinal->info);

	printf("\n");
	return 1;
}
// Contar os nós da lista:
int conta_nos(struct lista_LSEC *positFinal){ 
	struct lista_LSEC *positAtual;
	int cont = 1;

	if(!positFinal)
		return 0;
	positAtual = positFinal;

	while(positAtual->prox != positFinal){
		cont++;
		positAtual = positAtual->prox;
	}
	return cont;
}

// Função para inserir um nó na lista:
struct lista_LSEC *inserir(struct lista_LSEC *positFinal, int valor){

	struct lista_LSEC *novoNo;

	novoNo = (struct lista_LSEC*) malloc(sizeof(struct lista_LSEC));
	novoNo->info = valor;

	if(!positFinal){
		novoNo->prox = novoNo;
		return novoNo;
	}

	novoNo->prox = positFinal->prox;
	positFinal->prox = novoNo;

	return novoNo;
}
// Função para inserir um nó na lista:
struct lista_LSEC *inserir_inicio(struct lista_LSEC *positFinal, int valor){

	struct lista_LSEC *novoNo;

	novoNo = (struct lista_LSEC*) malloc(sizeof(struct lista_LSEC));
	novoNo->info = valor;

	if(!positFinal){
		novoNo->prox = novoNo;
		return novoNo;
	}

	novoNo->prox = positFinal->prox;
	positFinal->prox = novoNo;

	return positFinal;
}

//Divide a lista no No:
struct lista_LSEC *divideKlsec(struct lista_LSEC *p, int k){
	struct lista_LSEC *novaLista,*positAtual;
	int cont=1;

	if(p == p->prox) 
		return NULL;

	positAtual = p->prox;
	while(cont != k) {
		positAtual = positAtual->prox;
		cont++;
	}

	novaLista = p;
	while(novaLista->prox != positAtual){
		novaLista = novaLista->prox;

	}

	novaLista->prox = p->prox;
	p->prox = positAtual;

	return novaLista;
}
// =============================================================== //
// =============================================================== //

int main(){
	struct lista_LSEC *lista = NULL;

	lista = inserir(lista,0);

	lista = inserir_inicio(lista,-1);
	lista = inserir_inicio(lista,-2);
	lista = inserir_inicio(lista,-3);
	lista = inserir_inicio(lista,-4);
	lista = inserir_inicio(lista,-5);

	lista = inserir(lista,1);
	lista = inserir(lista,2);
	lista = inserir(lista,3);
	lista = inserir(lista,4);
	lista = inserir(lista,5);

	printf("\nConteudo na lista: ");
	exibe(lista);
	printf("Quantidade de Nós: %d\n",conta_nos(lista));

	printf("\nDividindo lista...\n");

	struct lista_LSEC *numerosNegativos;
	numerosNegativos = divideListaNo(lista,6);

	printf("\nConteudo na lista 1: ");
	exibe(lista);
	printf("Conteudo na lista 2: ");
	exibe(numerosNegativos);
}
