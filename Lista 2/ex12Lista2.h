#include <stdio.h>
#include <stdlib.h>

struct lista_LDE{
	int info;

	struct lista_LDE *eprox;
	struct lista_LDE *dprox;
};

/*
12) Considere uma estrutura de Lista Duplamente Encadeada que contém números inteiros.
Escreva um programa que leia e imprima duas listas L1 e L2. 
Logo após, crie uma função que concatena a lista L2 no final da lista L1. A função deve retornar ponteiro para o início da lista concatenada. 
Imprima a lista concatenada.
*/
// ======================  Funções da Lista ====================== // 
// =============================================================== // 
// 1) Função para imprimir a LDE.
int exibe(struct lista_LDE *positInicial){
	if(!positInicial)
		return 0;
	while(positInicial){
		printf("%d\t", positInicial->info);
		positInicial = positInicial->dprox;
	}
	return 1;
}

// 2) Função para contar os nós da LDE. 
int conta_nos(struct lista_LDE *positInicial){
	if(!positInicial)
		return 0;

	int cont=0;
	while(positInicial){
		cont++;
		positInicial = positInicial->dprox;
	}
	return cont;
}

// 3) Função para inserir um nó no final da LDE.
struct lista_LDE *insere(struct lista_LDE *positInicial, int valor){
	struct lista_LDE *novoNo, *positAtual;

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	novoNo->info = valor;

	if(!positInicial){
		novoNo->eprox = novoNo->dprox = NULL;
		return novoNo;
	}
	else{
		positAtual = positInicial;

		while(positAtual->dprox)
			positAtual = positAtual->dprox;

		positAtual->dprox = novoNo;
		novoNo->eprox = positAtual;
		novoNo->dprox = NULL;

		return positInicial;
	}
} 
// 3.1) Função para inserir um nó na frente da LDE.
struct lista_LDE *insere_frente(struct lista_LDE *positInicial, int valor){
	struct lista_LDE *novoNo;

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	novoNo->info = valor;
	novoNo->eprox = NULL;

	if(!positInicial){
		novoNo->dprox = NULL;
		return novoNo;
	}else{
		novoNo->dprox = positInicial;
		positInicial->eprox = novoNo;
		return novoNo;
	}
}

//3.2) Função para inserir um nó antes do k-ésimo nó na LSEC.
struct lista_LDE *insere_AntesNo(struct lista_LDE *positInicial, int no, int valor){
	struct lista_LDE *positAtual, *positAux, *novoNo;
	int cont=1;

	if( no < 1 || no > conta_nos(positInicial) ){
		printf("\nValor do nó não existe na lista\n");
		return positInicial;
	}

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	novoNo->info = valor;

	if(no == 1){
		novoNo->eprox = NULL;

		novoNo->dprox = positInicial;
		positInicial->eprox = novoNo;
		return novoNo;
	}
	positAtual = positInicial;
	while(cont != no) {
		positAux = positAtual;
		positAtual = positAtual->dprox;
		cont++;
	}

	positAux->dprox = novoNo;
	novoNo->eprox = positAux;
	novoNo->dprox = positAtual;
	positAtual->eprox = novoNo;

	return positInicial;
}

// 4) Função para remover o k-ésimo nó da LDE.
struct lista_LDE *remove_no(struct lista_LDE *positInicial, int no){
	struct lista_LDE *positAtual, *positAux, *positAux2;
	int cont;
	if( no<1 || no>conta_nos(positInicial) ){
		printf("\nValor do nó não existe na lista\n");
		return positInicial;
	}else if(no == 1){
		if(!positInicial->dprox){
			free(positInicial);
			return NULL;
		}else{
			positAux = positInicial;
			positInicial = positInicial->dprox;
			positInicial->eprox = NULL;

			free(positAux);
			return positInicial;
		}
	}else{
		cont = 1;
		positAtual = positInicial;
		while(cont != no){ 
			positAtual = positAtual->dprox;
			cont++;
		}

		positAux = positAtual->dprox;
		positAux2 = positAtual->eprox;
		positAux2->dprox = positAux;

		if(positAux != NULL)
			positAux->eprox = positAux2;
		free(positAtual);
	}
	return(positInicial);
} 

// 5) Copia lista Deepcopy
struct lista_LDE *copia_lista(struct lista_LDE *lista){
	struct lista_LDE *novaLista=NULL,*positAtual;

	if(!lista){
		return NULL;
	}
	positAtual = lista;
	novaLista = insere(novaLista, positAtual->info);
	
	while(positAtual->dprox){
		positAtual = positAtual->dprox;
		novaLista = insere(novaLista, positAtual->info);
	}
	return novaLista;
}
// 6) Concatena
struct lista_LDE *concatena(struct lista_LDE *lista1, struct lista_LDE  *lista2){
	struct lista_LDE *listaAux;
	if(!lista1)
		return lista2;
	listaAux = lista1;
	while(listaAux->dprox)
		listaAux = listaAux->dprox;

	listaAux->dprox = lista2;
	return lista1;
}

// =============================================================== // 
/*
Considere uma estrutura de Lista Duplamente Encadeada que contém números inteiros.

Escreva um programa que leia e imprima duas listas L1 e L2. 
Logo após, crie uma função que concatena a lista L2 no final da lista L1. A função deve retornar ponteiro para o início da lista concatenada. 
Imprima a lista concatenada.
*/
// =============================================================== // 
int main(){
	struct lista_LDE *lista = NULL;
	struct lista_LDE *lista2 = NULL;

	int n=5,auxInt;

	while(n--){
		lista = insere_frente(lista,n);
		auxInt = n*-1;
		lista2 = insere(lista2,auxInt);
	}

	printf("\nConteudo da lista 1: \n");
	exibe(lista);
	printf("\nConteudo da lista 2: \n");
	exibe(lista2);

	printf("\nConteudo na lista Concatenada: \n");
	lista = concatena(lista,lista2);
	exibe(lista);

	free(lista);
	free(lista2);
}