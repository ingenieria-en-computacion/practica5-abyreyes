#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

//Crea una nueva pila vacía y la devuelve.
Stack stack_create(){
  Stack s;
    s.top = -1; // Inicializa la pila como vacía
    return s;
}

//Inserta un elemento en la parte superior de la pila.
void stack_push(Stack* s, Data d){
  if (s->top >= TAM - 1) {
        printf("Error: La pila está llena.\n");
        return;
    }
    s->data[++(s->top)] = d;
}

//Elimina y devuelve el elemento en la parte superior de la pila.
Data stack_pop(Stack* s){
  if (stack_is_empty(s)) {
        printf("Error: La pila está vacía.\n");
        return -1; // Valor de error
    }
    return s->data[(s->top)--];
}

//Verifica si la pila está vacía.
bool stack_is_empty(Stack* s){
    return s->top == -1;
}

//Vacía la pila, eliminando todos sus elementos.
void stack_empty(Stack* s){
  s->top = -1;
}

//Imprime los elementos de la pila.
void stack_print(Stack *s){
   if (stack_is_empty(s)) {
        printf("La pila está vacía.\n");
        return;
    }
    printf("Elementos de la pila: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
