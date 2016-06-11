#ifndef List
#define List

#include <stdlib.h>
#include <stdio.h>

//Definición de estructura de un nodo
struct _Node{
  void* data;
  struct _Node* next;
  struct _Node* back;
};
typedef struct _Node Node;

//Definicion de estructura Lista
struct _List{
    Node* first;
    Node* last;
    int size;
    char* (*toString)(void*);
};
typedef struct _List LList;

//Metodos para acceder a los elementos de las estructuras
#define N_next(x) x->next
#define N_back(x) x->back
#define N_data(x) x->data
#define L_firstNode(x) x->first
#define L_lastNode(x) x->last
#define L_size(x) x->size

/**
* Convierte un puntero a void en un string, solo funciona si este es un string
**/
char* defaultToString(void* v);

/**
* Crea una lista vacia
**/
LList* createList();

/**
* Crea un nodo con un Valor
**/
Node* createNode(void* value);

/**
* Agrega un elemento al final de la lista
**/
void append(LList* l, void* value);

/**
* Agrega un elemento al principio de la lista
**/
void prepend(LList* l, void* value);

/**
* Elimina el primer elemento de la lista y lo retorna
**/
void* removeFirst(LList* l);

/**
* Elimina el ultimo elemento de la lista y lo retorna
**/
void* removeLast(LList* l);

/**
* Indica si la lista está vacía
**/
int isEmpty(LList* l);

/**
* Imprime la lista
**/
void printList(LList* l);

/**
* Destruye la lista
**/
void destroyList(LList* l);

/**
* Toma una lista y una funcion booleana que retorna un nodo de la lista (Buscar)
**/
Node* getNode(LList* l, int(*isThis)(void*, ...));

/**
* Toma una lista y una funcion booleana y retorna un elemento de la lista (Buscar)
**/
void* getElement(LList* l, int(*isThis)(void*, ...));

/**
* Elimina un elemento de la lista en base a una funcion booleana (Elimina una ocurencia)
**/
int removeElement(LList* l, int(*isThis)(void*, ...));

#endif
