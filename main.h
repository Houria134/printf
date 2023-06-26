#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int _print_str(char *str);
int write_char(char c);
int write_string(char *str);
int print_number(int num, char *num_buffer, int char_count);
#endif
