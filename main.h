#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

void handle_decimal(va_list args, int *count);
void handle_unknown(const char modifier, int *count);
void handle_percent(int *count);
void handle_string(va_list args, int *count);
void handle_char(va_list args, int *count);
void handle_binary(va_list args, int *count);
void handle_unsigned(va_list args, int *count);
void handle_address(va_list args, int *count);
void handle_octal(va_list args, int *count);
void handle_hex(va_list args, int *count, int uppercase);
void _printf(const char *format, ...);
#endif

