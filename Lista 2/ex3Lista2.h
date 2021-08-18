#include <stdio.h>
#include <stdlib.h>

/*
3) Escreva um programa, que contém uma estrutura do tipo Lista Simplesmente Encadeada que
armazena números reais. Execute o menu de opções abaixo com as funções para:
	1) Inserir um elemento na lista                        (X)
	2) Contar os nós da lista                              (X)
	3) Buscar um elemento (lido via teclado) na lista      (X)
	4) Remover um elemento k (lido via teclado) da lista   (X)
	5) Imprimir a lista                                    (X)
	6) Sair
O programa acaba quando o usuário escolher a opção 6.
*/

struct lista_LSE{
	float info;
	struct lista_LSE *prox;
};

// ======================================================================== // Funções da Lista
// Exibe a lista:
void exibe(struct lista_LSE *lista){
	printf("\n");
	while(lista != NULL){
		printf("%.2f\t", lista->info);
		lista = lista->prox;
	}
	printf("\n");
}
// Exibe a lista:
void exibeValorDoNo(struct lista_LSE *lista, int no){
	int cont=1;
	printf("\n");
	while(cont != no){
		lista = lista->prox;
		cont++;
	}
	printf("%.2f\t", lista->info);
	printf("\n");
}
// Busca um dado na lista e retorna numero do Nó da primeira ocorrencia:
int busca(struct lista_LSE *lista, float val){
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
struct lista_LSE *inserirFinal(struct lista_LSE *positInicial, float valor){

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
// ======================================================================== //
int main(){
	struct lista_LSE *lista = NULL;
	
	int op,auxInt,run=1;
	float auxFloat;

	while(run){
		printf("\n(1) - Inserir um elemento na lista");
		printf("\n(2) - Contar os nós da lista");
		printf("\n(3) - Buscar um elemento na lista");
		printf("\n(4) - Remover um elemento da lista ");
		printf("\n(5) - Imprimir a lista");
		printf("\n(6) - Sair");
		printf("\n ==> ");
		scanf("%d",&op);
		printf("\n ============== \n");
		switch(op){
			case 1:
				printf("\nInforme um Valor\n ==> ");
				scanf("%f",&auxFloat);
				lista = inserirFinal(lista, auxFloat);
				break;
			case 2:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				auxInt = contaNos(lista);
				printf("\nA Lista possui %d nós\n", auxInt);
				break;
			case 3:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				printf("\nInforme o valor que deseja buscar na lista\n ==> ");
				scanf("%f",&auxFloat);
				auxInt = busca(lista, auxFloat);
				if(!auxInt){
					printf("\nO valor não existe na lista!!!");
					break;
				}
				exibeValorDoNo(lista,auxInt);
				break;
			case 4:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				printf("\nInforme o valor que deseja remover da lista\n ==> ");
				scanf("%f",&auxFloat);
				auxInt = busca(lista, auxFloat);
				if(!auxInt){
					printf("\nO valor não existe na lista!!!");
					break;
				}
				lista = removeNo(lista,auxInt);
				break;
			case 5:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}

				exibe(lista);
				break;
			case 6:
				run=0;
				break;
			default:
				printf("\nOpção Invalida!!\n");
		}
		printf("\n ============== \n");

	}
}
// =============================================================== //
// =============================================================== //

