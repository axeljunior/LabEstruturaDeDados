#define TAM 100
// =========== LISTA SEQ. N' ORDENADA =========== //
struct tno {
	int chave;
};
struct tlista {
	int qtnos;
	struct tno lista[TAM];
};

void inicializa_lista(struct tlista *);
int lista_vazia(struct tlista *);
int lista_cheia(struct tlista *);
void percurso(struct tlista *);

int busca_seq(struct tlista *, int, int *);
int insere_listaOrd(struct tlista *, int);
int remove_listaOrd(struct tlista *, int);


// =========== LISTA SEQ. N' ORDENADA =========== //
// (1) Inicialização da lista
void inicializa_lista(struct tlista *pl) {
 pl -> qtnos = 0;
}
// (2) Testar lista vazia
int lista_vazia(struct tlista *pl) {
	if(pl -> qtnos == 0)
		return 1;
	return 0;
}
// (3) Testar lista cheia
int lista_cheia(struct tlista *pl) {
	if(pl ->qtnos==TAM)
		return 1;
	return 0;
}
// (4) Percurso
void percurso(struct tlista *pl) {
	int i;
	for(i=0; i< pl -> qtnos; i++)
		printf("%d\t", pl -> lista[i].chave);
}
// (5) Busca Sequencial Ordenada
int busca_seq(struct tlista *pl, int elem, int *pos){
	int i;
	for(i=0; i < pl -> qtnos && elem > pl -> lista[i].chave; i++);
	*pos=i;
	if((i == pl -> qtnos) || (elem != pl -> lista[i].chave))
		return 0; //não achou
	return 1; //achou
}
// (6) Inserção
int insere_ord(struct tlista *pl, int elem){
	int i, posicao;
	if(pl -> qtnos == TAM)
		return 0;
	if(buscaseq(pl, elem, &posicao))
		return -1;
	for(i=pl -> qtnos; i>posicao; i--)
		pl -> lista[i].chave = pl->lista[i-1].chave;
	pl -> lista[posicao].chave = elem;
	pl->qtnos++;
	return 1;
}

// (7) Remoção
int remove_ord(struct tlista *pl, int elem){
	int i, posicao;
	if(pl->qtnos==0)
		return 0;
	if(!buscaseq(*pl, elem, &posicao))
		return -1;
	for(i=posicao; i< pl ->qtnos-1; i++)
		pl -> lista[i].chave = pl->lista[i+1].chave;
	pl->qtnos--;
	return 1;
}
// =========== LISTA SEQ. N' ORDENADA =========== //
