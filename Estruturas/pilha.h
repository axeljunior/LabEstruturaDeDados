#define TAM 100

// ========== PILHA ========== //
typedef struct tpilha {
	int topo;
	char pilha[TAM];
}PILHA;

void inicializaPilha(struct tpilha *);
int pilhaVazia(struct tpilha *);
int pilhaCheia(struct tpilha *);
int empilha(struct tpilha *, int);
int desempilha (struct tpilha *);
void exibePilha(struct tpilha *,int);
// =========== PILHA ========== //

// =========== PILHA =========== //

// (1) Inicializar a pilha:
void inicializaPilha(struct tpilha *ps){
	ps->topo = -1;
}

// (2) Testar pilha vazia
int pilhaVazia(struct tpilha *ps){
	if(ps->topo == -1)
		return 1;
	return 0;
}

// (3) Testar pilha cheia
int pilhaCheia(struct tpilha *ps){
	if(ps->topo == TAM-1)
		return 1;
	return 0;
}

// (4) Empilhamento
int empilha(struct tpilha *ps, int valor){
	if(pilhaCheia(ps))
		return 0;
	ps->topo++;
	ps->pilha[ps -> topo] = valor;
	return 1;
}

// (5) Desempilha
int desempilha (struct tpilha *ps){
	int elem;
	if (pilhaVazia(ps)){
		printf("\nPilha Vazia");
		return -1;
	}
	elem = ps->pilha[ps->topo];
	ps->topo--;
	return elem;
}

// (6) Exibe pilha
void exibePilha(struct tpilha *ps,int aux){
	if(aux==0)
		for(int i=0; i<ps->topo+1; i++){

			printf("%d ", ps->pilha[i]);
		}
	else if(aux>0 && aux<TAM){
		for(int i=0; i<aux; i++){
			printf("%d ", ps->pilha[i]);
		}
	}
	else
		printf("\n~Posição fora da Pilha~\n");
}
// =========== PILHA =========== //