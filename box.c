#include "box.h"

#include <malloc.h>

void pb_delete(ParsedBox **pb) {
    switch ((*pb)->type) {
    case FTYP:
        // ParsedFTYPBox *b = AS_FTYP(*pb);
        ParsedFTYPBox *b = &((*pb)->as.ftyp);
        free(b->major_brand);
        free(b->minor_version);
        for (uint32_t i = 0; i < b->n_compatible_brands; i++) {
            free(b->compatible_brands[i]);
        }
        free(b->compatible_brands);
        break;
    default: break;
    }

    free(*pb);
    *pb = NULL;
}
