#include <stdio.h>
#include <stdio.h>

#include "interpret.h"
#include "stack.h"

static void repl()
{
  char line[1024];
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


int main () {
    interpret_init();
    repl();
    return 0;
}