#include "List.h"

/**
* Convierte un puntero a void en un string, solo funciona si este es un string
**/
char* defaultToString(void *v){
	return (char *)v;
}

/**
* Crea una lista vacia
**/
LList* createList(){
	LList* l = (LList*) malloc(sizeof(LList));
	L_firstNode(l) = NULL;
	L_lastNode(l) = NULL;
	L_size(l) = 0;
	l->toString = defaultToString;
	return l;
}

/**
* Crea un nodo con un Valor
**/
Node* createNode(void *value){
	Node* node = (Node*) malloc(sizeof(Node));
	N_data(node) = value;
	N_next(node) = NULL;
	N_back(node) = NULL;
	return node;
}

/**
* Agrega un elemento al final de la lista
**/
void append(LList* l, void *value){
	//Evita acceder a cola nula
	if (l == NULL){
		return;
	}
	//Crea el nodo
	Node* node = createNode(value);
	//Caso lista vacia
	if (L_size(l) == 0){
		L_firstNode(l) = node;
		L_lastNode(l) = node;
	}
	else{
		N_next(L_lastNode(l)) = node;
		N_back(node) = L_lastNode(l);
		L_lastNode(l) = node;
	}
	L_size(l)++;
}

/**
* Agrega un elemento al principio de la lista
**/
void prepend(LList* l, void *value){
	//Evita acceder a cola nula
	if (l == NULL){
		return;
	}
	//Crea el nodo
	Node* node = createNode(value);
	//Caso Lista vacia
	if (L_size(l) == 0){
		L_firstNode(l) = node;
		L_lastNode(l) = node;
	}
	else{
		N_next(node) = L_firstNode(l);
		L_firstNode(l) = node;
	}
	L_size(l)++;
}

/**
* Elimina el primer elemento de la lista y lo retorna
**/
void* removeFirst(LList* l){
	//Evita acceder a cola nula
	if (l == NULL){
		return NULL;
	}
	Node* f = L_firstNode(l);
	void* value = N_data(f);
	L_firstNode(l) = N_next(f);
	L_size(l)--;
	free(f);
	return value;
}

/**
* Elimina el ultimo elemento de la lista y lo retorna
**/
void* removeLast(LList* l){
	//Evita acceder a cola nula
	if (l == NULL){
		return NULL;
	}
	//Caso lista vacia
	if (L_size(l) == 0){
		return NULL;
	}
	Node* oldLast = L_lastNode(l);
	void* value = N_data(oldLast);
	//Lista con un solo elemento
	if (L_size(l) == 1){
		L_lastNode(l) = NULL;
		L_firstNode(l) = NULL;
	}
	else{
		L_lastNode(l) = N_back(oldLast);
		N_next(L_lastNode(l)) = NULL;
	}
	L_size(l)--;
	free(oldLast);
	return value;
}

/**
* Indica si la lista está vacía
**/
int isEmpty(LList* l){
	//Evita acceder a cola nula
	if (l == NULL){
		return -1;
	}
	return L_size(l) == 0;
}

/**
* Imprime la lista
**/
void printList(LList* l){
	if (l->toString == NULL){
		printf("No se puede imprimir la lista porque no seteó la funcion de impresion\n");
		return;
	}
	Node* node = L_firstNode(l);
	int i;
	char* str;
	for (i = 0; i < L_size(l); i++){
		str = l->toString(N_data(node));
		printf("%s -> ", str);
		node = N_next(node);
	}
	printf("|\n");
}

/**
* Destruye la lista
**/
void destroyList(LList* l){
	//Evita acceder a cola nula
	if (l == NULL || L_size(l) == 0){
		return;
	}
	Node* n = NULL;
	while ((n = L_firstNode(l)) != NULL){
		L_firstNode(l) = N_next(n);
		free(n);
	}
	free(l);
}

/**
* Toma una lista y una funcion booleana que retorna un nodo de la lista (Buscar)
**/
Node* getNode(LList* l, int (*isThis) (void *,...)){
	Node* nod = L_firstNode(l);
	while (nod != NULL){
		if (isThis(N_data(nod))){
			return nod;
		}
		nod = N_next(nod);
	}
	return NULL;
}

/**
* Toma una lista y una funcion booleana y retorna un elemento de la lista (Buscar)
**/
void* getElement(LList* l, int (*isThis) (void *,...)){
	Node* node = getNode(l, isThis);
	return node == NULL ? NULL : N_data(node);
}

/**
* Elimina un elemento de la lista en base a una funcion booleana (Elimina una ocurencia)
**/
int removeElement(LList* l, int (*isThis) (void *,...)){
	if (isThis(N_data(L_firstNode(l)))){
		removeFirst(l);
		return 1;
	}
	if (isThis(N_data(L_lastNode(l)))){
		removeLast(l);
		return 1;
	}
	Node* node = getNode(l, isThis);
	if (node == NULL){
		return 0;
	}
	Node* prev = N_back(node);
	Node* next = N_next(node);
	N_next(prev) = next;
	N_back(next) = prev;
	free(node);
	return 1;
}
