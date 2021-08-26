#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista_LDE{
	int chave;
	char nome[50];
	struct lista_LDE *eprox;
	struct lista_LDE *dprox;
};

/*
18) Escreva um programa que insira n (lido via teclado) nós numa Lista Duplamente
Encadeada Ordenada que armazena em cada nó uma chave inteira e um nome. 
Em seguida, as seguintes operações devem ser definidas:
	a) Buscar uma chave na lista;
	b) Inserir um novo elemento na lista mantendo a ordem;
	c) Remover um elemento da lista;
	d) Imprimir os valores da lista;
	e) Copiar uma lista L1 para uma lista L2.
*/

// ======================  Funções da Lista ====================== // 
// =============================================================== //

// 1) Função para imprimir a LDE.
int exibe(struct lista_LDE *positInicial){
	if(!positInicial)
		return 0;
	while(positInicial){
		printf("\n --------\n Chave: %d", positInicial->chave);
		printf("\n Nome: %s\n --------\n ", positInicial->nome);

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
	novoNo->chave = valor;

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
	novoNo->chave = valor;
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
		noDaLista->eprox->dprox = noInserido;     // A 1 2 B 3 4 | 2 -> B |
	noInserido->eprox = noDaLista->eprox; 	  	  // A 1 2 B 3 4  | 2 <- B |
	noInserido->dprox = noDaLista; 				 // A 1 2 B 3 4   | B -> 3 |
	noDaLista->eprox = noInserido; 				// A 1 2 B 3 4    | 3 <- B |
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
	novoNo->chave = valor;

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
// 3.3) Função para inserir de maneira ordenada
struct lista_LDE *insereOrd(struct lista_LDE *positInicial,char nome[], int valor){
	struct lista_LDE *novoNo, *positAtual;

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	// ----
	strcpy(novoNo->nome, nome);
	novoNo->chave = valor;	
	// ----

	if(!positInicial){
		novoNo->eprox = novoNo->dprox = NULL;
		return novoNo;
	}else{
		positAtual = positInicial;
		while(positAtual->dprox && valor > positAtual->chave)
			positAtual = positAtual->dprox;

		if(!positAtual->dprox && valor > positAtual->chave){ 
			positAtual->dprox = novoNo;
			novoNo->eprox = positAtual;
			novoNo->dprox = NULL;
			return positInicial;
		}
		if(valor < positAtual->chave){
			insereNo(novoNo, positAtual);

			if(positAtual==positInicial)
				return novoNo;
		}

		return positInicial;
	}
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
	novaLista = insereOrd(novaLista, positAtual->nome, positAtual->chave);
	
	while(positAtual->dprox){
		positAtual = positAtual->dprox;
		novaLista = insereOrd(novaLista, positAtual->nome, positAtual->chave);
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
(X) -	a) Buscar uma chave na lista;
(X) -	b) Inserir um novo elemento na lista mantendo a ordem;
(X) -	c) Remover um elemento da lista;
(X) -	d) Imprimir os valores da lista;
(X) -	e) Copiar uma lista L1 para uma lista L2.
*/
// =============================================================== // 

int busca_seqOrd(struct lista_LDE *lista, int tamanho, int alvo) {
	int i;
	for(i=0; i < tamanho && alvo > lista->chave; i++)
		lista = lista->dprox;

	if((i==tamanho) || (alvo != lista->chave))
		return 0;
	return 1;
}

int main(){
	struct lista_LDE *lista = NULL;
	struct lista_LDE *lista2 = NULL;
	int n=5,k;

	/*
		Ao contrario das outras questões a 10 - 18 - 19 não citam "menu" no enunciado então imagino que a ideia era fazer ao longo da main mesmo.
	*/

	// - Criar uma lista LDE com 'n' nós com Chave e Nome.
	printf("\nInforme a quantidade de nós\n ==> ");
	scanf("%d",&n);	/*
		Essa questão também não cita "Menu" então imagino que queira as operações de forma sequencial na main
	*/

	while(n--)
		lista = insereOrd(lista, "Nome", n+1);
	exibe(lista);

	// (X) -  a) Buscar uma chave na lista;
	if(busca_seqOrd(lista, conta_nos(lista), 5))
		printf("\nAchou");
	else
		printf("\nNão achou");

	// (X) -  b) Inserir um novo elemento na lista mantendo a ordem;
	printf("\nInsira um Nome \n ==> ");
	lista = insereOrd(lista, "Nome", 42);

	// (X) -  c) Remover um elemento da lista;
	printf("\nInsira a Chave que deseja remover \n ==> ");
	lista = remove_no(lista, 2);
	// (X) -  d) Imprimir os valores da lista;
	exibe(lista);
	// (X)  -  e) Copiar uma lista L1 para uma lista L2.
	lista2 = copia_lista(lista);

	free(lista);
	free(lista2);
}