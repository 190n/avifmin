#ifndef __BOX_H__
#define __BOX_H__

#include <stdint.h>

typedef struct Box {
    uint32_t size;
    uint32_t type;
    unsigned char *data;
} Box;

typedef struct FTYPBox {
    Box box;
    uint32_t major_brand;
    uint32_t minor_version;
    uint32_t n_compatible_brands;
    uint32_t *compatible_brands;
} FTYPBox;

typedef struct ParsedFTYPBox {
    unsigned char *major_brand;
    unsigned char *minor_version;
    uint32_t n_compatible_brands;
    unsigned char **compatible_brands;
} ParsedFTYPBox;

typedef enum ParsedBoxType {
    FTYP,
} ParsedBoxType;

typedef struct ParsedBox {
    ParsedBoxType type;
    union {
        ParsedFTYPBox ftyp;
    } as;
} ParsedBox;

//
// For a ParsedBox that is an FTYP box, access it as a ParsedFTYPBox
//
// ParsedBox *pb: pointer to the ParsedBox
//
// returns ParsedFTYPBox*
//
#define AS_FTYP(pb) (&((pb)->as.ftyp))

//
// Delete a parsed box
//
// pb: double pointer to the parsed box
//
void pb_delete(ParsedBox **pb);

#endif
