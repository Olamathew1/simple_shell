#include "shell.h"

/**
 * list_len - ascertain the length of the linked list
 * @h: pointer to the first node
 *
 * Description: ascertain the length of the linked list
 * Return: size of the list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;
	
	while (h)
	{
		h = h->next;
		i++;
	}

	return i;
}

/**
 * list_to_strings - this will return the array of strings of list->str
 * @head: pointer to the first node
 *
 * Description: this will return the array of strings of list->str
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head);
	size_t j;
	char **strs;
	char *str;

	if (!head || !i)
		return NULL;

	strs = (char **)malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return NULL;

	for (i = 0; node; node = node->next, i++)
	{
		str = (char *)malloc(_strlen(node->str) + 1);
		if (!str)
			str = (char *)malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return NULL;
		}
		str = _strcpy(str, node->str);
		strs[i] = str;
	}

	strs[i] = NULL;
	return strs;
}

/**
 * print_list - this will print over all elements of list_t linked list
 * @h: pointer to the beginning of the node
 *
 * Description: this will print over all elements of list_t linked list
 * Return: size of the list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}

	return i;
}

/**
 * node_starts_with - this will return the node that the string starts with prefix
 * @node: pointer to the list head
 * @prefix: string to match
 * @c: the next character after prefix must match
 *
 * Description: this will return the node that the string starts with prefix
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return node;
		node = node->next;
	}

	return NULL;
}

/**
 * get_node_index - this will get the index of a given node
 * @head: the pointer to list head
 * @node: the pointer to the node
 *
 * Description: this will get the index of a given node
 * Return: index of the node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;
	
	while (head)
	{
		if (head == node)
			return i;
		head = head->next;
		i++;
	}

	return -1;
}
