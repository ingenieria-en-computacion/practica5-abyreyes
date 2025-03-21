#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Crea una nueva pila vacía y la devuelve.
Stack *stack_create(){
   Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }
    s->top = NULL;
    return s;
}

//Inserta un elemento en la parte superior de la pila.
void stack_push(Stack* s, Data d){
      if (s == NULL) {
        return; // No se puede operar en una pila nula
    }
    Node *n = new_node(d);
    if (n == NULL) {
        return; // Fallo al asignar memoria para el nodo
    }
    n->next = s->top;
    s->top = n;
}

//Elimina y devuelve el elemento en la parte superior de la pila.
Data stack_pop(Stack* s){
  if (s == NULL || s->top == NULL) {
        return -1;
    }
    Node *temp = s->top;
    Data data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

//Verifica si la pila está vacía.
int stack_is_empty(Stack* s){
  if (s == NULL) {
        return -1;
    }
    return s->top == NULL;
}

//Vacía la pila, eliminando todos sus elementos.
void stack_empty(Stack* s){
   if (s == NULL) {
        return;
    }
    while (!stack_is_empty(s)) {
        stack_pop(s);
    }
}

//Elimina la pila y libera la memoria asociada a ella.
void stack_delete(Stack *s){
   if (s == NULL) {
        return;
    }
    stack_empty(s);
    free(s);
}

//Imprime los elementos de la pila.
void stack_print(Stack *s){
  if (s == NULL) {
        printf("[Pila inválida]\n");
        return;
    }
    Node *current = s->top;
    printf("Pila: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
