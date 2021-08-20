struct lista_LDE{
	int info;

	struct lista_LDE *eprox;
	struct lista_LDE *dprox;
};

int exibe(struct lista_LDE *);
int conta_nos(struct lista_LDE *);
struct lista_LDE *copia_lista(struct lista_LDE *);
struct lista_LDE *concatena(struct lista_LDE *, struct lista_LDE  *);

struct lista_LDE *insere(struct lista_LDE *, int);
struct lista_LDE *insere_frente(struct lista_LDE *, int);
struct lista_LDE *remove_no(struct lista_LDE *, int);

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


// 4) Função para remover o k-ésimo nó da LDE.
struct lista_LDE *remove_no(struct lista_LDE *positInicial, int no){
	struct lista_LDE *positAtual, *positAux, *positAux2;
	int cont;
	if( no<1 || no>conta_nos(positInicial) ){
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



// ============== ??????? ====================
// ===========================================

//7) Função para inserir um nó apontado por p após um nó apontado por x,onde x aponta para algum nó de uma LDE. Utilize apenas as variáveis p e x na função.
void insereNo(struct lista_LDE *p, struct lista_LDE *x){ 
	if( x->dprox != NULL)
		x->dprox->eprox = p;
	p->dprox = x->dprox;
	p->eprox = x;
	x->dprox = p;
}
//8) Função para remover um nó apontado por x de uma LDE, onde y aponta para o início da lista. Retorne ponteiro para o início da lista resultante. Utilize apenas as variáveis y e x na função.
struct lista_LDE *removeNo(struct lista_LDE *y, struct lista_LDE *x){
	if(y == x){
		if(y -> dprox == NULL)
			y = NULL;
		else{
			y = y -> dprox;
			y -> eprox = NULL;
		}
	}else{
		if(!x->dprox)
			x->eprox->dprox = NULL;
		else{
			x->eprox->dprox = x->dprox;
			x->dprox->eprox = x->eprox;
		}
	}
	free(x);
	return y;
}
// ============== ??????? ====================
// ===========================================

// =============================================================== // 
// =============================================================== // 

int main(){
	struct lista_LDE *lista = NULL;
	struct lista_LDE *lista2 = NULL;

	lista = insere(lista, 0);
	lista = insere(lista, 1);
	lista = insere(lista, 2);
	lista = insere(lista, 3);

	printf("\nQuantidade de Nós: %d", conta_nos(lista));
	printf("\nConteudo da lista: \n");
	exibe(lista);


	printf("\n\nRemovendo o 1ºNo da Lista ...");
	lista = remove_no(lista, 1);
	printf("\nConteudo da lista: \n");
	exibe(lista);

	printf("\n\nCopiando Lista ...");
	lista2 = copia_lista(lista);
	printf("\nConteudo da lista original: \n");
	exibe(lista);
	printf("\nConteudo da lista copiada: \n");
	exibe(lista2);

	printf("\n\nModificando Lista2 ...");
	if(lista2){
		lista2->info *= -1;
		lista2->dprox->info *= -1;
		lista2->dprox->dprox->info *= -1;

	}
	printf("\nConteudo da lista original: \n");
	exibe(lista);
	printf("\nConteudo da lista copiada: \n");
	exibe(lista2);

	printf("\n\nConcatenando as listas ...");
	lista = concatena(lista,lista2);
	printf("\nConteudo da lista concatenada: \n");
	exibe(lista);

	insereNo(lista->dprox,lista);
	printf("\nConteudo da lista: \n");
	exibe(lista);
}