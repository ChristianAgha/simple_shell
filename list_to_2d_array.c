#include "shell.h"

char ** conv_list_to_array(env_var_list_t * env_head, int n)
{
	char **array;
	env_var_list_t *tmp;
	int len, i, j;
	char * val;

	len = i = 0;
	tmp = env_head;
	array = _grand_malloc(sizeof(char *) * (n + 1));

	while (tmp != NULL)
	{
		len = _strlen(tmp->key) + _strlen(tmp->value);
		array[i] = _grand_malloc(sizeof(char) * (len + 1));
		if (array[i] == NULL)
		{
			free(array);
			return(NULL);
		}
		_memset(array[i], '\0', len);
		_memcopy(array[i], tmp->key, _strlen(tmp->key));
		array[i][_strlen(tmp->key)] = '=';
		val = tmp->value;
		for (j = 0; j < _strlen(tmp->value); j++)
		{
			array[i][_strlen(tmp->key) + 1 + j] = val[j];
		}
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
	return(array);
}
