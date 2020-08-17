#include "shell.h"
/**
* _strlen - function that calculates lenght of a string
* @str: string
* Return: the size  of the string
*/
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strcmp- function that compares two strings
 * @s1: primera string
 * @s2: segunda string
 *Return: return the comparation
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (s1[i] - s2[i]);
}
/**
 * _strncat - function that concatenate an string
 * @dest: pointer char parameter destination dest
 * @src: source char pointer parameter source
 * @n: int parameter that determinate the end of bytes to concatenate
 * Return: Always 0 (Success)
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	i = _strlen(dest);
	while (j < n  && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	return (dest);
}
/**
 **_strcpy-function that copy an array
 *@dest: variable that copy the array
 *@src: array to copy from
 *Return: the array copied  to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strncpy - copying an string
 * @dest: pointer char parameter destination
 * @src: source char pointer parameter
 * @n: int parameter that determinate the end of bytes to concatenate
 *
 * Return: Always 0 (Success)
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n ; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
