#include "box.h"

#include <malloc.h>

ParsedBox *pb_create_ftyp(char *major_brand, char *minor_version, uint32_t n_compatible_brands) {
    ParsedBox *pb = (ParsedBox *) malloc(sizeof(ParsedBox));
    if (pb) {
        pb->type = FTYP;
        ParsedFTYPBox *b = AS_FTYP(pb);
        (void) b;
        (void) major_brand;
        (void) minor_version;
        (void) n_compatible_brands;
    }
    return pb;
}

void pb_delete(ParsedBox **pb) {
    switch ((*pb)->type) {
    case FTYP: {
        ParsedFTYPBox *b = AS_FTYP(*pb);
        free(b->major_brand);
        free(b->minor_version);
        for (uint32_t i = 0; i < b->n_compatible_brands; i++) {
            free(b->compatible_brands[i]);
        }
        free(b->compatible_brands);
        break;
    }
    default: break;
    }

    free(*pb);
    *pb = NULL;
}
