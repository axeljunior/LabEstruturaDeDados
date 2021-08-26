#include <stdio.h>
#include <stdlib.h>
/*
5) Escreva um programa que leia e imprima um vetor com n (lido via teclado) elementos
inteiros. 
Em seguida, gere uma Lista Simplesmente Encadeada ordenada com os elementos
do vetor. 
Imprima a lista gerada.
*/

struct lista_LSE{
	int info;
	struct lista_LSE *prox;
};

// =============================================================== // // Exibe a lista:
void exibe(struct lista_LSE *lista){
	printf("\n");
	while(lista != NULL){
		printf("%d\t", lista->info);
		lista = lista->prox;
	}
}
// Busca um dado na lista e retorna numero do Nó da primeira ocorrencia:
int busca(struct lista_LSE *lista, int val){
	int cont=1;
	if(!lista)
		return 0;

	while(lista){
		if(lista->info == val)
			return cont;
		
		lista = lista->prox;
		cont++;
	}

	return 0;
}
// Contar os nós da lista:
int contaNos(struct lista_LSE *lista){
	int cont;

	if(!lista)
		return 0;
	else{
		cont=0;
		while(lista) {
			lista = lista->prox;
			cont++;
		}
		return cont;
	}
}
// Função para concatenar duas LSEs. Retornar ponteiro para o inicio da lista concatenada.
struct lista_LSE *concatena (struct lista_LSE *lista1, struct lista_LSE  *lista2){
	struct lista_LSE *listaAux;
	if(!lista1)
		return lista2;
	listaAux = lista1;
	while(listaAux->prox)
		listaAux = listaAux->prox;

	listaAux->prox = lista2;
	return lista1;
}

// ================== FUNÇÕES PARA LSE NÃO ORDENADAS ================== //
//======================================================================//

// Função para inserir um nó na lista
struct lista_LSE *inserirFinal(struct lista_LSE *positInicial, int valor){

	struct lista_LSE *positAtual, *novoNo;

	novoNo = (struct lista_LSE*) malloc(sizeof(struct lista_LSE));
	novoNo->info = valor;
	novoNo->prox = NULL;

	if(!positInicial){
		positInicial = novoNo;
		return positInicial;
	}

	positAtual = positInicial;

	while(positAtual->prox)
		positAtual = positAtual->prox;
	
	positAtual->prox = novoNo;
	return positInicial;
}

// Função para remover o último nó da lista.
struct lista_LSE *removerFinal(struct lista_LSE *positInicial){

	struct lista_LSE *positAtual, *positFinal;

	if(!positInicial)
		return NULL;
	if(!positInicial->prox){
		free(positInicial);
		return NULL;
	}
	positAtual = positInicial;
	while(positAtual->prox) {
		positFinal = positAtual;
		positAtual = positAtual->prox;
	}

	positFinal->prox = NULL;
	free(positAtual);
	return positInicial;
}
// Função para remover o k-ésimo nó da lista.
struct lista_LSE *removeNo(struct lista_LSE *positInicial, int no){
	struct lista_LSE *positAtual, *positAux;
	int cont;

	if(no < 1 || no > contaNos(positInicial) )
		return positInicial;
	else if(no==1){
		if(!positInicial->prox){
			free(positInicial); 
			return NULL;
		}else{
			positAux = positInicial->prox; 
			positInicial->prox = NULL;
			free(positInicial); 
			return positAux;
		}
	}else{
		cont = 1;
		positAtual = positInicial; 

		while(cont != no) {
			positAux = positAtual;       
			positAtual = positAtual->prox;
			cont++;
		}
		positAux->prox = positAtual->prox;

		free(positAtual);
		return positInicial;
	}
}
// ================== FUNÇÕES PARA LSE ORDENADA ================== //
//=================================================================//

// Insere em LSE Ordenada
struct lista_LSE *insereOrd(struct lista_LSE *positInicial, int valor){
	
	struct lista_LSE *positAux, *novoNo, *positAtual;

	novoNo = (struct lista_LSE*) malloc(sizeof(struct lista_LSE));
	novoNo->info = valor;

	if(!positInicial){
		novoNo->prox = NULL;
		return novoNo;
	}else{
		positAtual = positInicial;
		while(positAtual && valor > positAtual->info){ 
			positAux = positAtual;
			positAtual = positAtual->prox; 
		}
		if(!positAtual){ 
			positAux->prox = novoNo;
			novoNo->prox = NULL;
			return positInicial;
		}
		if(valor < positAtual->info){ 
			novoNo->prox = positAtual;
			if(positAtual != positInicial){
				positAux->prox = novoNo; 
				return positInicial;
			}
			return novoNo;
		}
		return positInicial;
	}
}
// ======================================================================== // Funções da Lista
int main(){
	int valor,tamanhoVetor=0,op=1;

	int *vetor = NULL;
	struct lista_LSE *lista = NULL;


	while(op){
		if(!vetor)
			vetor = (int*) malloc(sizeof(int));
		else
			vetor = realloc(vetor, 1*sizeof(int));

		if(!vetor){
			printf ("\nErro: Falha ao alocar memoria \n");
        	exit(1);
		}

		printf("\nInforme um valor para o vetor\n ==> ");
		scanf("%d",&valor);
		vetor[tamanhoVetor] = valor;

		printf("\nDesejar adicionar outro valor ao vetor?\n 1:Sim/0:Não\n ==> ");
		scanf("%d",&op);
		switch(op){
			case 1:
				tamanhoVetor++;
				break;
			case 0:
				break;
			default:
				printf("\nOpção invalida");
		}
	}

	for(int i=0; i<tamanhoVetor; i++)
		lista = insereOrd(lista, vetor[i]);
	printf("\nLista: \n");
	exibe(lista);

	free(lista);
}