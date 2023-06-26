#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _putchar - Writes the character to stdout
 * @c: Character to write
 * Return: On success 1 , On error -1
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * _print_str - Prints string
 * @str: String to be printed
 * Return: Number of characters printed
 */
int _print_str(char *str)
{
int count = 0;
int i = 0;
if (str == NULL)
str = "(null)";
while (str[i])
{
count += _putchar(str[i]);
i++;
}
return (count);
}
/**
 * _printf - Prints output according to formay
 * @format: Character string contains zero or more directives
 * Return: Number of characters printed but not bytes
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int i = 0;
if (format == NULL)
return (-1);
va_start(args, format);
while (format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
return (-1);
switch (format[i])
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
count += _print_str(va_arg(args, char *));
break;
case '%':
count += _putchar('%');
break;
default:
count += _putchar('%');
count += _putchar(format[i]);
break;
}
}
else
{
count += _putchar(format[i]);
}
i++;
}
va_end(args);
return (count);
}
