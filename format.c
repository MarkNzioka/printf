#include "main.h"
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
/**
 * handle_percent - handle the %& specifier
 * @count: pointer to char
 */
void handle_percent(int *count)
{
	putchar('%');
	(*count)++;
}
/**
 * handle_unknown - handle unknown specifier
 * @count: pointer to char
 * @modifier: unrecognized modifier character
 */
void handle_unknown(const char modifier, int *count)
{
	putchar('%');
	putchar(modifier);
	*count += 2;
}
/**
 * handle_decimal - handle %d and %i specifiers
 * @args: va_list of arguments
 * @count: pointer to character
 */
void handle_decimal(va_list args, int *count)
{
	int num = va_arg(args, int);
	int num_digits = 0, index, i;
	int temp_num = num;
	char digits[12];

	if (num == 0)
	{
		putchar('0');
		(*count)++;
		return;
	}
	if (num < 0)
	{
		putchar('-');
		temp_num = -num;
		num_digits++;
	}
	while (temp_num != 0)
	{
		temp_num /= 10;
		num_digits++;
	}
	index = num_digits - 1;
	temp_num = num < 0 ? -num : num;
	do {
		digits[index] = temp_num % 10 + '0';
		temp_num /= 10;
		index--;
	} while (temp_num != 0);
	for (i = 0; i < num_digits; i++)
	{
		putchar(digits[i]);
		(*count)++;
	}
}
/**
 * _printf - function for printf
 * @format:format.
 * Return:count.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				break;
			if (*format == ' ')
				return (-1);
			if (*format == 'c')
				handle_char(args, &count);
			else if (*format == 's')
				handle_string(args, &count);
			else if (*format == '%')
				handle_percent(&count);
			else if (*format == 'd' || *format == 'i')
				handle_decimal(args, &count);
			else
				handle_unknown(*format, &count);
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}
