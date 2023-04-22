#include "main.h"

/**
  * is_printable - Evaluates if a char is printable
  * @c: Char to be evaluated
  *
  * Return: 1 if c is printable, 0 otherwise
  */

int is_printable(char c)
{
  return (c >= 32 && c < 127);
}

/**
  * append_hexa_code - Append ascci in hexadecimal code to buffer
  * @buffer: Array of chars.
  * @i: Index at which to start appending.
  * @asci_code: ascii code
  *
  * Return: Always 3.
  */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
  static const char map_to[] = "0123456789ABCDEF";
  if (ascii_code < 0)
    ascii_code *= -1;
    buffer[i++] = '\\';
    buffer[i++] = 'x';
    buffer[i++] = map_to[ascii_code / 16;
    buffer[i] = map_to[ascii_code % 16];
  return (3);
}

/**
  * is_digit - Verifies if a char is a digit
  * @c: Char to be evaluated
  *
  * Return: 1 if c is a digit, otherwise 0
  */

int is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

/**
  * convert_size_number - Casts a number to the specified size
  * @num: casted number
  * @size: the type of number to be casted
  *
  * Return: the value of the casted number
  */
 
 long int convert_size_number(long int num, int size)
 {
   switch (size)
   {
     case S_LONG:
       return (num);
     case S_SHORT:
       return ((short)num);
     default:
       return ((int)num);
   }
 }
 
/**
  * convert_size_unsigned - Casts a number to the specified size
  * @num: casted number
  * @size: type of number to be casted
  *
  * Return: Value casted
  */
 
long int convert_size_unsigned(unsigned long int num, int size)
{
  switch (size)
  {
    case S_LONG:
      return (num);
    case S_SHORT:
      return ((unsigned short)num);
    default:
      return ((unsigned int)num);
  }
}
