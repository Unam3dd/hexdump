#include <stdio.h>
#include "hxd.h"
#include <windows.h>

int main(int argc, char **argv)
{

    if (argc < 2) {
        fprintf(stderr, "usage : %s <binary>", argv[0]);
        return (1);
    }

    FILE *fp = fopen(argv[1], "rb");

    if (!fp)
        fprintf(stderr, "[-] File not found !\n");
    
    fseek(fp, 0L, SEEK_END);

    size_t size_bytes = ftell(fp);

    fseek(fp, 0L, SEEK_SET);

    char *Image = VirtualAlloc(NULL, size_bytes + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

    fread(Image, sizeof(char), size_bytes, fp);

    Image[size_bytes + 1] = 0;

    fclose(fp);

    hexdump(Image, size_bytes);

    VirtualFree(Image, 0, MEM_RELEASE);

    return (0);
}