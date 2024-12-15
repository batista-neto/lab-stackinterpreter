#ifndef stack_h
#define stack_h

typedef struct stack {
    int v[100];
    int topo;
} Stack;

Stack* new_stack();
void stack_push(Stack* s, int value);
int stack_pop (Stack* s);
void stack_print(Stack* s);


#endif