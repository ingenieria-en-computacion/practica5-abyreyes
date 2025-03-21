#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>

// Crea una cola vacía y la devuelve
Queue queue_create() {
    Queue q;
    q.head = -1;
    q.tail = -1;
    q.len = 0;
    return q;
}

// Inserta un elemento al final de la cola
void queue_enqueue(Queue* q, Data d) {
    if (q->len == TAM) {
        printf("Error: La cola está llena.\n");
        return;
    }
    if (q->len == 0) {
        q->head = 0;
        q->tail = 0;
    } else {
        q->tail = (q->tail + 1) % TAM;
    }
    q->datos[q->tail] = d;
    q->len++;
}

// Elimina y devuelve el elemento al frente de la cola
Data queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Error: La cola está vacía.\n");
        return -1; // Suponiendo que -1 indica error
    }
    Data d = q->datos[q->head];
    if (q->len == 1) {
        q->head = -1;
        q->tail = -1;
    } else {
        q->head = (q->head + 1) % TAM;
    }
    q->len--;
    return d;
}

// Verifica si la cola está vacía
bool queue_is_empty(Queue* q) {
    return q->len == 0;
}

// Obtiene el elemento al frente de la cola sin eliminarlo
Data queue_front(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Error: La cola está vacía.\n");
        return -1; // Suponiendo que -1 indica error
    }
    return q->datos[q->head];
}

// Vacía la cola eliminando todos sus elementos
void queue_empty(Queue* q) {
    q->head = -1;
    q->tail = -1;
    q->len = 0;
}

