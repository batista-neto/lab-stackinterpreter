#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interpret.h"
#include "stack.h"

#define MAX_LINE_LENGTH 1024

static void repl()
{
    char line[MAX_LINE_LENGTH];
    for (;;)
    {
        printf("> ");

        if (!fgets(line, sizeof(line), stdin))
        {
            printf("\n");
            break;
        }

        interpret(line);
    }
}

int interpret_file(char* path) {
    FILE *file = fopen(path, "r");
    char line[MAX_LINE_LENGTH] = {0};

    if (!file) {
        perror(path);
        return EXIT_FAILURE;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        interpret(line);
    }

    if (fclose(file)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    interpret_init();

    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        char *path = argv[1];
        if (interpret_file(path) == EXIT_FAILURE) {
            printf("Erro ao ler o arquivo: %s\n", path);
            return EXIT_FAILURE;
        }
    } else {
        fprintf(stderr, "Uso: %s [arquivo]\n", argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
