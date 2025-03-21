#include "queue.h"
#include <stdlib.h>

struct Queue {
    int *data;   
    int front;   
    int rear;    
    int len;  
};

//Crea una nueva cola vacía y la devuelve.
Queue queue_create(int len){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        return NULL;
    }
    q->data = (int*)malloc(sizeof(int) * len); 
    if (!q->data) {
        free(q);
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->len = len;
    return q;
} 

//Inserta un elemento al final de la cola.
void queue_enqueue(Queue* q, int d) {
    if (q->rear == q->len - 1) {
        // La cola está llena
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Si la cola estaba vacía, se coloca el primer elemento
    }
    q->rear++;
    q->data[q->rear] = d; // Insertar el dato en el final de la cola
}

//Elimina y devuelve el elemento al frente de la cola.
Data queue_dequeue(Queue* q){
  if (q->front == -1) {
        // La cola está vacía
        return -1; // Valor de error
    }
    int data = q->data[q->front];
    q->front++;
    if (q->front > q->rear) {
        // La cola quedó vacía
        q->front = q->rear = -1;
    }
    return data;
}

//Verifica si la cola está vacía.
bool queue_is_empty(Queue* q) {
    return q->front == -1;
}

//Obtiene el elemento al frente de la cola sin eliminarlo.
Data queue_front(Queue* q){
  if (q->front == -1) {
        // La cola está vacía
        return -1; // Valor de error
    }
    return q->data[q->front];
}

//Vacía la cola, eliminando todos sus elementos
void queue_empty(Queue* q){
  q->front = q->rear = -1; 
}

//Elimina la cola y libera la memoria asociada a ella.
void queue_delete(Queue* q){
   if (q) {
        free(q->data); 
        free(q);      
    }
}
