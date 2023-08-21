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
