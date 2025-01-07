#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "interpret.h"
#include "stack.h"
#include "list.h"

Stack* s = NULL;
List* l = NULL;

void interpret_init() {
  s = new_stack();
  l = new_list();
}

int isValid() {
    if(s->topo <= 1) {
        printf ("Não há argumentos suficientes\n");
        return 0;
    }
    return 1;
}

void interpret (const char *source) {
    char op[10];
    char arg[10];

    sscanf (source, "%s%s", op, arg);
    printf("operação: %s\n", op);
    printf("argumento: %s\n",  arg);

    if(strcmp(op, "push") == 0 ) {
        int value;
        if(sscanf(arg, "%d", &value) == 0) {
            value = list_get(l, arg);
        }
        stack_push(s, value);
    }

    if(strcmp(op, "pop") == 0 ) {
        int value = stack_pop(s);
        list_append(l, arg, value);
    }

    if(strcmp(op, "add") == 0 ) {
        if(!isValid()) {
            return;
        }
        int first = stack_pop(s);
        int second = stack_pop(s);
        stack_push(s, first + second);
    }

    if(strcmp(op, "sub") == 0 ) {
        if(!isValid()) {
            return;
        }
        int first = stack_pop(s);
        int second = stack_pop(s);
        stack_push(s, first - second);
    }

    if(strcmp(op, "div") == 0 ) {
        if(!isValid()) {
            return;
        }
        int first = stack_pop(s);
        int second = stack_pop(s);
        stack_push(s, first / second);
    }

    if(strcmp(op, "mul") == 0 ) {
        if(!isValid()) {
            return;
        }
        int first = stack_pop(s);
        int second = stack_pop(s);
        stack_push(s, first * second);
    }

    if(strcmp(op, "print") == 0 ) {
        if(s->topo == 0) {
            printf ("Não há argumentos suficientes na pilha\n");
            return;
        }
        printf("%d foi retirado da pilha\n", stack_pop(s));
    }
}