#include "shell.h"

/**
 * _eputs - this will print the inputed string
 * @str: string to be printed
 *
 * Return: Null
 */
void _eputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
 * _eputchar - this will write the character c to stderr
 * @c: The character to print
 *
 * Return: 1 on success
 * On error, -1
 */
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putfd - this will  write character c to given fd
 * @c: The character to print
 * @fd: The filed escriptor to write to
 *
 * Return:1 on success
 * On error, -1
 */
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putsfd - this will print inputed string
 * @str: string to be printed
 * @fd: The filed escriptor to write to
 *
 * Return: chars puts number
 */
int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
