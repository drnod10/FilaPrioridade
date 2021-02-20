// Fila Prioridade
#include <stdio.h>
#include <stdlib.h>

struct ELEMENTO_FILA{
	int info;
	int prioridade;
	struct ELEMENTO_FILA *prox;
};

typedef struct {
	struct ELEMENTO_FILA *inicio;
	struct ELEMENTO_FILA *final;
} FILA;

// Inicializa a fila como vazia
void init(FILA *f) {
	f->inicio = NULL;
	f->final = NULL;
}

// Verifica se a fila está vazia
int empty(FILA *f) {
	return (f->inicio == NULL && f->final == NULL);
}

// Enfileirar elementos no fim da fila 
void insert(FILA *f, int elemento, int prioridade) {
	struct ELEMENTO_FILA *novo = (struct ELEMENTO_FILA*) malloc(sizeof(struct ELEMENTO_FILA));
	
	novo->info = elemento;
	novo->prioridade = prioridade;
	novo->prox = NULL;
	
	if(f->final != NULL){
		struct ELEMENTO_FILA *navegador = f->inicio;
		struct ELEMENTO_FILA *anterior = NULL;
		while (navegador != NULL && prioridade >= navegador->prioridade){
			anterior = navegador;
			navegador = navegador->prox;
		}
		if (anterior != NULL){
			anterior->prox = novo;
		}
		else
			f->inicio = novo;
	}
	novo->prox = navegador;
	if (navegador == NULL){
		f->final = novo;
	}
}
else{
	f->inicio = f->final = novo;
}
// Desenfileirar elemento do inicio da fila
int deletar(FILA *f) {
	if (empty(f)) {
		printf("Fila vazia!");
		return -1;
	} else {
		int valorInicio = f->inicio->info;
		struct ELEMENTO_FILA *aux = f->inicio;
		f->inicio = f->inicio->prox;
		free(aux);
		if(f->inicio == NULL){
			f->final = f->inicio;
		}
		return valorInicio;
	}
}

//Exibe os elementos da fila
void exibeFila(FILA *f){
	struct ELEMENTO_FILA *navegador;
	
	navegador = f->inicio;
	
	while (navegador != NULL){
		printf("Elemento: %i Prioridade: %i\n", navegador->info, navegador->prioridade);
		
		navegador = navegador->prox;
	}
}
