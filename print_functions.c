#include "main."

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

