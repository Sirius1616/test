#include "shell.h"

/**
 * execute_command - a function that executes command
 * @args: the array of commands
 * @argv0: the count of commands
 * Return: nothing
 */

void execute_command(char **args, char *argv0)
{

	if (access(args[0], X_OK) == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror(argv0);
	}
	else
	{

		char *path = _getenv("PATH");
		char *token = strtok(path, ":");
		char *progpath = malloc(strlen(token) + strlen(args[0]) + 2);
		int found = 0;

		while (token != NULL)
		{
			_strcpy(progpath, token);
			_strcat(progpath, "/");
			_strcat(progpath, args[0]);
			_strcat(progpath, "\0");
			if (access(progpath, X_OK) == 0)
			{
				found = 1;
				break;
			}
			token = strtok(NULL, ":");
		}
		if (found)
		{
			if (execve(progpath, args, environ) == -1)
			perror(argv0);
		}
		else
		{
			perror(argv0);
			exit(EXIT_FAILURE);
		}

		free(progpath);
	}
}

/**
 * parse_input - a function that takes in input and tokenize them
 * @input: the strings entered in the command line
 * Return: args
 */

char **parse_input(char *input)
{
	char *token;
	char **args = malloc(sizeof(char *) * (MAX_ARGS + 1));
	int i = 0;

	token = strtok(input, " \n");
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " \n");
		i++;
		if (i == MAX_ARGS)
		{
			break;
		}
	}
	args[i] = NULL;
	return (args);
}

/**
 * run_command - a function that executes commands depending on the pid
 * @args: the array of arguments passed into the command line
 * @argv0: the count of the command
 * Return: nothing
 */

void run_command(char **args, char *argv0)
{
	int status;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
	}
	else if (pid == 0)
	{
		execute_command(args, argv0);
	}
	else
	{
		if (wait(&status) == -1)
			perror("wait failed");
	}
}

/**
 * get_input - a function that propts to input a command
 * Return: lineptr
 */

char *get_input(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	char *usrprompt = "$ ";
	ssize_t nchars_read;

	write(STDOUT_FILENO, usrprompt, _strlen(usrprompt));
	nchars_read = getline(&lineptr, &n, stdin);
	if (nchars_read == -1)
	{
		write(STDOUT_FILENO, "Exiting shell....\n", 18);
		return (NULL);
	}
	return (lineptr);
}


/**
 * main - the main function
 * @argc: the argument count
 * @argv: the arguments recieved from the command line
 * Return: 0 always
 */
int main(int argc, char **argv)
{
	char *lineptr = NULL;
	char **env;
	char **args;

	(void) argc;

	while (1)
	{
		lineptr = get_input();
		if (lineptr == NULL)
			return (-1);

		args = parse_input(lineptr);

		if (_strcmp(args[0], "exit") == 0)
		{
			free(lineptr);
			return (0);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			env = environ;
			while (*env)
			{
				write(STDOUT_FILENO, *env, _strlen(*env));
				write(STDOUT_FILENO, "\n", 1);
				env++;
			}
		}
		else
		{
			run_command(args, argv[0]);
		}
	}
	free(lineptr);
	return (0);
}
