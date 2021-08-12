//-------------------------------------------------------------
// =========== FILA Cirular (Contador)=========== //
typedef struct tfila_circC {
	int ini;
	int fim;
	int cont;
	int fila[TAM];
}FILAcc;

void inicializaFila(struct tfila_circC *pf);
int fila_vazia(struct tfila_circC *pf);
int fila_cheia(struct tfila_circC *pf);
int insere_fila(struct tfila_circC *pf, int valor);
int remove_fila(struct tfila_circC *pf);
void exibeFila(struct tfila_circC *pf,int aux);
// =========== FILA Cirular (Contador)=========== //
// =========== FILA Cirular (Contador)=========== //

// (1) Inicialização
void inicializaFila(struct tfila_circC *pf) {
	pf->ini=0;
	pf->fim=-1;
	pf->cont=0;
}
// (2) Testar fila vazia
int fila_vazia(struct tfila_circC *pf){
	if(pf -> cont == 0)
		return 1;
	return 0;
}
// (3) Testar fila cheia
int fila_cheia(struct tfila_circC *pf){
	if(pf->cont == TAM)
		return 1;
	return 0;
}
// (4) Inserção
int insere_fila(struct tfila_circC *pf, int valor){
	if(fila_cheia(pf))
		return 0;
	pf -> cont++;
	pf -> fim = (pf -> fim == TAM-1) ? 0 : pf ->fim+1;
	pf -> fila[pf -> fim] = valor;
	return 1;
}
// (5) Remoção
int remove_fila(struct tfila_circC *pf){
	int elem;
	if(fila_vazia(pf))
		return -1;
	pf->cont--;
	elem=pf->fila[pf->ini];
	pf -> ini = (pf ->ini==TAM-1) ? 0 : pf->ini+1;
	return elem;
}
// (6) Exibição

void exibeFila(struct tfila_circC *pf,int aux){
	int i=pf->ini;
	if(aux==0){
		if(fila_cheia(pf)){
			for(i=0;i<TAM;i++)
				printf("%d ", pf->fila[i]);

		}else if(pf->ini < pf->fim+1){
			for(i=pf->ini;i<pf->fim+1;i++)
				printf("%d ", pf->fila[i]);
		}
		else{
			while(i!=pf->fim+1){
				if(i == TAM){
					i=0;
				}
				printf("%d ", pf->fila[i]);
				i++;
			}
		}
	}
	else if(aux>0 && aux<TAM){
		for(int i=0; i<aux; i++){
			printf("%d ", pf->fila[i]);
		}
	}
	else
		printf("\n~Posição fora da Pilha~\n");
}
// =========== FILA Cirular (Contador)=========== //
//-------------------------------------------------------------