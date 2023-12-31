#include "shell.h"

/**
 * _memset - this will fill the memory with an unchanged byte
 * @s: pointer pointing to the memory area
 * @b: the byte to fill *s with
 * @n: the number of bytes to be filled
 *
 * Description: this will fill the memory with an unchanged byte
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
	s[i] = b;
	}

	return (s);
}

/**
 * ffree - to free the array of strings
 * @pp: the array of strings
 *
 * Description: to free the array of strings
 * Return: void
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
	return;

	while (*pp)
	free(*pp++);
	free(a);
}

/**
 * _realloc - redistribute a block of memory
 * @ptr: pointer to the previously allocated block
 * @old_size: byte size of the previous block
 * @new_size: byte size of the new block
 *
 * Description: redistribute a block of memory
 * Return: pointer to the new block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
	return (malloc(new_size));

	if (!new_size)
	{
	free(ptr);
	return (NULL);
	}

	if (new_size == old_size)
	return (ptr);

	p = malloc(new_size);
	if (!p)
	return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	p[old_size] = ((char *)ptr)[old_size];

	free(ptr);

	return (p);
}
