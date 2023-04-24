#include "main.h"

/* Print Pointer */

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}


	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/* print non-printable */

/**
 * print_non_printable - Prints the ascii codes in hexa of non printable chars
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specificier
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *star = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (star == NULL)
		return (write(1, "(null)", 6));

	while (star[i] != '\0')
	{
		if (is_printable(star[i]))
			buffer[i + offset] = star[i];
		else
			offset += append_hexa_code(star[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));

}

/* Print reverse */

/**
 * print_reverse - Prints reverse
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: number of chars printed
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *star;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	star = va_arg(types, char *);

	if (star == NULL)
	{
		UNUSED(precision);

		star = "(null)";
	}

	for (i = 0; star[i]; i++)
		for (i = i - 1; i >= 0; i--)
		{
			char z = star[i];

			write(1, &z, 1);
			count++;
		}
	return (count);

}

/* Print a string in rot13 */

/**
 * print_rot13string - Prints a string in rot13
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *star;
	unsigned int i, j;
	int count = 0;
	char in[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	star = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (star == NULL)
		star = "(AHYY)";
	for (i = 0; star[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == star[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = star[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
