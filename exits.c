#include "shell.h"

/**
 * _strncpy - this will copy the string
 * @dest: destination string to be copied to
 * @src: source string
 * @n: number of characters to be copied
 * Return: the added string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - this will  add two strings
 * @dest: first string
 * @src: second string
 * @n: the value of bytes to be utilized
 * Return: the added string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
	{
		dest[i] = '\0';
	}
	return (s);
}

/**
 * _strchr - this will search for character in a string
 * @s: string to be searched
 * @c: character to search for
 * Return: s a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do
	{
		if (*s == c)
			return (s);
	}
	while (*s++ != '\0');
	return (NULL);
}
