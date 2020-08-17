#include "shell.h"
/**
 * main - main function of the Shell
 * @ac: Is the number of input of arguments
 * @av: the arguments type string in the array
 * @env: enviroment variable.
 * Return: 0 on succesfull completion
 */

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;

	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$hell ", 6);
		prompt(env);
	}
	else
	{
		prompt(env);
	}
	exit(0);
	return (0);
}
