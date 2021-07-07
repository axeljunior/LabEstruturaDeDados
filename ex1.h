/*
1) Escreva um programa que leia o tamanho n do vetor, aloque memória,
leia n números inteiros sem repetição de valores e preencha o vetor.
Imprima o vetor. Em seguida, mostre um menu com as seguintes opções:

	1 - Ordenar por trocas (Bubblesort)
	2 - Seleção
	3 - Inserção

Após a escolha da opção, mostre o vetor ordenado.

Logo após, leia um valor qualquer e faça a busca na forma sequencial e
binária. Para ambas as buscas mostre uma mensagem "Achou" ou "Não
achou".
*/

int *alocaMemoria(int);
void preencherVetor(int*,int);
void exibeVetor(int*,int);
void menu(int*,int);

// Função para gerar um novo vetor
// Função para desordenar o mesmo vetor
// Função que contabilize a quantidade de loops que cada função fez

void ex1() {
	int tamanho_vetor,*Vetor;

	printf("Informe o tamanho do Vetor: ");
	scanf("%d", &tamanho_vetor);

	Vetor = alocaMemoria(tamanho_vetor);
	preencherVetor(Vetor,tamanho_vetor);

	menu(Vetor,tamanho_vetor);
	free(Vetor);
}
//===
void menu(int *vet, int vet_tam){
	int opt=0,menu=1;
	int teste = 1;

	while(menu){
		exibeVetor(vet,vet_tam);
		printf("\nOque deseja fazer? Escolha uma opção: \n(1) Bubble sort \n(2) Selection sort \n(3) Inserction sort\n(4) Embaralhar\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("-- Bubble sort --");
				bubbleSort(vet, vet_tam);
				break;
			case 2:
				printf("-- Selection sort --");
				selectionSort(vet, vet_tam);
				break;
			case 3:
				printf("-- Inserction sort --");
				inserctionSort(vet, vet_tam);
				break;
			case 4:
				printf("-- Embaralhar --");
				preencherVetor(vet, vet_tam);
				break;
			case 5:
				if(buscaSeqOrd(vet,vet_tam,7)){
					printf("Achou");
				}
				else{
					printf("Não achou");
				}
				break;
			default:
				printf("Opção invalida");
		}
		limparTela();
	}
}
//===
int *alocaMemoria(int tam){
	int *Mry;
	Mry = (int*) malloc(tam*sizeof(int));
	if(*Mry){
		printf("\nSem memoria disponivel!\n");
		exit(1);
	}
	else{
		printf("\nMemoria alocada para %d elementos\n", tam);
		return Mry;
	}
}
//===
void preencherVetor(int *vet,int vet_tam){
	int valor_imput,ctrl = 0;

/*                                         //TESTE
	printf("\nVetor atual...");
	exibeVetor(vet,vet_tam);
*/ 
	for(int i=0;i<=vet_tam;i++) // Inicia o Vetor
		vet[i] = -1;
/* 		
	printf("\nLimpando o Vetor...");
	exibeVetor(vet,vet_tam);
*/                                         //TESTE

	while(ctrl<vet_tam){
		printf("\nInforme um valor para o Vetor: ");

		valor_imput = imput(vet_tam);
		//scanf("%d",&valor_imput);

		for(int i=0;i<=ctrl;i++){
			printf("\n valor_imput = %d vet[%d] = %d",valor_imput,i,vet[i]); // TESTE
			if(valor_imput == vet[i]){
				printf("\nO valor não pode ser repetido\n\n");
				break;
			}else if(i == ctrl){
				printf(" ADD"); // TESTE
				vet[i] = valor_imput;
				ctrl++;
				break;
			}
		}
	}
}
//===
void exibeVetor(int *vet,int vet_tam){
	printf("\n[");
	for(int i=0;i<vet_tam;i++)
		printf(" %d ",vet[i]);
	printf("]\n");
}
