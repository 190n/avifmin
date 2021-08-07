#ifndef __BOX_H__
#define __BOX_H__

#include <stdint.h>

typedef struct Box {
    uint32_t size;
    uint32_t type;
    unsigned char *data;
} Box;

#endif
