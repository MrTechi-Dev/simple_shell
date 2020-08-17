#include "shell.h"
/**
 * execute_cmd -  Execute a command prompt by the user in the shell
 * @commands: array of commands
 * @line: line pointer
 * @env: environment varibale
 * Return: true on succes or  failure if it bool fails
 */
bool execute_cmd(char **commands, char *line, char **env)
{
	bool command = false;

	if (commands == NULL)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	/* =======E X I T   F U N C T I O N   B U I L T  I N ======*/
	else if ((_strcmp("exit", commands[0])) == 0)
		exit_shell(line, commands);
	/*===== E N V   F U N C T I O N   B U I L T  I N ========*/
	else if ((_strcmp("env", commands[0])) == 0)
	{
		print_environment();
		command = true;
	}
	/* ======== TRY THE ROUTE WITH THE FORMAT $/bin/ls ============ */
	else if (access(commands[0], X_OK) == 0)
		execve(commands[0], commands, NULL);
	else
	{
		/*==== TRY THE ROUTE WITH THE FORMAT: $ls===== */
		command = exec_routes(commands, line, env);
		if (command == false)
			return (false);
	}
	return (command);
}

