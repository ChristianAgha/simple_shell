#include "shell.h"

int input_word_counter(char * buffer)
{
	int i, counter;

	i = counter = 0;
	if (buffer == NULL)
		return (0);
	while(buffer[i] == ' ' && buffer[i] != '\0')
		i++;
	if(buffer[i] == '\0')
		return(0);
	while (buffer[i] != '\0')
	{
		if((buffer[i] == ' ' && buffer[i + 1] != ' ') || (buffer[i + 1] == '\0'))
			counter++;
		i++;
	}
	return(++counter);
}
