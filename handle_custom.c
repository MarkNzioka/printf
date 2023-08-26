#include <stdio.h>
#include <stdarg.h>
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

/**
 * custom_string - Handles the %S specifier
 * @args: The va_list containing the arguments
 * @count: Pointer to the character count
 */
void custom_string(va_list args, int *count) {
    const char *str = va_arg(args, const char *);

    while (*str) {
        if (*str >= 32 && *str < 127) {
            putchar(*str);
            (*count)++;
        } else {
            (*count) += 4;
            putchar('\\');
            putchar('x');
            putchar((*str >> 4) < 10 ? (*str >> 4) + '0' : (*str >> 4) - 10 + 'A');
            putchar((*str & 0x0F) < 10 ? (*str & 0x0F) + '0' : (*str & 0x0F) - 10 + 'A');
        }
        str++;
    }
}
