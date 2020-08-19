#include "shell.h"
/**
 * get_env_path - function that gets the PATH route
 * @env: enviroment of thr system
 * @compare: PATH to compare
 * Return: the PATH POSITION captured into environment
*/

char *get_env_path(char **env, char *compare)
{
	int i;
	int j;
	/*char compare[4] = "PATH";*/

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; compare[j] != '\0'; j++)
		{
			if (env[i][j] == compare[j])
				continue;
			else
				break;
		}
		if (compare[j] == '\0')
			break;
	}
	return (env[i]);
}
