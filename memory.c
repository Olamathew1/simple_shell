#include "shell.h"

/**
 * bfree - this will free the pointers and address would be NULL
 * @ptr: address of the pointer to be freed
 *
 * Description: this will free the pointers and address would be NULL
 * Return: 1 if freed, or else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}
