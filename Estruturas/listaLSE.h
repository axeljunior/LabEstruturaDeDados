struct lista_LSE{
	int info;
	struct lista_LSE *prox;
};

int contaNos(struct lista_LSE *);
void imprimir (struct lista_LSE *);

// ========= // Não Ordenada

struct lista_LSE *cria(int); // Não Ordenada
struct lista_LSE *inserirFinal(struct lista_LSE *, int); // Não Ordenada
struct lista_LSE *removerFinal(struct lista_LSE *, int); // Não Ordenada
struct lista_LSE *removeK(struct lista_LSE *, int ); // Não Ordenada
struct lista_LSE *concatena (struct lista_LSE *, struct lista_LSE  *); // Não Ordenada

// ========= // Ordenada

struct lista_LSE *insereOrd(struct lista_LSE *p, int valor);
struct lista_LSE *buscaOrd(struct lista_LSE *p, int valor);
struct lista_LSE *removeOrd(struct lista_LSE *p, int valor);

// ========================================================

// Função para criar uma LSE com n nós:
struct lista_LSE *cria(int n){
	int i, valor;
	struct lista_LSE *p,*ini,*ult;

	ini = ult = NULL;

	for(i=1; i<=n; i++){
		printf("Informe um valor: ");
		scanf("%d", &valor);

		p = (struct lista_LSE*) malloc(sizeof(struct lista_LSE));

		p->info = valor;
		p->prox = NULL;
		if(ult)
			ult->prox = p;
		else
			ini = p;
		ult = p;
	}
	return ini;
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

// Função para inserir um nó no final da lista:
struct lista_LSE *inserirFinal(struct lista_LSE *p, int valor){
	struct lista_LSE *ini, *novo;

	novo = (struct lista_LSE*) malloc(sizeof(struct lista_LSE));

	novo->info = valor;
	novo->prox = NULL;

	if(!p)
		return novo;

	ini = p;

	while(p->prox)
		p = p->prox;

	p->prox = novo;
	return ini;
}

// Função para remover o último nó da lista. Retornar o ponteiro para o início da lista resultante.
struct lista_LSE *removerFinal(struct lista_LSE *p, int valor){
	struct lista_LSE *ini, *ult;
	if(!p)
		return NULL;
	if(!p->prox){
		free(p);
		return NULL;
	}
	ini = p;
	while(p->prox) {
		ult=p;
		p = p->prox;
	}

	ult->prox = NULL;
	free(p);
	return ini;
}

// Função para remover o k-ésimo nó da lista. Retornar ponteiro para o início da lista resultante. (k>=1 && k<=n)
struct lista_LSE *removeK(struct lista_LSE *p, int k){
	struct lista_LSE *t, *q;
	int cont;
	if(k==1){
		if(!p->prox){
			free(p);
			return NULL;
		}else{
			t = p->prox;
			p->prox = NULL;
			free(p);
			return t;
		}
	}else{
		cont = 1;
		t = p;

		while(cont != k) {
			q = p;
			p = p->prox;
			cont++;
		}
		q->prox = p->prox;

		free(p);
		return t;
	}
}
// ==========

// Imprimir a lista:
void imprimir (struct lista_LSE *lista){
	while(lista){
		printf("%d\t", lista->info);
		lista = lista->prox;
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

// ==========

// Insere em LSE Ordenada
struct lista_LSE *insereOrd(struct lista_LSE *p, int valor){
	struct lista_LSE *t, *q, *r;
	q = (struct lista_LSE*) malloc(sizeof(struct lista_LSE));

	q->info = valor;
	if(!p){
		q->prox = NULL;
		return q;
	}else{
		r = p;
		while(p && valor > p->info){
			t = p;
			p = p->prox;
		}
		if(!p){
			t->prox = q;
			q->prox = NULL;
			return r;
		}
		if(valor < p->info){
			q->prox = p;
			if(p != r){
				t->prox = q;
				return r;
			}
			return q;
		}
	}
}
// Busca em LSE Ordenada
struct lista_LSE *buscaOrd(struct lista_LSE *p, int valor){
	struct lista_LSE *q;
	if(!p)
		return NULL;
	while(p && valor != p->info){
		q = p;
		p = p->prox;
	}
	return p;
}
// Remove em LSE Ordenada
struct lista_LSE *removeOrd(struct lista_LSE *p, int valor){
	struct lista_LSE *q, *t;
	if(!p)
		return NULL;
	else {
		if(buscaOrd(p,valor)==NULL){
			printf("\nElemento não existente.");
			return p;
		}
		else {
			q=p;
		while(q->info < valor){
			t = q;
			q = q->prox;
		}
		if(p!=q)
			t->prox = q->prox;
		else
			p = p->prox;
		free(q);
		return p;
		}
	}
}
