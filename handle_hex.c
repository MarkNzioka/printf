#include"main.h"
/**
 * handle_hex - handle tje x and X specifiers
 * @args: va_list of arguments
 * @count: pointer to character
 * @flags: chack for flags
 * @uppercase: determine whether uppercase or lowercase
 */
void handle_hex(va_list args, int *count, int flags, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	int index, i, remainder, num_digits = 0;
	unsigned int temp = num;
	char digits[12];

	if (flags & FLAG_ALTERNATE)
	{
		if (uppercase)
		{
			putchar('0');
			putchar('X');
		}
		else
		{
			putchar('0');
			putchar('x');
		}
		(*count) += 2;
	}
	if (num == 0)
	{
		putchar('0');
		(*count)++;
		return;
	}
	while (temp != 0)
	{
		temp /= 16;
		num_digits++;
	}
	index = num_digits - 1;
	temp = num;
	do {
		remainder = temp % 16;
		digits[index] = (remainder < 10) ? (remainder + '0') :
			(remainder - 10 + (uppercase ? 'A' : 'a'));
		temp /= 16;
		index--;
	} while (temp != 0);
	for (i = 0; i < num_digits; i++)
	{
		putchar(digits[i]);
		(*count)++;
	}
}
/**
 * handle_lower_hex - handle lower case
 * @args: va_list of arguments
 * @count: pointer to character
 */
void handle_lower_hex(va_list args, int *count, int flags)
{
	handle_hex(args, count, flags, 0);
}
/**
 * handle_upper_hex - handle upper case
 * @args: va_list of arguments
 * @count: pointer to character
 */
void handle_upper_hex(va_list args, int *count, int flags)
{
	handle_hex(args, count, flags, 1);
}
