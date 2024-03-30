#include "monty.h"
/**
 * debug - debug function
 *
 * @args: array of arguments
 * @line_nb: line number
 */

void debug(char **args, int line_nb) {
    printf("line[%d] = ", line_nb + 1);
    for (int i = 0; args && args[i]; i++) {
        printf("[%s] ", args[i]);
    }
    printf("\n");
}
