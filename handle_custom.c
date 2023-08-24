#include"main.h"
/**
 * handle_binary - handle the b specifier
 * @args: va_list of arguments
 * @count: pointer to character
 */
void handle_binary(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, num_bits = 0;
	unsigned int temp = num;

	if (num == 0)
	{
		putchar('0');
		(*count)++;
		return;
	}
	while (temp > 0)
	{
		temp /= 2;
		num_bits++;
	}
	for (i = num_bits - 1; i >= 0; i--)
	{
		putchar(((num >> i) & 1) + '0');
		(*count)++;
	}
}
void _printf(const char *format, ...) {
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

