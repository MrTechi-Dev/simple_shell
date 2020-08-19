#include "shell.h"
/**
 * print_environment - function that prints the system enviroment
 * Return: nothing
 */
void print_environment(void)
{
	int j = 0;
	char **env = environ;

	while (env[j])
	{
		write(STDOUT_FILENO, (const void *) env[j], _strlen(env[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}

/**
 * exit_shell - Function that exits the shell if is prompt by the user
 * @line: getline line from user
 * @cmd: command given by user
 * Return: nothing
 */
void exit_shell(char *line, char **cmd)
{
	free(line);
	free(cmd);
	/*free_arrays(cmd);*/
	exit(EXIT_SUCCESS);
}
/**
 * excutefalse - Function that frees memory allocated
 * @line: buffer of memory allocated
 * @commands: input from command user
 */
void excutefalse(char *line, char **commands)
{
	perror("COMMAND NOT FOUND");
	free(line);
	free_arrays(commands);
	exit(EXIT_FAILURE);
}
