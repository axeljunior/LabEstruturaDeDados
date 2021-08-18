struct lista_LSEC{
	int info;
	struct lista_LSEC *prox;
};

// =============================================================== //
int exibe(struct lista_LSEC *positFinal);
int conta_nos(struct lista_LSEC *positFinal);
struct lista_LSEC *divideListaNo(struct lista_LSEC *lista, int no);

struct lista_LSEC *inserir_inicio(struct lista_LSEC *positFinal, int valor);
struct lista_LSEC *inserir_final(struct lista_LSEC *positFinal, int valor);
struct lista_LSEC *insereAposNo(struct lista_LSEC *positFinal, int no, int valor);

struct lista_LSEC *remove_inicio(struct lista_LSEC *positFinal); 
struct lista_LSEC *remove_final(struct lista_LSEC *positFinal); 
struct lista_LSEC *removeNo(struct lista_LSEC *positFinal, int no);

// =============================================================== //

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
struct lista_LSEC *inserir_final(struct lista_LSEC *positFinal, int valor){

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
// Função para inserir um nó na lista
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
// ======

// Função para remover o primeiro nó da lista.
struct lista_LSEC *remove_inicio(struct lista_LSEC *positFinal){ 
	struct lista_LSEC *positAuxiliar;

	if(!positFinal)
		return NULL;
	if(positFinal == positFinal->prox){
		free(positFinal);
		return NULL;
	}

	positAuxiliar = positFinal->prox;
	positFinal->prox = positAuxiliar->prox;

	free(positAuxiliar);
	return positFinal;
}

// Função para remover o último nó da lista.
struct lista_LSEC *remove_final(struct lista_LSEC *positFinal){ 
	struct lista_LSEC *positAtual;

	
	if(!positFinal)
		return NULL;
	if(positFinal == positFinal->prox){
		free(positFinal);
		return NULL;
	}

	positAtual = positFinal->prox;

	while(positAtual->prox != positFinal){
		positAtual = positAtual->prox;
	}
	positAtual->prox = positFinal->prox;

	free(positFinal);
	return positAtual;
}
// Função para remover o k-ésimo nó da LSEC não vazia.
struct lista_LSEC *removeNo(struct lista_LSEC *positFinal, int no){
	struct lista_LSEC *positAtual, *positAuxiliar; 
	int cont;
	if( no<1 || no>conta_nos(positFinal) ){
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
			positFinal = positAtual;
			positAtual = positAtual->prox;
			cont++;
		}
		positFinal->prox = positAtual->prox;
		if(positFinal == positAtual){
			free(positAtual);
			return positFinal;
		}
		free(positAtual);
		return positFinal;
	}
}

//Divide a lista no No
struct lista_LSEC *divideListaNo(struct lista_LSEC *lista, int no){
	struct lista_LSEC *novaLista,*positAtual;
	int cont=1;

	if(lista == lista->prox) 
		return NULL;

	positAtual = lista->prox;
	while(cont != no) {
		positAtual = positAtual->prox;
		cont++;
	}

	novaLista = lista;
	while(novaLista->prox != positAtual){
		novaLista = novaLista->prox;

	}

	novaLista->prox = lista->prox;
	lista->prox = positAtual;

	return novaLista;
}

//7) Função para inserir um nó após o k-ésimo nó na LSEC.
struct lista_LSEC *insereAposNo(struct lista_LSEC *positFinal, int no, int valor){
	struct lista_LSEC *positAtual, *novoNo;
	int cont=1;

	novoNo = (struct lista_LSEC*) malloc(sizeof(struct lista_LSEC));
	novoNo->info = valor;

	positAtual = positFinal->prox;
	while(cont != no) {
		positAtual = positAtual->prox;
		cont++;
	}

	novoNo->prox = positAtual->prox;
	positAtual->prox = novoNo;

	if(positAtual == positFinal)
		return novoNo;
	else
		return positFinal;
}

// =============================================================== //
// =============================================================== //