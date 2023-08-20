#include"main.h"
/**
 * handle_percent - handle the %& specifier
 * @count: pointer to char
 */
void handle_percent(int *count)
{
	putchar('%');
	(*count)++;
}
