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
int _printf(const char *format, ...);

#endif
