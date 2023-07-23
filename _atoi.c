#include "shell.h"

/**
 * interactive mode - return success if the shell is in interactive order
 * @info: concise addresses
 *
 * Return: 1 if interactive order, or else 0
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - this will check whether the  character is in delimeter
 * @c: char to check
 * @delim: delimeter string
 * Return: 1 if correct, 0 if wrong
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 * _isalpha - this will check for alphabet characters
 * @c: characters to be inputed
 * Return: 1 if c is an alphabet or 0if not
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
/**
 * _atoi - this will convert all strings to integers
 * @s: strings to convert
 * Return: 0 with  numbers in the string, else convert numbers
 */

int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
utput = result;

return (output);
}
