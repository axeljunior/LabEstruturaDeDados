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
		printf("%d ", raiz->chave);
		inorder(raiz->dir);
	}
}
// 2.2 - Preorder
void preorder(struct tree *raiz){
	if(raiz != NULL){
		printf("%d ", raiz->chave);
		preorder(raiz->esq);
		preorder(raiz->dir);
 	}
}
// 2.3 - Postorder
void postorder(struct tree *raiz){
	if(raiz != NULL){
		postorder(raiz->esq);
		postorder(raiz->dir);
		printf("%d ", raiz->chave);
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
//==============================================================================//
//==============================================================================//

int nosComUmFilho(struct tree *raiz){
	if(!raiz)
		return 0;
	if(raiz->esq || raiz->dir){
		if(!raiz->esq || !raiz->dir){
			return 1 + nosComUmFilho(raiz->esq) + nosComUmFilho(raiz->dir);
		}
	}
	return nosComUmFilho(raiz->esq) + nosComUmFilho(raiz->dir);
}
int main(){
	int vetor[MAX] = {40, 25, 23,12,10, 35,33, 48, 65, 67, 44, 34, 46};
	struct tree *Arvore = NULL;
	struct tree *Teste = NULL;

	for(int i=0; i<MAX; i++)
		Arvore = insereABB(Arvore, NULL, vetor[i]);

	printf("\nInorder: ");
	inorder(Arvore);
	printf("\nPostorder: ");
	postorder(Arvore);
	printf("\nPreorder: ");
	preorder(Arvore);
	
	Teste = insereABB(Teste, NULL, 32);
	Teste = insereABB(Teste, NULL, 42);
	Teste = insereABB(Teste, NULL, 22);

	printf("\nNós com apenas um filho: %d", nosComUmFilho(Arvore));
}