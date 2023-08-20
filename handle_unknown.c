#include"main.h"
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
