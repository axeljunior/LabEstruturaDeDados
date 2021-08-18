#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
4) Dada uma estrutura livraria com código, título, autor, ano e editora. Faça um programa,usando Listas Simplesmente Encadeadas, com opções para:
	I- Inserir um livro na lista,          (X)
	B- Buscar um livro na lista,           (X)
	R- Remover um livro da lista,          (X)
	E- Escrever todos os livros da lista.  (X)
Na busca, leia um código qualquer e mostre título e autor, caso o código exista na lista. 
A lista deve conter n livros lidos via teclado.
*/
struct lista_LSE{
	int codigo;

	char titulo[50];
	char autor[50];
	char editora[50];

	struct lista_LSE *prox;
};

// ======================================================================= // Funções da Lista
// Exibe a lista:
void exibe(struct lista_LSE *lista){
	printf("\n");
	while(lista != NULL){
		printf("\n ============== ");
		printf("\nTitulo: %s |Codigo: %d", lista->titulo, lista->codigo);
		printf("\nEditora: %s", lista->editora);
		printf("\nNome do autor: %s", lista->autor);
		printf("\n ============== \n");
		lista = lista->prox;
	}
	printf("\n");
}
// Exibe a lista:
void exibeNo(struct lista_LSE *lista, int no){
	int cont=1;
	printf("\n");
	while(cont != no){
		lista = lista->prox;
		cont++;
	}
	printf("\n ==============");
	printf("\nTitulo: %s", lista->titulo);
	printf("\nEditora: %s", lista->editora);
	printf("\nNome do autor: %s", lista->autor);
	printf("\n ============== \n");
	printf("\n");
}
// Busca um dado na lista e retorna numero do Nó da primeira ocorrencia:
int busca(struct lista_LSE *lista, float val){
	int cont=1;
	if(!lista)
		return 0;

	while(lista){
		if(lista->codigo == val)
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
struct lista_LSE *inserirFinal(struct lista_LSE *positInicial, int cod, char titulo[],char autor[],char editora[]){

	struct lista_LSE *positAtual, *novoNo;

	novoNo = (struct lista_LSE*) malloc(sizeof(struct lista_LSE));
	
	novoNo->codigo = cod;
	novoNo->prox = NULL;

	//------
	strcpy(novoNo->titulo,titulo);
	strcpy(novoNo->autor,autor);
	strcpy(novoNo->editora,editora);
	//------

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
		printf("\n %s ... Removido!\n",positAtual->titulo);
		free(positAtual);
		return positInicial;
	}
}
// ======================================================================== // Funções da Lista

int main(){
	struct lista_LSE *lista = NULL;
	char op;
	char titulo[50],autor[50],editora[50];
	int n,auxInt,quantidade=0,cod=1,run=1;

	while(run){
		printf("\n(I) - Inserir um livro na lista.");
		printf("\n(B) - Buscar um livro na lista.");
		printf("\n(R) - Remover um livro da lista.");
		printf("\n(E) - Escrever todos os livros da lista.");
		printf("\n(S) - Sair");
		printf("\n ==> ");
		scanf("%c",&op);
		fgetc(stdin);
		switch(op){
			case 'I':
				printf("\nInforme a quantidade de livros que deseja inserir \n ==> ");
				scanf("%d",&n);
				fgetc(stdin);
				while(quantidade != n){
					printf("\n%d/%d",n,quantidade+1);
					printf("\nInsira o titulo do livro\n ==> ");
					gets(titulo);
					printf("\nInsira o nome do autor\n ==> ");
					gets(autor);
					printf("\nInsira o nome da editora\n ==> ");
					gets(editora);
					cod++;
					lista = inserirFinal(lista, cod, titulo, autor, editora);
					quantidade++;
				}
				break;
			case 'B':
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				printf("\nInsira o codigo do livro\n ==> ");
				scanf("%d",&auxInt);
				fgetc(stdin);
				exibeNo(lista,busca(lista,auxInt));
				break;
			case 'R':
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				printf("\nInsira o codigo do livro que deseja remover\n ==> ");
				scanf("%d",&auxInt);
				fgetc(stdin);
				lista = removeNo(lista,busca(lista,auxInt));
				break;
			case 'E':
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				exibe(lista);
				break;
			case 'S':
				run=0;
				break;
			default:
				printf("\nOpção Invalida!!\n");
		}

	}
}
