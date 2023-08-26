#include"main.h"
/**
 * handle_decimal - handle %d and %i specifiers
 * @args: va_list of arguments
 * @count: pointer to character
 * @flags: check for flags in the code
 */
void handle_decimal(va_list args, int *count, int flags)
{
	int num = va_arg(args, int);
	int num_digits = 0, index, i;
	int temp_num = num;
	char digits[12];

	if (flags & FLAG_PLUS)
	{
		if (num >= 0)
		{
			putchar('+');
			(*count)++;
		}
	}
	else if (flags & FLAG_SPACE)
	{
		if (num >= 0)
		{
			putchar(' ');
			(*count)++;
		}
	}
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
