#include <stdio.h>
#include <stdlib.h>

struct lista_LDE{
	float info;
	struct lista_LDE *eprox;
	struct lista_LDE *dprox;
};

/*
20) Escreva um programa que leia vários números reais positivos e insira-os em um arquivo texto (um número por linha). 
Em seguida, leia os dados do arquivo e insira-os numa Lista Duplamente Encadeada através da chamada de uma função que retorna ponteiro para o início da lista. 
Logo após, gere um menu com as seguintes opções:
	1- Imprimir a lista
	2- Buscar um elemento na lista
	3- Remover um valor da lista (lido via teclado)
	4- Contar os nós da lista
	5- Gerar uma cópia da lista num vetor
	6- Sair
Crie funções para cada opção do menu, exceto a opção 6. 
Após executar a opção 3 ou a opção 5 imprima a lista resultante ou o vetor resultante. 
O programa acaba quando for digitado a opção 6.
*/

// ======================  Funções da Lista ====================== //
// =============================================================== //

// 1) Função para imprimir a LDE.
int exibe(struct lista_LDE *positInicial){
	if(!positInicial)
		return 0;
	while(positInicial){
		printf("%.2f\t", positInicial->info);

		positInicial = positInicial->dprox;
	}
	return 1;
}

// 2) Função para contar os nós da LDE. 
int conta_nos(struct lista_LDE *positInicial){
	if(!positInicial)
		return 0;

	int cont=0;
	while(positInicial){
		cont++;
		positInicial = positInicial->dprox;
	}
	return cont;
}
//3.2) Função para inserir um nó antes do k-ésimo nó na LSEC.
void insereNo(struct lista_LDE *noInserido, struct lista_LDE *noDaLista){ 
	if( noDaLista->eprox != NULL )
		noDaLista->eprox->dprox = noInserido;      // A 1 2 B 3 4 | 2 -> B |
	noInserido->eprox = noDaLista->eprox; 	  	  // A 1 2 B 3 4  | 2 <- B |
	noInserido->dprox = noDaLista; 				 // A 1 2 B 3 4   | B -> 3 |
	noDaLista->eprox = noInserido; 				// A 1 2 B 3 4    | 3 <- B |
}
// 
struct lista_LDE *insere_AntesNo(struct lista_LDE *positInicial, int no, int valor){
	struct lista_LDE *positAtual, *novoNo;
	int cont=1;

	if( no < 1 || no > conta_nos(positInicial) ){
		printf("\nValor do nó não existe na lista\n");
		return positInicial;
	}

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));
	novoNo->info = valor;

	positAtual = positInicial;
	while(cont != no) {
		positAtual = positAtual->dprox;
		cont++;
	}
	
	insereNo(novoNo, positAtual);
	if(no == 1)
		return novoNo;
	return positInicial;
}
// 3.3) Função para inserir de maneira ordenada
struct lista_LDE *insereOrd(struct lista_LDE *positInicial, float valor){
	struct lista_LDE *novoNo, *positAtual;

	novoNo = (struct lista_LDE*) malloc(sizeof(struct lista_LDE));

	// ----
	novoNo->info = valor;
	// ----

	if(!positInicial){
		novoNo->eprox = novoNo->dprox = NULL;
		return novoNo;
	}else{
		positAtual = positInicial;
		while(positAtual->dprox && valor > positAtual->info)
			positAtual = positAtual->dprox;

		if(!positAtual->dprox && valor > positAtual->info){ 
			positAtual->dprox = novoNo;
			novoNo->eprox = positAtual;
			novoNo->dprox = NULL;
			return positInicial;
		}
		if(valor < positAtual->info){
			insereNo(novoNo, positAtual);

			if(positAtual==positInicial)
				return novoNo;
		}

		return positInicial;
	}
}
// 4) Função para remover o k-ésimo nó da LDE.
struct lista_LDE *remove_no(struct lista_LDE *positInicial, int no){
	struct lista_LDE *positAtual, *positAux, *positAux2;
	int cont;
	printf("\n ==> %d", no);
	if( no<1 || no>conta_nos(positInicial) ){
		printf("\nValor do nó não existe na lista\n");
		return positInicial;
	}else if(no == 1){
		if(!positInicial->dprox){
			free(positInicial);
			return NULL;
		}else{
			positAux = positInicial;
			positInicial = positInicial->dprox;
			positInicial->eprox = NULL;

			free(positAux);
			return positInicial;
		}
	}else{
		cont = 1;
		positAtual = positInicial;
		while(cont != no){ 
			positAtual = positAtual->dprox;
			cont++;
		}

		positAux = positAtual->dprox;
		positAux2 = positAtual->eprox;
		positAux2->dprox = positAux;

		if(positAux != NULL)
			positAux->eprox = positAux2;
		free(positAtual);
	}
	return positInicial;
} 
// 4.1) Função para remover um elemento passado por parametro.
struct lista_LDE *remove_elemento(struct lista_LDE *positIncial, float valor){
	if(!positIncial)
		return positIncial;
	
	int cont=1;
	struct lista_LDE *positAtual;

	positAtual = positIncial;
	while(positAtual){
		if(positAtual->info == valor)
			break;
		cont++;
		positAtual = positAtual->dprox;
	}
	positIncial = remove_no(positIncial, cont);
	return positIncial;
}
// 5.1) Copia lista to vetor
float *copia_para_vetor(struct lista_LDE *lista){
	struct lista_LDE *novaLista=NULL,*positAtual;
	float *vetor;
	int i=0;

	if(!lista){
		return 0;
	}

	vetor = (float*) malloc( conta_nos(lista) * sizeof(float) );

	positAtual = lista;
	while(positAtual){	
		*(vetor+i) = positAtual->info;
		positAtual = positAtual->dprox;
		i++;
	}
	return vetor;
}
// 7) Busca em uma lista Ordenada
float busca_seqOrd(struct lista_LDE *lista, int tamanho, float alvo) {
	int i;
	for(i=0; i < tamanho && alvo > lista->info; i++)
		lista = lista->dprox;

	if((i==tamanho) || (alvo != lista->info))
		return 0;
	return lista->info;
}

// =============================================================== // 
/*
(X)	1 - Imprimir a lista
(X)	2 - Buscar um elemento na lista
(X)	3 - Remover um valor da lista (lido via teclado)
(X)	4 - Contar os nós da lista
(X)	5 - Gerar uma cópia da lista num vetor
(X)	6 - Sair
*/
// =============================================================== // 
int main(){
	struct lista_LDE *lista = NULL;
	FILE *arquivo;
	int i,op=1,run=1;
	float imput,auxFloat;
	//float saida[7],entrada[7] = {1.618,0.45,2.718,3.141,0.67,4.964,0.7437};
	float *teste;
	
	arquivo = fopen("dados.txt", "w+");

	while(run){
		printf("\nInforme um valor real positivo\n ==> ");
		scanf("%f",&imput);

		fprintf(arquivo,"\n%f",imput);

		printf("\nParar de inserir valores?\n 1: Sim\n 2: Não\n ==> ");
		scanf("%d",&op);
		switch(op){
			case 1:
				run=0;
				break;
			case 2:
				break;
			default:
				printf("\nTecla invalida");
		}
	}
	
	rewind(arquivo);

	while(!feof(arquivo)){ //lê um caractere do arquivo
		fscanf(arquivo, "%f", &auxFloat);
		lista = insereOrd(lista, auxFloat);
	}

	fclose(arquivo);

	run=1;
	while(run){
		printf("\n(1) - Imprimir a lista");
		printf("\n(2) - Buscar um elemento na lista");
		printf("\n(3) - Remover um valor da lista");
		printf("\n(4) - Contar os nós da lista");
		printf("\n(5) - Gerar uma cópia da lista num vetor");
		printf("\n(6) - Sair\n ==> ");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				printf("\nElementos na lista:\n");
				exibe(lista);				
				printf("\n ------- \n");

				break;
			case 2:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				printf("\nInforme o valor que deseja buscar na lista\n ==> ");
				scanf("%f",&auxFloat);
				auxFloat = busca_seqOrd(lista, conta_nos(lista), auxFloat);
				if(auxFloat)
					printf("\nEsta na lista: %.3f\n", auxFloat);
				else
					printf("\nNão esta na lista!!\n");
				break;
			case 3:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				printf("\nInforme o valor que deseja remover na lista\n ==> ");
				scanf("%f",&auxFloat);
				lista = remove_elemento(lista,auxFloat);
				printf("\nLista Resultante:\n");
				exibe(lista);				
				printf("\n ------- \n");
				break;
			case 4:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				printf("\nQuantidade de nós: %d\n", conta_nos(lista));
				break;
			case 5:
				if(!lista){
					printf("\nLista vazia!!\n");
					break;
				}
				teste = copia_para_vetor(lista);
				printf("\nVetor resultante: \n");
				for(i=0;i<=conta_nos(lista)-1;i++)
					printf("%.3f\t",*(teste+i));
				printf("\n ------- \n");
				break;
			case 6:
				run=0;
				break;			
			default:
				printf("\nTecla invalida\n");
		}
	}
	free(lista);
}