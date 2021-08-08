#include "parser.h"

#include <malloc.h>
#include <string.h>

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

ParsedBox *parse_box(Parser *p) {
    char type[5];
    type[4] = '\0';
    // skip size for now
    fseek(p->fd, 4, SEEK_SET);
    // read the type
    fread(type, 4, 1, p->fd);

    if (strcmp(type, "ftyp") == 0) {
        printf("ftyp box\n");
    }

    return NULL;
}
