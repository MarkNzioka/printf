#include"main.h"
/**
 * handle_octal - handle the o specifier
 * @args: va_list of arguments
 * @count: pointer to character
 */
void handle_octal(va_list args, int *count)
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
		temp /= 8;
		num_digits++;
	}
	index = num_digits - 1;
	temp = num;
	do {
		digits[index] = temp % 8 + '0';
		/*if (digits[index] > '7')*/
			/*digits[index] += 'A' - '9' - '1';*/
		temp /= 8;
		index--;
	} while (temp != 0);
	for (i = 0; i < num_digits; i++)
	{
		putchar(digits[i]);
		(*count)++;
	}
}
