#include "main.h"

/* Print a  Char */

/**
 * print_char - Prints a char
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates ready flags
 * @width: Width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: number of chars printed
 */
int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char c =va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/* Print a string */

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{


