void troca (int *elemento_a, int *elemento_b);
void bubbleSort (int *vetor, int tam);

void troca (int *elemento_a, int *elemento_b){
	int aux;
	aux = *elemento_a;
	*elemento_a = *elemento_b;
	*elemento_b = aux;
}

void bubbleSort (int *vetor, int tam){
	int ordenando=1;

	while(ordenando){
		ordenando=0;

		for(int i=0; i<tam-1; i++) {
			if(vetor[i]>vetor[i+1]) {
				troca(&vetor[i], &vetor[i+1]); //vetor+i

				ordenando=1;
			}
		}
		tam--;
	}

}