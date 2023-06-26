#include <stdio.h>
#include <limits.h>
#include "main.h"
int main(void)
{
int length1;
int length2;
unsigned int num;
void *address;
length1 = _printf("Let's try to printf a simple sentence.\n");
length2 = printf("Let's try to printf a simple sentence.\n");
num = (unsigned int)INT_MAX + 1024;
address = (void *)0x7ffe637541f0;
_printf("Character:[%c]\n", 'H');
printf("Character:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
printf("String:[%s]\n", "I am a string !");
_printf("Length:[%d, %i]\n", length1, length1);
printf("Length:[%d, %i]\n", length2, length2);
_printf("Negative:[%d]\n", -762534);
printf("Negative:[%d]\n", -762534);
_printf("Unsigned:[%u]\n", num);
printf("Unsigned:[%u]\n", num);
_printf("Unsigned octal:[%o]\n", num);
printf("Unsigned octal:[%o]\n", num);
_printf("Unsigned hexadecimal:[%x, %X]\n", num, num);
printf("Unsigned hexadecimal:[%x, %X]\n", num, num);
_printf("Address:[%p]\n", address);
printf("Address:[%p]\n", address);
length1 = _printf("Percent:[%%]\n");
length2 = printf("Percent:[%%]\n");
_printf("Len:[%d]\n", length1);
printf("Len:[%d]\n", length2);
_printf("Unknown:[%s]\n", "r");
printf("Unknown:[%s]\n", "r");
return (0);
}
