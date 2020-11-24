#include<stdio.h>
#include<stdlib.h>

typedef int Item;
typedef struct no{
	Item item;
	struct no *prox;
} *Lista;


Lista no(Item x, Lista p){
	Lista n = malloc(sizeof(struct no));
	n->item = x;
	n->prox = p;
	return n;
}

int tamanho(Lista L){
	int i = 0;
	while(L != NULL){
		i++;
		L = L -> prox;
	}
	return i;
}

void exibe(Lista L){
	printf(" [");
	while(L != NULL){
		printf("%d", L->item);
		L = L->prox;
		printf(L!= NULL ? "," : "");
	}
	printf("]");
}

Item soma(Lista L){
	int acc = 0;
	while(L){
		acc += L -> item;
		L = L -> prox;
	}
	return acc;
}

Item soma_recursiva(Lista L) {
	int acc = soma_recursiva(L);

	if(L == NULL)
		return acc;

	L = L -> prox;

	return acc + L -> item;
}

float media(Lista L){
	float acc = 0.0;
	float qtde = 0.0;

	while(L){
		qtde++;
		acc += L -> item;
		L = L -> prox;
	}

	return acc/qtde;
}

int main(void){
	Lista I = no(4, no(2, no(7, NULL)));
	exibe(I);
	printf("\n Soma: %d", tamanho(I));
	printf("\n Tamanho: %d", soma(I));
	printf("\n Media lista: %f", media(I));
	return 0;
}
