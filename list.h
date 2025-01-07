#ifndef list_h
#define list_h

typedef struct list List;

List* new_list();
void list_append(List* l, char* key, int value);
int list_get(List* l, char* key);
void list_set(List* l, char* key, int value);
int list_exist(List* l, char* key);
void list_print(List* l);

#endif