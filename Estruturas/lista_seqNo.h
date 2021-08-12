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
int busca(struct tlista *, int);
int insere_lista(struct tlista *, int);
int insere_lista2(struct tlista *, int);
int remove_lista(struct tlista *, int);

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
// (5) Buscar um elemento na lista
int busca(struct tlista *pl, int elem) {
	int i;
	for(i=0; i< pl -> qtnos; i++) {
		if(elem == pl->lista[i].chave)
			return i; //achou
	}
	return -1; //não achou
}
// (6) Inserção na lista com repetição de chave
int insere_lista(struct tlista *pl, int valor) {
	if(pl -> qtnos == TAM)
		return -1;
	pl -> lista[pl->qtnos].chave = valor;
	pl -> qtnos++;
	return 1;
}
// (7) Inserção sem repetição de chave
int insere_lista2(struct tlista *pl, int valor) {
	int i;
	if(pl -> qtnos == TAM)
		return 0;
	i = busca(pl, valor);
	if(i>=0) //se achou o valor na lista
		return -1;
	pl->lista[pl->qtnos].chave = valor;
	pl->qtnos++;
	return 1;
}
// (8) Remoção
int remove_lista(struct tlista *pl, int valor) {
	int i;
	if(lista_vazia(pl))
		return 0;
	i = busca(pl, valor);
	if(i<0) //se não achou o valor na lista
		return -1;
	pl->qtnos--;
	pl->lista[i].chave = pl->lista[pl->qtnos].chave;
	return 1;
}
// =========== LISTA SEQ. N' ORDENADA =========== //
