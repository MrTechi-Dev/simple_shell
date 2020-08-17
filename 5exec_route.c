#include "shell.h"
/**
 * exec_routes - functions that receive commands into the  directores 
 *  on a string type and try one by one to execv function
 * @commands: Array of commands
 * @line: Pointer to line
 * @env: environment
 * Return: false on failure
 */
bool exec_routes(char **commands, char *line, char **env)
{
	char **command = NULL;
	int i = 0;
	/*==========THE FUNCTION OBTAIN THE ROUTES=============*/
	/* =============/bin/ls - /bin/pwd===============*/
	command = get_route(commands, env);
	/*========T R Y  T H E  C O M M A N D S  R O U T E S==========*/
	while (command[i] != NULL)
	{
		if (access(command[i], X_OK) == 0)
			execve(command[i], commands, env);
		i++;
	}
	/* ============Not command found in the terminal==========*/
	if (command[i] ==  NULL)
	{
		free_arrays(command);
		return (false);
	}
    /** ==================Free memory used by user==============**/
	free(line);
	free_arrays(command);
	free_arrays(commands);
	exit(EXIT_SUCCESS);
}
