int buscaSeqOrd(int*,int, int);
int buscaBinaria (int*,int,int);

int buscaSeqOrd(int *vetor,int tamanho_vetor, int valAlvo) {
	int i;
	for(i=0; i< tamanho_vetor && valAlvo > vetor[i]; i++);

	if((i==tamanho_vetor) || (valAlvo != vetor[i]))
		return 0;
	return 1;
}

int buscaBinaria (int *vetor,int tamanho_vetor, int valAlvo){
	int ini, fim, meio;
	ini=0;
	fim=tamanho_vetor-1;
	while(ini <= fim){
		meio=(ini+fim)/2;
		if(valAlvo == vetor[meio])
			return meio;
		if (valAlvo < vetor[meio])
			fim = meio-1;
		else
			ini = meio+1;
	}
	return -1;
}