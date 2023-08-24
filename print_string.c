#include "main.h"
/*
 * _printf - handle the s specifier
 * format:format
 * @args: va_list of arguments
*/
void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        const char *str;  
        if (*format == '%' && *(format + 1) == 'S') {
            format += 2;
            str = va_arg(args, const char *);  

            while (*str) {
                if (*str >= 32 && *str < 127) {
                    putchar(*str);
                } else {
                    printf("\\x%02X", (unsigned char)*str);
                }
                str++;
            }
        } else {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
}
