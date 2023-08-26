#include "main.h"
/**
 * _printf - function for printf
 * @format:format.
 * Return:count.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, flags;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format == '+')
		{
			flags = FLAG_PLUS;
			format++;
		}
		else if (*format == ' ')
		{
			flags = FLAG_SPACE;
			format++;
		}
		else if (*format == '#')
		{
			flags = FLAG_ALTERNATE;
			format++;
		}
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
			else if (*format == 'b')
				handle_binary(args, &count);
			else if (*format == 'u')
				handle_unsigned(args, &count);
			else if (*format == 'o')
				handle_octal(args, &count);
			else if (*format == 'x' || *format == 'X')
				handle_hex(args, &count, (*format == 'X') ? 1 : 0);
			else if (*format == 'p')
				handle_address(args, &count);
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
