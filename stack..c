#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack* new_stack () {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->topo = 0;
    return st;
}

void stack_push(Stack* s, int value) {
    s->v[s->topo++] = value;
}

int stack_pop (Stack* s) {
    return s->v[--s->topo];
}

void stack_print(Stack* s) {
    for (int i = s->topo - 1; i >= 0; i--) {
        printf("%d\n", s->v[i]);
    }
}

