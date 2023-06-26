#include <unistd.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int write_char(char c);
int write_string(char *str);
int print_number(int num, char *num_buffer, int char_count);
int _printf(const char *format, ...)
{
va_list args;
int char_count = 0;
int number;
char num_buffer[1024];
int i = 0;
va_start(args, format);
while (format && format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == 'd' || format[i] == 'i')
{
number = va_arg(args, int);
char_count += print_number(number, num_buffer, char_count);
}
else if (format[i] == 'c')
{
char character = (char)va_arg(args, int);
char_count += write_char(character);
}
else if (format[i] == 's')
{
char *string = va_arg(args, char *);
char_count += write_string(string);
}
else if (format[i] == '%')
{
char_count += write_char('%');
}
}
else
{
char_count += write_char(format[i]);
}
i++;
}
va_end(args);
return (char_count);
}
int write_char(char c)
{
return (write(1, &c, 1));
}
int write_string(char *str)
{
int i = 0;
while (str && str[i])
{
write_char(str[i]);
i++;
}
return (i);
}
int print_number(int num, char *num_buffer, int char_count)
{
int i = 0;
int sign = 0;
unsigned int number;
if (num < 0)
{
sign = 1;
number = -num;
num_buffer[i++] = '-';
}
else
{
number = num;
}
if (number == 0)
{
num_buffer[i++] = '0';
}
else
{
while (number != 0)
{
num_buffer[i++] = (number % 10) + '0';
number /= 10;
}
}
while (--i >= sign)
{
write_char(num_buffer[i]);
char_count++;
}
return (char_count);
}
