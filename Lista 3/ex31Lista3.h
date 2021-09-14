#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 13
struct tree{
	struct tree *esq;
	int chave;
	struct tree *dir;
};

/*
31) Escreva um programa para manipular Árvore Binária de Busca (ABB) com n (lido via teclado) números inteiros que contenha o seguinte menu de opções:

	1 (X) - Inserir um nó na ABB
	2 (X) - Imprimir a ABB
		I - Inoder
		P - Preorder
		O - Postorder
		S - Sair
	3 (X) - Buscar uma chave na ABB
	4 (X) - Mostrar a altura da ABB
	5 (X) - Mostrar a quantidade de nós da ABB
	6 (X) - Mostrar a quantidade de folhas da ABB
	7 (X) - Mostrar a quantidade de pais da ABB
	8 (X) - Mostrar a maior chave da ABB
	9 (X) - Mostrar a menor chave da ABB
	10 (X) - Remover um nó da ABB
	11 (X) - Sair

Para as opções 1 a 9 crie uma função recursiva para resolver cada item.
Na opção 10, crie uma função não recursiva. Mostre a árvore resultante após a remoção do nó.
Na opção 2, mostre o menu com as opções de caminhamentos para o usuário.
Na opção 11, mostre uma mensagem. O menu acaba quando o usuário escolher a opção 11.
*/

// 1 - Insere nó na Arvore
struct tree *insereABB(struct tree *raiz,struct tree *novoNo, int valor){
	if(!novoNo){
		novoNo = (struct tree *) malloc( sizeof(struct tree));
		novoNo->chave = valor;
		novoNo->dir = novoNo->esq = NULL;
	}
	if(!raiz){
		return novoNo;
	}
	if(raiz->chave > valor){
		if(!raiz->esq)
			raiz->esq = novoNo;
		else
			insereABB(raiz->esq, novoNo, valor);

	}else if(raiz->chave < valor){
		if(!raiz->dir)
			raiz->dir = novoNo;
		else
			insereABB(raiz->dir, novoNo, valor);
	}
	return raiz;
}
// 2 - Funções recursivas para Imprimir
// 2.1 - Inorder
void inorder(struct tree *raiz){
	if(raiz != NULL){
		inorder(raiz->esq);
		printf("%d \t", raiz->chave);
		inorder(raiz->dir);
	}
}
// 2.2 - Preorder
void preorder(struct tree *raiz){
	if(raiz != NULL){
		printf("%d \t", raiz->chave);
		preorder(raiz->esq);
		preorder(raiz->dir);
 	}
}
// 2.3 - Postorder
void postorder(struct tree *raiz){
	if(raiz != NULL){
		postorder(raiz->esq);
		postorder(raiz->dir);
		printf("%d \t", raiz->chave);
	}
}
// 3. Função recursiva para Buscar uma chave na Aravore caso existe.
struct tree *busca(struct tree *raiz, int valor){
	if(raiz){
		if(valor == raiz->chave)
			return(raiz);
		if(valor < raiz->chave)
			return(busca(raiz->esq, valor));
		if(valor > raiz->chave)
			return(busca(raiz->dir, valor));
	}
	return(NULL);
}
// 4. Função recursiva para determinar a Altura 
int altura(struct tree *raiz){
	int tamEsquerda, tamDireita;
	if(!raiz)
		return 0;
	tamEsquerda = 1 + altura(raiz->esq);
	tamDireita = 1 + altura(raiz->dir);
	return (tamEsquerda >= tamDireita ? tamEsquerda : tamDireita);
} 
// 5. Função recursiva para contar os nós da árvore.
int contaNos(struct tree *raiz){
	if(!raiz)
		return 0;
	return (1+contaNos(raiz->esq)+contaNos(raiz->dir));
}
// 6. Função recursiva para contar os nós folhas da árvore.
int contaFolhas(struct tree *raiz){
	if(!raiz)
		return 0;
	if(!raiz->esq && !raiz->dir)
		return 1;
	return (contaFolhas(raiz->esq) + contaFolhas(raiz->dir));
}
// 7. Função recursiva para contar os nós pais da árvore.
int contaPais(struct tree *raiz){
	if(!raiz)
		return 0;
	if(!raiz->esq && !raiz->dir)
		return 0;
	return (1+contaPais(raiz->esq) + contaPais(raiz->dir));
}
// 8. Mostrar a maior chave da ABB
struct tree *maiorChave(struct tree *raiz){
	if(!raiz)
		return raiz;
	if(!raiz->dir)
		return raiz;
	return maiorChave(raiz->dir);
}
// 9. Mostrar a menor chave da ABB
struct tree *menorChave(struct tree *raiz){
	if(!raiz)
		return raiz;
	if(!raiz->esq)
		return raiz;
	return menorChave(raiz->esq);
}
// 10 - Remove nó na Arvore
struct tree *SucessorImediato(struct tree *noAtual, struct tree *noAnterior){
	if(!noAtual->esq){
		if(noAtual->dir){
			if(noAnterior->dir == noAtual)
				noAnterior->dir = noAtual->dir;
			else
				noAnterior->esq = noAtual->dir;
		}
		else
			if(noAnterior->dir == noAtual)
				noAnterior->dir = NULL;
			else
				noAnterior->esq = NULL;
		return noAtual;
	}
	return SucessorImediato(noAtual->esq, noAtual);
}
struct tree *removeABB(struct tree *raiz,struct tree *noAtual, struct tree *noAnterior, int valor){
	if(!raiz)
		return NULL;
	if(noAtual->chave == valor){
		if(!noAtual->dir && !noAtual->esq){
			if(noAnterior->dir == noAtual)
				noAnterior->dir = NULL;
			else
				noAnterior->esq = NULL;
			free(noAtual);
			return raiz;
		}
		else if(noAtual->dir && noAtual->esq){
			struct tree *noSucessor = SucessorImediato(noAtual->dir, noAtual);
			noSucessor->dir = noAtual->dir;
			noSucessor->esq = noAtual->esq;
			if(noAtual == raiz){
				free(noAtual);
				return noSucessor;
			}
			if(noAnterior->dir == noAtual)
				noAnterior->dir = noSucessor;
			else
				noAnterior->esq = noSucessor;
			free(noAtual);
			return raiz;
		}
		else if(noAtual->dir || noAtual->esq){
			if(noAnterior->dir == noAtual){
				if(noAtual->dir)
					noAnterior->dir = noAtual->dir;
				else
					noAnterior->dir = noAtual->esq;
			}
			else{
				if(noAtual->dir)
					noAnterior->esq = noAtual->dir;
				else
					noAnterior->esq = noAtual->esq;
			}
			free(noAtual);
			return raiz;
		}
	}
	if(valor < noAtual->chave)
		removeABB(raiz, noAtual->esq, noAtual, valor);
	if(valor > noAtual->chave)
		removeABB(raiz, noAtual->dir, noAtual, valor);
	return raiz;
}
int arvoreVazia(struct tree *raiz){
	if(!raiz){
		printf("\nA Arvore esta vazia!!\n");
		return 0;
	}
	return 1;
}
int main(){
	int n,i;
	int op,val,menu=1,submenu=1;
	char subOp;
	struct tree *Arvore = NULL;

	printf("\nInforme a quantidade n que quer na Arvore:\n");
		scanf("%d",&n);
	for(i=0; i<n; i++)
		Arvore = insereABB(Arvore, NULL, i);

	while(menu){
		printf("\n(1) - Inserir um nó na ABB");
		printf("\n(2) - Imprimir a ABB");
		printf("\n(3) - Buscar uma chave na ABB");
		printf("\n(4) - Mostrar a altura da ABB");
		printf("\n(5) - Mostrar a quantidade de nós da ABB");
		printf("\n(6) - Mostrar a quantidade de folhas da ABB");
		printf("\n(7) - Mostrar a quantidade de pais da ABB");
		printf("\n(8) - Mostrar a maior chave da ABB");
		printf("\n(9) - Mostrar a menor chave da ABB");
		printf("\n(10) - Remover um nó da ABB");
		printf("\n(11) - Sair\n ==> ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("\nInforme um valor para a chave\n");
				scanf("%d",&val);
				Arvore = insereABB(Arvore, NULL, val);
				break;
			case 2:
				if(!arvoreVazia(Arvore))
					break;
				submenu=1;
				while(submenu){
					printf("\n(I) - Inoder");
					printf("\n(P) - Preorder");
					printf("\n(O) - Postorder");
					printf("\n(S) - Sair\n ==> ");
					scanf(" %c",&subOp);
					switch(subOp){
						case 'I':
							printf("\n ========= \n");
							printf("Inorder: ");
							inorder(Arvore);
							printf("\n ========= \n");
							break;
						case 'P':
							printf("\n ========= \n");
							printf("Preorder: ");
							preorder(Arvore);	
							printf("\n ========= \n");
							break;
						case 'O':
							printf("\n ========= \n");
							printf("Postorder: ");
							postorder(Arvore);
							printf("\n ========= \n");
							break;
						case 'S':
							submenu=0;
							break;
						default:
							printf("\nTecla invalida\n");
					}
				}
				break;
			case 3:
				if(!arvoreVazia(Arvore))
					break;
				printf("\nInforme o valor da chave\n");
				scanf("%d",&val);
				if(busca(Arvore,val))
					printf("\nAchou!!");
				else
					printf("\nNão existe uma chave com este valor\n");
				break;
			case 4:
				if(!arvoreVazia(Arvore))
					break;
				printf("\nAltura da Arvore: %d", altura(Arvore));
				break;
			case 5:
				if(!arvoreVazia(Arvore))
					break;
				printf("\nQuantidade de Nós: %d", contaNos(Arvore));
				break;
			case 6:
				if(!arvoreVazia(Arvore))
					break;
				printf("\nQuantidade de Nós Folhas: %d\n", contaFolhas(Arvore));
				break;		
			case 7:
				if(!arvoreVazia(Arvore))
					break;
				printf("\nQuantidade de Nós Pai: %d\n", contaPais(Arvore));
				break;
			case 8:
				if(!arvoreVazia(Arvore))
					break;
				printf("\nMaior chave: %d\n", maiorChave(Arvore)->chave);
				break;
			case 9:
				if(!arvoreVazia(Arvore))
					break;
				printf("\nMenor chave: %d\n", menorChave(Arvore)->chave);
				break;
			case 10:
				if(!arvoreVazia(Arvore))
					break;
				printf("\nInforme o valor da chave\n");
				scanf("%d",&val);
				Arvore = removeABB(Arvore,Arvore,NULL,val);
				break;
			case 11:
				menu=0;
				break;
			default:
				printf("\nTecla invalida\n");
		}
	}

}