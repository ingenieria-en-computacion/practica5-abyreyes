#include "queue.h"
#include <stdlib.h>

struct Queue {
    Data *data;  
    int head;    
    int tail;    
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
void queue_enqueue(Queue* q, Data d) {
    if (q->tail == q->len - 1) {
        // La cola está llena
        return;
    }
    if (q->head == -1) {
        q->head = 0; 
    }
    q->tail++;
    q->data[q->tail] = d; 
}

//Elimina y devuelve el elemento al frente de la cola.
Data queue_dequeue(Queue* q) {
    if (q->head == -1) {
        // La cola está vacía
        return -1; // Valor de error
    }
    Data d = q->data[q->head];
    q->head++;
    if (q->head > q->tail) {
        // La cola queda vacía
        q->head = q->tail = -1;
    }
    return d;
}

//Verifica si la cola está vacía.
bool queue_is_empty(Queue* q) {
    return q->head == -1;
}

//Obtiene el elemento al frente de la cola sin eliminarlo.
Data queue_front(Queue* q) {
    if (q->head == -1) {
        // La cola está vacía
        return -1; // Valor de error
    }
    return q->data[q->head];
}

//Vacía la cola, eliminando todos sus elementos
void queue_empty(Queue* q) {
    q->head = q->tail = -1; 
}

//Elimina la cola y libera la memoria asociada a ella.
void queue_delete(Queue* q) {
    if (q) {
        free(q->data); 
        free(q);      
    }
}
