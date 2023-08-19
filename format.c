#include "main.h"
/**
*_printf - function for printf
*@format:format.
*Return:count.
*/
int _printf(const char *format, ...)
{
    va_list args;
    int count= 0;
    char c;
    char *str;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == '\0')
                break;

            if (*format == 'c')
            {
                c = (char)va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                str = va_arg(args, char *);
                while (*str)
                {
                    putchar(*str);
                    str++;
                    count++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                count++;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
