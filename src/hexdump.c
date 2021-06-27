#include "../includes/hxd.h"
#include <stdio.h>

inline void write_hex(unsigned char c)
{
    printf(" %x%x ", c >> 4, c & 0xf);
}

inline void write_ascii(unsigned char c)
{
    printf("%c", (c > ' ') ? c : '.');
}

void hexdump(unsigned char *buffer, uint64_t size)
{
    char *tmp = buffer;

    printf("OFFSET   |  0   1  2   3   4   5   6   7   8   9   A   B   C   D   E   F    |\t  Ascii      |\n"
    "---------|------------------------------------------------------------------|----------------|\n");
    uint64_t byte = 0;
    uint32_t offset = 0;
    uint8_t i = 0;
    char *hex_data = buffer;

    while (byte < size) {
        printf("%08x |", offset);

        for (i = 0; i < 16; i++)
            write_hex(*tmp++);
        
        printf("  |");
        
        for (i = 0; i < 16; i++)
            write_ascii(*hex_data++);
        
        printf("|\n");
        
        offset += 0x10;
        byte += 0x10;
    }
}