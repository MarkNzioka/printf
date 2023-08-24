#include"main.h"
/**
 * handle_address - handle the p specifier
 * @args: va_list of arguments
 * @count: pointer to count
 */
void handle_address(va_list args, int *count)
{
	void *ptr = va_arg(args, void *);
	unsigned long address = (unsigned long)ptr;
	int i, num_digits = 0;
	unsigned int digit;
	unsigned long temp_address = address;
	char digits[16];

	putchar('0');
	putchar('x');
	if (address == 0)
	{
		putchar('0');
		*count += 3;
		return;
	}
	while (temp_address != 0)
	{
		temp_address >>= 4;
		num_digits++;
	}
	if (num_digits == 0)
	{
		num_digits = 1;
		putchar('0');
		putchar('x');
	}
	for (i = 0; i < num_digits; i++)
	{
		digit = (address >> (4 * i)) & 0xF;
		digits[num_digits - i - 1] = (digit < 10) ?
			(digit + '0') : (digit - 10 + 'a');
	}
	for (i = 0; i < num_digits; i++)
	{
		putchar(digits[i]);
		(*count)++;
	}
}
