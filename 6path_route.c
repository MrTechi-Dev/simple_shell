#include "shell.h"
/**
 * get_route - function that concatenates the path id and the command input from user
 * @commands: comands given by user input
 * @env: enviroment
 * Return: concatenation of Full Path
 */
char **get_route(char **commands, char **env)
{
	char *path = NULL;
	char **path_route = NULL; 
	char *token = NULL;
	int counter = 0;
	int i;
	int j;
	int lenghtcommand = 0;
	int lenghtpath = 0; 
	int k;
	int l;
	
	path = get_env_path(env);
	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[i + 1] == ':' || path[i + 1] == '\0')
			counter++;
	}
	path_route = malloc(sizeof(char *) * (counter + 1));
	if (path_route == NULL)
		return (NULL);
	j = 0;
	/*=========SEPARATE THE PATH WITH THE  ":" DELIMETETOR========*/
	token = strtok(path, ":");
	while (token != NULL)
	{
		lenghtpath = _strlen(token);
		lenghtcommand = _strlen(commands[0]);
		path_route[j] = malloc(sizeof(char) * (lenghtpath + lenghtcommand + 2));
		if (path_route[j] == NULL)
		{
			free_arrays(path_route);
			return (NULL);
		}
		else
		{
			for (k = 0; k < lenghtpath && token[k] != '\0'; k++)
				path_route[j][k] = token[k];
			path_route[j][k] = '/';
			k++;
			for (l = 0; l < lenghtcommand && commands[0][l] != '\0'; k++, l++)
				path_route[j][k] = commands[0][l];
			path_route[j][k] = '\0';
		}
		token = strtok(NULL, ":");
		j++;
	}
	path_route[j] = NULL;
	return (path_route);
}