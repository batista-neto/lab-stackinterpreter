#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct item {
    char* name;
    int value;
    struct item* prox;
} Item;

typedef struct list {
    Item *inicio, *fim;
} List;

List* new_list() {
    List* self = malloc(sizeof(List));
    self->inicio = NULL;
    self->fim = NULL;
    return self;
}

Item* newItem(char *name, int value, struct item* prox) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    newItem->name = malloc(strlen(name) + 1);
    strcpy(newItem->name, name);
    newItem->value = value;
    newItem->prox = prox;
    return newItem;
}

int list_get(List* l, char* key) {
    Item* it = l->inicio;
    while (it != NULL) {
        if (strcmp(key, it->name) == 0) {
            return it->value;
        }
        it = it->prox;
    }
    return -1;
}

void list_set(List* l, char* key, int value) {
    Item* it = l->inicio;
    while (it != NULL) {
        if (strcmp(key, it->name) == 0) {
            it->value = value;
            return;
        }
        it = it->prox;
    }
    Item* new_Item = newItem(key, value, l->inicio);
    l->inicio = new_Item;
}

void list_append(List* l, char* key, int value) {
    int exist = list_get(l, key);
    if (exist != -1) {
        list_set(l, key, value);
        return;
    }
    
    Item* new_Item = newItem(key, value, NULL);
    if (l->inicio == NULL) {
        l->inicio = new_Item;
        l->fim = new_Item;
        return;
    }
    
    l->fim->prox = new_Item;
    l->fim = new_Item;
}

void list_print(List* l) {
    printf("[");
    Item* it = l->inicio;
    while (it != NULL) {
        printf("%s %d, ", it->name, it->value);
        it = it->prox;
    }
    printf("]\n");
}