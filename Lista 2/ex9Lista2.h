#include <stdio.h>
#include <stdlib.h>

/*
9) Escreva um programa, que contém uma estrutura do tipo Lista Simplesmente Encadeada Circular que armazena números inteiros e execute as seguintes funções:

	a) Criar uma LSEC com n nós;
	b) Imprimir os elementos da lista;
	c) Contar os elementos da lista;
	d) Remover o k-ésimo nó da lista, o nó k deve ser indicado pelo usuário (testar se tal elemento existe);
	e) Criar e imprimir uma cópia da lista;
	f) Inserir um nó antes do k-ésimo nó da lista, o nó k deve ser indicado pelo usuário.

*/

struct lista_LSEC{
	int info;
	struct lista_LSEC *prox;
};

// ======================  Funções da Lista ====================== // 
// =============================================================== // 
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

// Função para inserir um nó na lista
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
// Função para remover o k-ésimo nó da LSEC não vazia.
struct lista_LSEC *remove_no(struct lista_LSEC *positFinal, int no){
	struct lista_LSEC *positAtual, *positAuxiliar; 
	int cont;

	if( no<1 || no>conta_nos(positFinal) ){
		printf("\nValor do nó não existe na lista\n");
		return positFinal;
	}
	else if(no == 1){
		if(positFinal->prox == positFinal){
			free(positFinal);
			return NULL;
		}
		else{
			positAuxiliar = positFinal->prox;
			positFinal->prox = positAuxiliar->prox;
			free(positAuxiliar);
			return positFinal;
		}
	}
	else{
		cont = 1;
		positAtual = positFinal->prox;
		while(no != cont) {
			positAuxiliar = positAtual;
			positAtual = positAtual->prox;
			cont++;
		}
		
		positAuxiliar->prox = positAtual->prox;

		free(positAtual);
		return positFinal;
	}
}
//7) Função para inserir um nó após o k-ésimo nó na LSEC.
struct lista_LSEC *insere_AntesNo(struct lista_LSEC *positFinal, int no, int valor){
	struct lista_LSEC *positAtual, *novoNo;
	int cont=1;

	if( no < 1 || no > conta_nos(positFinal) ){
		printf("\nValor do nó não existe na lista\n");
		return positFinal;
	}else if(no == 1){
		positFinal = inserir(positFinal,valor);
		return positFinal;
	}

	positAtual = positFinal->prox;
	while(cont != no-1) {
		positAtual = positAtual->prox;
		cont++;
	}

	positAtual = inserir(positAtual,valor);
	return positFinal;
}
//Copia lista Deepcopy
struct lista_LSEC *copia_lista(struct lista_LSEC *lista){
	struct lista_LSEC *novaLista=NULL,*positAtual;

	if(!lista){
		printf("\nLista vazia\n");
		return NULL;
	}
	positAtual = lista->prox;
	novaLista = inserir(novaLista,positAtual->info);

	while(positAtual != lista){
		positAtual = positAtual->prox;
		novaLista = inserir(novaLista,positAtual->info);
	}
	return novaLista;
}
// =============================================================== //
/*
	(X) - a) Criar uma LSEC com n nós;
	(X) - b) Imprimir os elementos da lista;
	(X) - c) Contar os elementos da lista;
	(X) - d) Remover o k-ésimo nó da lista, o nó k deve ser indicado pelo usuário (testar se tal
	elemento existe);
	(X) - e) Criar e imprimir uma cópia da lista;
	(X) - f) Inserir um nó antes do k-ésimo nó da lista, o nó k deve ser indicado pelo usuário.
*/
// =============================================================== //

int main(){
	struct lista_LSEC *lista = NULL;
	int n,k;
	/*
		Como a questão não cita "Menu" asumi que queria as funções de forma sequencial na main
	*/

	//	(X) - a) Criar uma LSEC com n nós;
	printf("\nInsira a quantidade de nós: \n ==> ");
	scanf("%d", &n);
	while(n--){
		printf("\nInforme o Valor: \n ==> ");
		scanf("%d", &k);
		lista = inserir(lista,k);
	}

	//	(X) - b) Imprimir os elementos da lista;
	printf("\nConteudo na lista: ");
	exibe(lista);
	
	//	(X) - c) Contar os elementos da lista;
	printf("Quantidade de Nós: %d\n",conta_nos(lista));

	//	(X) - d) Remover o k-ésimo nó da lista, o nó k deve ser indicado pelo usuário (testar se tal elemento existe);
	/*
		A função testa internamente se k esta no range da lista ou se é menor que 1
	*/
	printf("\nInforme o nó para remover: \n ==> ");
	scanf("%d", &k);
	lista = remove_no(lista, k);

	//	(X) - e) Criar e imprimir uma cópia da lista;
	/*
		Imagino que a ideia era fazer uma Deep copy
	*/
	struct lista_LSEC *listaCopiada=NULL;
	listaCopiada = copia_lista(lista);

	printf("\nConteudo na lista: ");
	exibe(lista);
	printf("Conteudo na lista Copiada: ");
	exibe(listaCopiada);


	/*
	// Demonstrando que as listas podem ser alteradas de forma indpendente
	lista->info = 43;

	printf("\nConteudo na lista: ");
	exibe(lista);
	printf("Conteudo na lista Copiada: ");
	exibe(listaCopiada);
	*/

	//(X) - f) Inserir um nó antes do k-ésimo nó da lista, o nó k deve ser indicado pelo usuário.

	printf("\nInforme na frente de qual nó deseja inserir: \n ==> ");
	scanf("%d", &k);
	printf("\nInforme o Valor: \n ==> ");
	scanf("%d", &n);
	lista = insere_AntesNo(lista,k,n);
	
	printf("\nConteudo na lista: ");
	exibe(lista);
}
