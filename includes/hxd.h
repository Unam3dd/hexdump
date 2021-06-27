#pragma once
#include <stdint.h>

// hex_tab.c
extern const char HEX_TAB[16];

// utils.c
uint64_t string_len(const char *str);

// hex.c
static inline uint8_t hex_nibble(char c);
char *hex_encode(char *dst, char *src, uint64_t buffer_size);
char *hex_decode(char *dst, char *src, uint64_t buffer_size);

// hexdump.c
void hexdump(unsigned char *buffer, uint64_t size);
void write_hex(unsigned char c);
void write_ascii(unsigned char c);