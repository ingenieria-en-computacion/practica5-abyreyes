#include "node.h"
#include <stdio.h>
#include <stdlib.h>

//Crea un nuevo nodo con los datos proporcionados y lo devuelve.
Node *new_node(Data d){
  Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        return NULL; // La asignación de memoria falló
    }
    n->data = d;
    n->next = NULL;
    return n;
}

//Elimina un nodo y libera la memoria asociada a él.
void delete_node(Node* n){
   if (n == NULL || n->next != NULL) {
        return; // Solo eliminamos nodos sin enlaces al siguiente
    }
    free(n);
}

//Imprime la información contenida en un nodo.
void print_node(Node* n){
   if (n == NULL) {
        printf("[Nodo inválido]\n");
        return;
    }
    printf("[Data: %d, Next: %p]\n", n->data, (void*)n->next);
}
