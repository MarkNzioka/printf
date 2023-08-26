#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

#define FLAG_PLUS      (1 << 0)
#define FLAG_SPACE     (1 << 1)
#define FLAG_ALTERNATE (1 << 2)

void handle_decimal(va_list args, int *count, int flags);
void handle_unknown(const char modifier, int *count);
void handle_percent(int *count);
void handle_string(va_list args, int *count);
void handle_char(va_list args, int *count);
void handle_binary(va_list args, int *count);
void handle_unsigned(va_list args, int *count);
void handle_address(va_list args, int *count);
void handle_octal(va_list args, int *count);
void handle_hex(va_list args, int *count, int flags , int uppercase);
int _printf(const char *format, ...);
void custom_string(va_list args, int *count);
#endif

