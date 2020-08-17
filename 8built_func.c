#include "shell.h"
/**
 * signalhandle - function that handle user signals
 * @n: unused attribute (void)
 */

void signalhandle(int n __attribute__((unused)))
{
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$hell ", 6);
}
/**
 * ctrl_c - function that handle ctrl c signal from user
 * @line: command by user
 */
void ctrl_c(char *line)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(line);
	exit(EXIT_SUCCESS);
}
/**
 * fork_error -  function that exit once fork is not done correctly
 * @line: argument
 * @commands: command given by user
 */
void fork_error(char *line, char **commands)
{
	perror("FatalError: ");
	free(line);
	free_arrays(commands);
	exit(EXIT_FAILURE);
}
/**
 * free_arrays - function that free memory already used
 * @array: memory to free
 */
void free_arrays(char **array)
{
	int j = 0;
	while (array[j])
	{
		free(array[j]);
		j++;
	}
	if (array[j] == NULL)
		free(array[j]);
	free(array);
}
/**
 * print_env - function that prints the system enviroment
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
	free_arrays(cmd);
	exit(EXIT_SUCCESS);
}