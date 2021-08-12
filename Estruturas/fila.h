#define TAM 100

// =========== FILA SEQUENCIAL=========== //
typedef struct tfilaS {
	int F, R;
	int fila[TAM];
}FILA;

void inicializaFila(struct tfilaS *);
int fila_vazia(struct tfilaS *);
int fila_cheia (struct tfilaS *);
int insere_fila(struct tfilaS *, int);
int remove_fila(struct tfilaS *pf);
void exibeFila(struct tfilaS *,int);
// =========== FILA SEQUENCIAL=========== //
// =========== FILA SEQUENCIAL=========== //
//1) Inicialização
void inicializaFila(struct tfilaS *pf){
	pf->R = -1;
	pf->F = 0;
}

//2) Verificar Fila Vazia
int fila_vazia(struct tfilaS *pf){
	if(pf->F > pf->R)
		return 1;
	return 0;
}

//3) Verificar Fila Cheia
int fila_cheia (struct tfilaS *pf){
	if(pf->R == TAM-1)
		return 1;
	return 0;
}

//4) Inserção
int insere_fila(struct tfilaS *pf, int valor){
	if(fila_cheia(pf))
		return 0;
	pf->R++;
	pf->fila[pf->R] = valor;
	return 1;
}

//5) Remoção
int remove_fila(struct tfilaS *pf){
	int elem;
	if(fila_vazia(pf))
		return -1;
	elem = pf->fila[ pf->F ];
	pf->F++;
	return elem;
}

// (6) Exibe fila
void exibeFila(struct tfilaS *pf,int aux){
	int i;
	if(aux==0)
		for(i=0; i<pf->R+1; i++){
			printf("%d ", pf->fila[i]);
		}
	else if(aux>0 && aux<TAM){
		for(int i=0; i<aux; i++){
			printf("%d ", pf->fila[i]);
		}
	}
	else
		printf("\n~Posição fora da Filha~\n");
}
// =========== FILA SEQUENCIAL=========== //
