#include"main.h"
/**
 * handle_string - handle the %s specifier
 * @args: va_list of arguments
 * @count: pointer to char
 */
void handle_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		fputs("(null)", stdout);
		*count += 6;
	}
	else
	{
		while (*str)
		{
			putchar(*str);
			str++;
			(*count)++;
		}
	}
}
