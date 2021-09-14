void troca (int *elemento_a, int *elemento_b);
int verificaOrd(int *vetor,int tam);

void bubbleSort (int *vetor, int tam);
void selectionSort(int *vetor, int tam);
void inserctionSort(int *vetor, int tam);

void troca (int *elemento_a, int *elemento_b){
	int aux;
	aux = *elemento_a;
	*elemento_a = *elemento_b;
	*elemento_b = aux;
}

int verificaOrd(int *vetor,int tam){
	int aux=0;
	for(int j=1; j<tam; j++) {
		for(int i=j; i>0 && vetor[i-1]>vetor[i] ; i--){
			return 0;
		}
	}
	return 1;
}

void bubbleSort (int *vetor, int tam){
	int ordenando=1,count=0;

	while(ordenando){
		ordenando=0;

		for(int i=0; i<tam-1; i++) {
			if(vetor[i] > vetor[i+1]) {
				troca(&vetor[i], &vetor[i+1]); //vetor+i

				ordenando=1;
			}count+=1;
		}
		tam--;
	}
	//return count;
}

void selectionSort(int *vetor, int tam){
	int menor,count=0;

	for(int j=0; j<tam-1; j++) {
		menor = j;

		for(int i=j+1; i<tam; i++) {
			if(vetor[i] < vetor[menor])
				menor=i;
			count+=1;
		}
		troca(&vetor[j], &vetor[menor]);
	}
	//return count;
}

void inserctionSort(int *vetor, int tam){
	int count=0;
	for(int j=1; j<tam; j++) {
		for(int i=j; i>0 && vetor[i-1]>vetor[i] ; i--){
			troca(&vetor[i-1], &vetor[i]);
			count+=1;
		}
	}
	//return count;
}
