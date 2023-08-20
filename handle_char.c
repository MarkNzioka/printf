#include"main.h"
/**
 * handle_char - handle the %c specifier
 * @args: va_list of arguments
 * @count: pointer to char
 */
void handle_char(va_list args, int *count)
{
	char c = (char)va_arg(args, int);

	putchar(c);
	(*count)++;
}
