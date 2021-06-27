#include "../includes/hxd.h"
#include <stddef.h>

static inline uint8_t hex_nibble(char c)
{    
    return ((c >= '0' && c <= '9')  \
    ? (c & 0xF) : (c >= 'a' && c <= 'f') \
    ? (10 + (c - 'a')) : (c >= 'A' && c <= 'F') \
    ? (10 + (c - 'A')) : 0);
}

char *hex_encode(char *dst, char *src, uint64_t buffer_size)
{
    if ((string_len(src) << 1) >= buffer_size)
        return (NULL);
    
    char *tmp = dst;

    while (*src) {
        *tmp++ = HEX_TAB[*src >> 4];
        *tmp++ = HEX_TAB[*src++ & 0xF];
    }

    *tmp = 0;
    
    return (dst);
}

char *hex_decode(char *dst, char *src, uint64_t buffer_size)
{
    if ((string_len(src) >> 1) > buffer_size)
        return (NULL);
    
    char *tmp = dst;

    while (*src) {
        *tmp = hex_nibble(*src++);
        *tmp <<= 4;
        *tmp += hex_nibble(*src++);
        tmp++;
    }

    *tmp = 0;

    return (dst);
}