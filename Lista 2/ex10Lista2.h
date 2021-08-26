#include <stdio.h>
#include <stdlib.h>

struct lista_LDE{
	int info;

	struct lista_LDE *eprox;
	struct lista_LDE *dprox;
};

/*
10) Escreva um programa, que contém uma estrutura do tipo Lista Duplamente Encadeada que
armazena números inteiros e execute as seguintes funções:
	a) Criar uma LDE com n nós;
	b) Imprimir os elementos da lista;
	c) Contar os elementos da lista;
	d) Remover o k-ésimo nó da lista, o nó k deve ser indicado pelo usuário (testar se tal elemento existe);
	e) Criar e imprimir uma cópia da lista;
	f) Inserir um nó antes do k-ésimo nó da lista, o nó k deve ser indicado pelo usuário.
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
void insereNo(struct lista_LDE *noInserido, struct lista_LDE *noDaLista){ 
	if( noDaLista->eprox != NULL )
		noDaLista->eprox->dprox = noInserido;
	noInserido->eprox = noDaLista->eprox;
	noInserido->dprox = noDaLista;
	noDaLista->eprox = noInserido;
}
// 
struct lista_LDE *insere_AntesNo(struct lista_LDE *positInicial, int no, int valor){
	struct lista_LDE *positAtual, *novoNo;
	int cont=1;

	if( no < 1 || no > conta_nos(positInicial) ){
		printf("\nValor do nó não existe na lista\n");
		return positInicial;
	}

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	novoNo->eprox = NULL;
	novoNo->dprox = NULL;
	novoNo->info = valor;

	positAtual = positInicial;
	while(cont != no) {
		positAtual = positAtual->dprox;
		cont++;
	}
	
	insereNo(novoNo, positAtual);
	if(no == 1)
		return novoNo;
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
(X)	a) Criar uma LDE com n nós;
(X)	b) Imprimir os elementos da lista;
(X)	c) Contar os elementos da lista;
(X)	d) Remover o k-ésimo nó da lista, o nó k deve ser indicado pelo usuário (testar se tal elemento existe);
(X)	e) Criar e imprimir uma cópia da lista;
(X)	f) Inserir um nó antes do k-ésimo nó da lista, o nó k deve ser indicado pelo usuário.
*/
// =============================================================== // 
int main(){
	struct lista_LDE *lista = NULL;
	struct lista_LDE *lista2 = NULL;

	int n,k;
	
	/*
		Ao contrario das outras questões a 10 - 18 - 19 não citam "menu" no enunciado então imagino que a ideia era fazer ao longo da main mesmo.
	*/

	//	(X) - a) Criar uma LSEC com n nós;
	printf("\nInsira a quantidade de nós: \n ==> ");
	scanf("%d", &n);
	while(n--){
		printf("\nInforme o Valor: \n ==> ");
		scanf("%d", &k);
		lista = insere(lista,k);
	}

	// (X)	b) Imprimir os elementos da lista;
	printf("\nConteudo da lista: \n");
	exibe(lista);

	//(X)	c) Contar os elementos da lista;
	printf("\nQuantidade de Elementos na Lista: %d\n", conta_nos(lista));

	//(X)  d) Remover o k-ésimo nó da lista, o nó k deve ser indicado pelo usuário;
	printf("\nInforme o nó para remover: \n ==> ");
	scanf("%d", &k);
	lista = remove_no(lista, k);

	//(X)  e) Criar e imprimir uma cópia da lista;
	lista2 = copia_lista(lista);
	printf("\nConteudo da lista original: \n");
	exibe(lista);
	printf("\nConteudo da lista copiada: \n");
	exibe(lista2);

	//(X)  f) Inserir um nó antes do k-ésimo nó da lista, o nó k deve ser indicado pelo usuário.
	printf("\nInforme antes de qual nó deseja inserir: \n ==> ");
	scanf("%d", &k);
	printf("\nInforme o Valor: \n ==> ");
	scanf("%d", &n);
	lista = insere_AntesNo(lista,k,n);
	exibe(lista);

	free(lista);
	free(lista2);
}