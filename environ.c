#include "shell.h"

/**
 * _myenv - this will  print the immediate environment
 * @info: Module that contain the intended argument. asigned to keep
 * unchanged  function prototype.
 * Return: 0 Always
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - estimates the value of an environment variable
 * @info: Module that  contain the intended arguments. Asigned to maintain
 * unchanged function prototype.
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}
/**
 * _mysetenv - Generates  a new environment variable,
 * or edit the existing one
 * @info: Module that  contain the intended  arguments. Assigned to keep
 * constant function prototype.
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _myunsetenv - delete the  environment variable
 * @info: Module that  contain the intended arguments. assigned to keep
 * unchanged function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);

return (0);
}
/**
 * populate_env_list - populates env assigned list
 * @info: Module that contain intended arguments. Assigned to keep
 * unchanged function prototype.
 * Return: 0 Always
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
