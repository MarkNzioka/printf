#include"main.h"
/**
 * handle_unsigned - handle the u specifier
 * @args: va_list of arguments
 * @count: pointer to character
 */
void handle_unsigned(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int index, i, num_digits = 0;
	unsigned int temp = num;
	char digits[12];

	if (num == 0)
	{
		putchar('0');
		(*count)++;
		return;
	}
	while (temp != 0)
	{
		temp /= 10;
		num_digits++;
	}
	index = num_digits - 1;
	temp = num;
	do {
		digits[index] = temp % 10 + '0';
		temp /= 10;
		index--;
	} while (temp != 0);
	for (i = 0; i < num_digits; i++)
	{
		putchar(digits[i]);
		(*count)++;
	}
}
