#include "shell.h"
/**
 * _strcmp - a function that compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: an integer result of the comparison
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((int) (s1[i] - s2[i]));
		i++;
	}
	return (0);
}
/**
 * _strcmp - a function that compares two strings for a const char*
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: an integer result of the comparison
 */
int _strcmp_env(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((int) (s1[i] - s2[i]));
		i++;
	}
	return (0);
}
/**
 * _strdup - returns a pointer to a new string which is a duplicate
 * of the string str
 * @str: input string of const char*
 * Return: a pointer to a newly allocated space in memory
 */
char *_strdup(const char *str)
{
	unsigned int i;
	char *string;

	if (str == NULL)
		return (NULL);

	string = _grand_malloc(sizeof(char) * (_strlen(str) + 1));
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
			break;
		string[i] = str[i];
	}
	string[i] = '\0';
	return (string);
}
/**
 * _strlen - returns the length of a string of const char*
 * @s: input string
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	unsigned int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * path_to_folder_counter - counts how many folders are in the path
 * @paths: takes in the path
 * Return: the number of folders in a path
 */
unsigned int path_folder_counter(char *paths)
{
	unsigned int i, path_folders;

	i = path_folders = 0;

	while(paths[i] != '\0')
	{
		if(paths[i] == ':')
			path_folders++;
		i++;
	}
	return(++path_folders);
}
