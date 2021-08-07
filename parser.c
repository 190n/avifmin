#include "parser.h"

#include <malloc.h>

struct Parser {
    FILE *fd;
    bool done;
};

Parser *parser_create(FILE *fd) {
    Parser *p = (Parser *) malloc(sizeof(Parser));
    if (p) {
        p->fd = fd;
        p->done = false;
    }

    return p;
}

void parser_delete(Parser **p) {
    fclose((*p)->fd);
    free(*p);
    *p = NULL;
}

bool parser_done(Parser *p) {
    return p->done;
}
