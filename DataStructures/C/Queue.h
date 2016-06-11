#ifndef Queue
#define Queue

#include "List.h"

//Definicion de estrctura de Cola
typedef LList QQueue;

#include "Queue.h"

/**
* Crea una cola
**/
#define createQueue createList

/**
* Encola un elemento
**/
#define enqueue append

/**
* Desencola un elemento y lo retorna
**/
#define dequue removeFirst

/**
* Indica si una cola está vacía
**/
#define isEmpty isEmpty

/**
* Imprime una cola
**/
#define printQueue printList

/**
* Destruye una cola
**/
#define destroyQueue destroyList

#endif
