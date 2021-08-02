// =========== FILA Cirular (No bobo)=========== //
typedef struct tfila_circB {
	int R, F;
	int fila[TAM];
}FILAcb;

void inicializaFila(struct tfila_circB *);
int fila_vazia(struct tfila_circB *);
int insereFila(struct tfila_circB *, int);
int removeFila(struct tfila_circB *);
void exibeFila(struct tfila_circB *);

// =========== FILA Cirular (No bobo)=========== //
// =========== FILA Cirular (No bobo)=========== //

// (1) Inicialização da fila
void inicializaFila(struct tfila_circB *pf) {
	pf->R=0;
	pf->F=0;
}
// (2) Testar fila vazia
int fila_vazia(struct tfila_circB *pf) {
	if(pf -> F == pf->R)
		return 1;
	return 0;
}
// (3) Testar fila cheia
int fila_cheia(struct tfila_circB *pf){
	if((pf -> R+1)%TAM == pf->F){
		printf("\nFila Cheia\n");
		return 1;
	}
	return 0;
}
// (4) Inserção
int insereFila(struct tfila_circB *pf, int valor) {
	if(fila_cheia(pf))
		return 0;
	pf->R=(pf->R+1)%TAM;
	pf->fila[pf ->R] = valor;
	return 1;
}
// (5) Remoção
int removeFila(struct tfila_circB *pf){
	int elem;
	if(fila_vazia(pf))
		return 0;
	pf->F = (pf->F+1)%TAM;
	elem = pf->fila[pf->F];
	return elem;
}
// (6) Exibição

void exibeFila(struct tfila_circB *pf){
	int i=pf->F+1;
	if(pf->F+1 < pf->R){
		for(i=pf->F+1;i<=pf->R;i++)
			printf("%d ", pf->fila[i]);
	}else{
		while(i!=pf->R+1){
			if(i == TAM){
				i=0;
			}
			printf("%d ", pf->fila[i]);
			i++;
		}
	}
}
// =========== PILHA Cirular (No bobo)=========== //