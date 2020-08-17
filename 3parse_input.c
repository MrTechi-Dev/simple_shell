#include "shell.h"
/**
 * parse_input - function to divide the arguments
 * @buf: pointer to a string
 * Return: a variable contain the command
 */
char **parse_input(char *buf)
{
	char **all_tokens = NULL; 
	char *token = NULL;
	int j = 0;
	int counter;
	int x;

if(!buf)
	return(all_tokens);
buf[_strlen(buf) - 1] = '\0';
/* Checking number of delimiters to know how many spaces will be open in the tokenazation  */
x = 0;
for (; buf[x] != '\0'; x++)
{
	if (buf[x] != ' ')
	{
	if (buf[x + 1] == ' ' || buf[x + 1] == '\0')
		counter++;
	}
}
if (counter == 0)
{
	return (all_tokens);
}
all_tokens = malloc(sizeof(char *) * (counter + 1));
	if (!all_tokens)
	{
		return(all_tokens);
	}
token = strtok(buf, "WHITESPACE ");
	for (j = 0; token != NULL; j++)
	{
		all_tokens[j] = token;
		token = strtok(NULL, "WHITESPACE ");
	}
all_tokens[j] = NULL;
	return (all_tokens);
}