#include "../includes/hxd.h"

uint64_t string_len(const char *str)
{
    char *tmp = (char *)str;

    while (*tmp)
        tmp++;
    
    return (tmp - str);
}