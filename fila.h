#define TAM 100

struct tfilaS {
	int F, R; // F é a frente da fila e R é a retaguarda da fila.
	int fila[TAM];
};

//1) Inicialização
void inicializaFila(struct tfilaS *pf){
	pf->R = -1;
	pf->F = 0;
}

//2) Verificar Fila Vazia
int fila_vazia(struct tfilaS *pf){
	if(pf -> F > pf -> R)
		return 1;
	return 0;
}

//3) Verificar Fila Cheia
int fila_cheia (struct tfilaS *pf){
	if(pf -> R == TAM-1)
		return 1;
	return 0;
}

//4) Inserção
int insere_fila(struct tfilaS *pf, int valor){
	if(fila_cheia(pf))
		return 0;
	pf -> R++;
	pf->fila[pf->R]=valor;
	return 1;
}

//5) Remoção
int remove_fila(struct tfilaS *pf, int *elem){
	if(fila_vazia(pf))
		return 0;
	*elem = pf -> fila[pf -> F];
	pf ->F++;
	return 1;
}

