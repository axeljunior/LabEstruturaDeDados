int buscaSeqOrd(int*,int, int);

int buscaSeqOrd(int *vetor,int tamanho_vetor, int valAlvo) {
	int i;
	for(i=0; i< tamanho_vetor && valAlvo > vetor[i]; i++);
	if((i==tamanho_vetor) || (valAlvo != vetor[i]))
		return 0; // não achou
	return 1; // achou
}