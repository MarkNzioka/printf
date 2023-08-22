#include <stdio.h>

void custom_printf(const char *format, int value) {
    if (format == NULL) {
        return;
    }

    while (*format != '\0') {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i')) {
            printf("%d", value);
            format += 2;
        } else {
            printf("%c", *format);
            format++;
        }
    }
}

int main() {
    int number = 42;

    custom_printf("This is a number: %d\n", number);
    custom_printf("Another number: %i\n", number);

    return 0;
}


