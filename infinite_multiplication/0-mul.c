#include "holberton.h"
#include <stdlib.h>

/**
 * _strlen - Returns length of string
 * @s: String
 * Return: Length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * is_digit - Checks if string contains only digits
 * @s: String to check
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_error - Prints Error and exits
 */
void print_error(void)
{
	char *error = "Error";
	int i = 0;

	while (error[i])
	{
		_putchar(error[i]);
		i++;
	}
	_putchar('\n');
	exit(98);
}

/**
 * multiply - Multiplies two positive numbers
 * @num1: First number
 * @num2: Second number
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, len, i, j, n1, n2, prod, carry, start;
	int *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = malloc(sizeof(int) * len);
	if (!result)
		print_error();

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			prod = n1 * n2 + result[i + j + 1] + carry;
			carry = prod / 10;
			result[i + j + 1] = prod % 10;
		}
		result[i + j + 1] += carry;
	}

	start = 0;
	while (start < len && result[start] == 0)
		start++;

	if (start == len)
		_putchar('0');
	else
	{
		for (i = start; i < len; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);

	return (0);
}
