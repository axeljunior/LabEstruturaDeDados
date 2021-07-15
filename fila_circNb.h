// =========== FILA Cirular (No bobo)=========== //
typedef struct tfila_circB {
	int R, F;
	int fila[TAM];
}FILAcb;

void inicializaFila(struct tfila *pf);
int fila_vazia(struct tfila *pf);
int insereFila(struct tfila *pf, int);
int removeFila(struct tfila *pf);

// =========== FILA Cirular (No bobo)=========== //
// =========== FILA Cirular (No bobo)=========== //

// (1) Inicialização da fila
void inicializaFila(struct tfila *pf) {
	pf->R=0;
	pf->F=0;
}
// (2) Testar fila vazia
int fila_vazia(struct tfila *pf) {
	if(pf -> F == pf->R)
		return 1;
	return 0;
}
3) Testar fila cheia
int fila_cheia(struct tfila *pf){
	if((pf -> R+1)%TAM == pf->F)
		return 1;
	return 0;
}
// (4) Inserção
int insereFila(struct tfila *pf, int valor) {
	if(fila_cheia(pf))
		return 0;
	pf->R=(pf->R+1)%TAM;
	pf->fila[pf ->R] = valor;
	return 1;
}
// (5) Remoção
int removeFila(struct tfila *pf){
	if(fila_vazia(pf))
		return 0;
	pf -> F = (pf->F+1)%TAM;
	*elem = pf->fila[pf->F];
	return 1;
}
// =========== PILHA Cirular (No bobo)=========== //