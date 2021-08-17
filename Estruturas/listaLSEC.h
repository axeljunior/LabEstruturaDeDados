struct lista_LSEC{
	int info;
	struct lista_LSEC *prox;
};

// =============================================================== // Funções da Lista
//void exibe(struct lista_LSEC *);     
int conta_nos (struct lista *);
//int busca(struct lista_LSEC *, int); 
//struct lista_LSEC *concatena(struct lista_LSEC *, struct lista_LSEC  *); 
// ========= // Não Ordenada
struct lista_LSEC inserir_inicio(struct lista_LSEC *, int);
struct lista_LSEC *remove_primeiro(struct lista_LSEC *);
//struct lista_LSEC *removerFinal(struct lista_LSEC *);    
//struct lista_LSEC *removeNo(struct lista_LSEC *, int );  
// ========= // Ordenada 
//struct lista_LSEC *insereOrd(struct lista_LSEC *, int);

//struct lista_LSEC *buscaOrd(struct lista_LSEC *p, int valor);
//struct lista_LSEC *removeOrd(struct lista_LSEC *p, int valor);
//void removeNoTeste(struct lista_LSEC **positInicial, int no); // Teste
// =============================================================== //

// =============================================================== //
// =============================================================== //

// Contar os nós da lista:
int conta_nos (struct lista_LSEC *lista){ 
	struct lista_LSEC *positAtual;
	int cont = 1;

	if(!lista)
		return 0;
	positAtual = lista;

	while(lista->prox != positAtual){
		cont++;
		lista = lista->prox;
	}
	return cont;
}

// ================== FUNÇÕES PARA LSEC NÃO ORDENADAS ================== //
//======================================================================//

// Função para inserir um nó na lista
struct lista_LSEC inserir_inicio(struct lista_LSEC *positInicial, int valor){

	struct lista_LSEC *novoNo;

	novoNo = (struct lista_LSEC*)malloc(sizeof(struct lista_LSEC));
	novoNo->info = valor;

	if(!positInicial){
		novoNo->prox = novoNo;
		return novoNo;
	}
	novoNo->prox = positInicial->prox;
	positInicial->prox = novoNo;

	return positInicial;
}

// Função para remover o último nó da lista.
struct lista_LSEC *remove_primeiro(struct lista_LSEC *positInicial){ 
	struct lista_LSEC *positAuxiliar;

	if(!positInicial)
		return NULL;
	if(positInicial == positInicial->prox){
		free(positInicial);
		return NULL;
	}

	positAuxiliar = positInicial->prox;
	positInicial->prox = positAuxiliar->prox;
	free(positAuxiliar);

	return positInicial;
}

// Função para remover o k-ésimo nó da LSEC não vazia. Retornar ponteiro para a lista resultante.
struct lista *removeK(struct lista *p, int k){ // p ... pIni
	struct lista *q, *t; // q ... pAtu | t ... pAux
	int cont;
	if(k==1){
		if(p->prox == p) {     // p ... pIni
			free(p);           // p ... pIni
			return NULL;
		}
		else{
			q = p->prox;       // q ... pAtu | p ... pIni
			p->prox = q->prox; // p ... pIni | q ... pAtu
			free(q);
		}
	}
	else{
		cont=1;
		q = p->prox;
		while(k!=cont) {
			t = q;
			q = q->prox;
			cont++;
		}
		t->prox=q->prox;
		if(p==q){
			free(q);
			return t;
		}
		free(q);
		return p;
	}
}

// 5) Função para dividir a LSEC em duas, sendo:
// - A primeira com o ultimo nó
// - A segunda com o restante dos nós
// - Retornar referência para a segunda lista.
struct lista *divideLista(struct lista *p){
	struct lista *q;
	if(p == p->prox)
		return NULL;
	q=p;
	while(q->prox != p)
		q=q->prox;
	q->prox=p->prox;
	p->prox=p;
	return q;
}

//7) Função para inserir um nó após o k-ésimo nó na LSEC. Retornar referência para a lista resultante.
struct lista *insereAposK(struct lista *p, int k){
	struct lista *q, *r;
	int cont=1, valor;

	printf("\nDigite o valor a ser inserido: ");
	scanf("%d", &valor);

	r = (struct lista*) malloc(sizeof(struct lista));
	r->info = valor;
	q = p->prox;
	while(cont != k) {
		cont++;
		q = q->prox;
	}
	r->prox = q->prox;
	q->prox = r;
	if(q == p)
		return r;
	else
		return p;
}
