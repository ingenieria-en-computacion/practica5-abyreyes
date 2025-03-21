#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    Data *data;
    int top;
    int capacity; // Se agrega la capacidad de la pila
} Stack;

//Crea una nueva pila vacía y la devuelve.
Stack stack_create(int len){
   Stack s;
    s.data = (Data*)malloc(len * sizeof(Data));
    if (!s.data) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        s.top = -1;
        s.capacity = 0;
    } else {
        s.top = -1;
        s.capacity = len;
    }
    return s;
}

//Inserta un elemento en la parte superior de la pila.
void stack_push(Stack* s, Data d){
  if (s->top + 1 < s->capacity) {
        s->data[++s->top] = d;
    } else {
        fprintf(stderr, "Error: La pila está llena.\n");
    }
}

//Elimina y devuelve el elemento en la parte superior de la pila.
Data stack_pop(Stack* s){
  if (stack_is_empty(s)) {
        fprintf(stderr, "Error: La pila está vacía.\n");
        return -1; // Valor de error
    }
    return s->data[s->top--];
}

//Verifica si la pila está vacía.
int stack_is_empty(Stack* s){
  return (s->top == -1);
}

//Vacía la pila, eliminando todos sus elementos.
void stack_empty(Stack* s){
  s->top = -1;
}

//Elimina data y libera la memoria asociada.
void stack_delete(Stack *s){
  free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

//Imprime los elementos de la pila.
void stack_print(Stack *s){
if (stack_is_empty(s)) {
        printf("La pila está vacía.\n");
        return;
    }
    printf("Pila: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
