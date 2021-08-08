#include "parser.h"

#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("specify a file\n");
        return 1;
    }

    FILE *fd = fopen(argv[1], "r");
    Parser *p = parser_create(fd);

    parse_box(p);

    parser_delete(&p);

    return 0;
}
