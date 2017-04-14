#include "shell.h"

int cmd_executor(char **path_folders, char **cmd)
{
	char *folder;
	int i, j, k, l;
	int exec_status;
	pid_t pid;
	int status;
	(void) path_folders;
	for(i = 0; cmd[0][i] != '\0'; i++)
	{
		if(cmd[0][i] == '/')
		{
			pid = fork();
			if (pid == 0)
			{
				exec_status = execve(cmd[0], cmd, NULL);
				if(exec_status == -1)
					exit(EXIT_FAILURE);
				exit(EXIT_SUCCESS);
			}
			else
				wait(&status);
			break;
		}
	}

	for(i = 0; path_folders[i] != '\0'; i++)
	{
		/*folder = _grand_malloc(_strlen(path_folders[i]) + _strlen(cmd) + 2);*/
		folder = _grand_malloc(1024);
		for(j = 0; path_folders[i][j] != '\0'; j++)
		{
			folder[j] = path_folders[i][j];
		}
		folder[j] = '/';

		for(k = j + 1, l = 0; cmd[0][l] != '\0'; k++, l++)
		{
			folder[k] = cmd[0][l];
		}
		folder[k] = '\0';
/*		printf("folder[0]: %s\n", folder);*/

		if (access(folder, X_OK) == 0)
			execve(folder, cmd, NULL);
	}

	return(0);
}