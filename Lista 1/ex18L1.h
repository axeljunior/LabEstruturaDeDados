#include <stdio.h>
#include <stdlib.h>

/*
18) Faça um programa que exiba o seguinte menu principal:
- - - - - -Editor de Listas - - - - - - - -
O usuário deve digitar a opção de sua preferência para executar uma operação. implemente a
lista de números inteiros. Cada uma das operações do menu é descrita a seguir:

	(X) - a) Na opção 1, devem ser exibidos o tamanho corrente da lista e todos os seus elementos;
	(X) - b) Na opção 2, devem ser lidos não somente o elemento a ser inserido, mas também a posição na lista onde o usuário deseja realizar a inserção;
	(X) - c) Na opção 3, deve ser lida a posição na lista do elemento a ser removido;
	(X) - d) Na opção 4, deve ser lida a posição do elemento;
	(X) - e) Na opção 5, deve ser lido o valor do elemento cuja posição se quer exibir;
	(X) - f) Na opção 6, deve ser exibida uma mensagem de confirmação para o usuário antes da lista ser totalmente esvaziada;

	(X) - g) Após a execução de cada operação, o programa deve retornar ao menu principal para que o usuário possa executar outras opções ou encerre o programa;
	(X) - h) Lembre-se: em cada uma das operações, identifique possíveis situações de erros do
	usuário e exiba mensagens para ele nestas situações. (Ex. o programa deve exibir mensagens no caso do usuário tentar remover um item ou esvaziar uma lista que está vazia, inserir elemento numa lista que já está cheia, inserir posições inválidas, etc.).
*/

#define TAM 100
// =========== LISTA SEQ.ORDENADA =========== //
struct tno {
	int chave;
};
typedef struct tlista_nord {
	int qtnos;
	struct tno lista[TAM];
}LISTAs;

void inicializa_lista(struct tlista_nord *);
int lista_vazia(struct tlista_nord *);
int lista_cheia(struct tlista_nord *);
void exibe_lista(struct tlista_nord *, int);
int busca(struct tlista_nord *, int);
int insere_lista(struct tlista_nord *, int, int);
int remove_lista(struct tlista_nord *, int);

void menu(struct tlista_nord *);
int verifica_ord(struct tlista_nord*,int);
// =========== LISTA SEQ.ORDENADA =========== //
int main(){
	LISTAs L1;
	inicializa_lista(&L1);
	
/*  //TESTES
	insere_lista(&L1, 13,-1); // 0
	insere_lista(&L1, 19,-1); // 1
	insere_lista(&L1, 42,-1); // 2
	insere_lista(&L1, 7,-1);  // 3
	insere_lista(&L1, 64,-1); // 4
	insere_lista(&L1, 72, 56); // Entra na posição 3 - 5
*/
	menu(&L1);
}
void menu(struct tlista_nord *lista){
	int i,opt=0,run = 1;
	int valInput,posInput;
	/*
	(X) - 1 - Exibir a lista
	(X) - 2 - Inserir na lista
	(X) - 3 - Remover da lista
	(X) - 4 - Exibir um dado elemento da lista
	(X) - 5 - Exibir posição de um dado elemento na lista
	( ) - 6 - Esvaziar lista
	(X) - 7 - Sair
	*/
	while(run){
		printf("\nEscolha uma opção: \n - (1) - Exibir a lista\n - (2) - Inserir na lista\n - (3) - Remover da lista\n - (4) - Exibir um dado elemento da lista\n - (5) - Exibir posição de um dado elemento na lista\n - (6) - Esvaziar lista\n - (7) - Sair\n ==> ");
		scanf("%d",&opt);
		printf("\n=================================\n");
		switch(opt){
			case 1:
				if(lista_vazia(lista))
					break;
				printf("Espaço ocupado %d/%d\n\n",lista->qtnos,TAM);
				exibe_lista(lista, 0);
				break;
			case 2:
				printf("\nInforme um numero inteiro\n ==> ");
				scanf("%d",&valInput);
				printf("\nInforme a posição na lista  onde quer inseri-lo\n ==> ");
				scanf("%d",&posInput);
				if(posInput > lista->qtnos)
					printf("\n    Aviso: A posição %d esta fora do intervalo preenchido da lista, [0,%d], o valor foi adicionado na primeira posição valida >> %d <<\n",posInput,lista->qtnos,lista->qtnos);
				
				insere_lista(lista, valInput, posInput);
				break;
			case 3:
				if(lista_vazia(lista))
					break;
				printf("\nInforme a posição do elemento que deseja retirar\n ==> ");
				scanf("%d",&posInput);

				if(posInput > lista->qtnos){
					printf("\nNão há elementos nessa posição\n");
					break;
				}
				remove_lista(lista, posInput);
				break;
			case 4:
				if(lista_vazia(lista))
					break;
				printf("\nInforme a posição do elemento que deseja exibir\n ==> ");
				scanf("%d",&posInput);

				if(posInput > lista->qtnos){
					printf("\nNão há elementos nessa posição\n");
					break;
				}
				exibe_lista(lista, posInput);
				break;
			case 5:
				if(lista_vazia(lista))
					break;
				printf("\nInforme o valor do elemento que deseja saber a posição\n ==> ");
				scanf("%d",&valInput);
				i = busca(lista, valInput);
				if(i == -1){
					printf("\nEsse elemento não existe na lista\n");
					break;
				}
				printf("\n---------\nO elemento indicado esta na posição: %d\n---------\n",i);
				break;
			case 6:
				if(lista_vazia(lista))
					break;
				printf("\nEsvaziando lista...\n");
				printf("\nTem certeza que deseja esvaziar a lista?\n - (1) - Sim\n - (0) - Não\n ==> ");
				scanf("%d",&valInput);
				if(valInput==1){
					inicializa_lista(lista);
					lista_vazia(lista);
					break;
				}else if(valInput==0){
					printf("\nOperação cancelada\n");
					break;
				}else{
					printf("\nOpção invalida...\n");
					printf("\nOperação cancelada\n");
					break;
				}
			case 7:
				printf("\nEncerrando...\n");
				run=0;
				break;
			default:
				printf("\nOpção invalida\n");
			
		}
		printf("\n=================================\n");
	}
}
// =========== LISTA SEQ.ORDENADA =========== //
// (1) Inicialização da lista
void inicializa_lista(struct tlista_nord *pl) {
	pl->qtnos = 0;
}

// (2) Testar lista vazia
int lista_vazia(struct tlista_nord *pl) {
	if(pl -> qtnos == 0){
		printf("\nA Lista esta vazia\n");
		return 1;
	}
	return 0;
}
// (3) Testar lista cheia
int lista_cheia(struct tlista_nord *pl) {
	if(pl ->qtnos==TAM)
		return 1;
	return 0;
}
// (4) exibir
void exibe_lista(struct tlista_nord *pl,int index){ 
	if(index>0){
		printf("\n---------\nElemento: %d\n---------\n", pl->lista[index].chave);
	}else{
		int i;
		for(i=0; i < pl->qtnos; i++){
			printf("Elemento: %d\n---------\n", pl->lista[i].chave);	
		}
	}
}
// (5) Buscar um elemento na lista
int busca(struct tlista_nord *pl, int elem) {
	int i;
	for(i=0; i<pl->qtnos; i++) {
		if(elem == pl->lista[i].chave)
			return i; //achou
	}
	return -1; //não achou
}
// (6) Inserção sem repetição de chave
int insere_lista(struct tlista_nord *pl, int valor,int posicao){
	if(pl->qtnos == TAM){
		printf("\nSem espaço na lista\n");
		return 0;
	}
	int i;
	i = busca(pl, valor);
	if(i >= 0){ //se achou o valor na lista
		printf("\nA lista já possui um elemento com este valor\n");
		return -1;
	}
	if(posicao >= 0 && posicao <= pl->qtnos){
		for(i=pl->qtnos; i>posicao; i--)
			pl->lista[i].chave = pl->lista[i-1].chave;
		pl->lista[posicao].chave = valor;	
	}else{
		pl->lista[pl->qtnos].chave = valor;
	}
	pl->qtnos++;
	return 1;
}
// (7) Remoção
int remove_lista(struct tlista_nord *pl, int pos) {
	if(lista_vazia(pl)){
		printf("\nLista Vazia\n");
		return 0;
	}
	int i;

	for(i=pos; i<=pl->qtnos; i++)
		pl->lista[i].chave = pl->lista[i+1].chave;
	pl->qtnos--;
	return 1;
}
// =========== LISTA SEQ.ORDENADA =========== //