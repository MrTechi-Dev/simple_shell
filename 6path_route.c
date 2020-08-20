#include "shell.h"
/**
 * get_route - function that concatenates the path id and of command input from
 * user
 * @commands: comands given by user input
 * @env: enviroment
 * Return: concatenation of Full Path
 */
char **get_route(char **commands, char **env)
{
	char *path = NULL, **dir_path = NULL, *token = NULL;
	int counter = 0, l, i, len_comm = 0, len_dir = 0, k, j;

	path = get_env_path(env, "PATH");
	for (l = 0; path[l] != '\0'; l++)
	{
		if (path[l + 1] == ':' || path[l + 1] == '\0')
			counter++;
	}
	dir_path = malloc(sizeof(char *) * (counter + 1));
	if (dir_path == NULL)
		return (NULL);
	i = 0;
	token = strtok(path, ":");
	while (token != NULL)
	{
		len_dir = _strlen(token);
		len_comm = _strlen(commands[0]);
		dir_path[i] = malloc(sizeof(char) * (len_dir + len_comm + 2));
		if (dir_path[i] == NULL)
		{
			free_arrays(dir_path);
			return (NULL);
		}
		else
		{
			for (k = 0; k < len_dir && token[k] != '\0'; k++)
				dir_path[i][k] = token[k];
			dir_path[i][k] = '/';
			k++;
			for (j = 0; j < len_comm && commands[0][j] != '\0'; k++, j++)
				dir_path[i][k] = commands[0][j];
			dir_path[i][k] = '\0';
		}
		token = strtok(NULL, ":");
		i++;
	}
	dir_path[i] = NULL;
	return (dir_path);
}
