#include "main.h"
/**
*print_environ - the function that prints the environ to stdout
*@environ: the variable environ
*Return: Nothing
*/
void print_environ(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
*ksh_env - the function that has env builtin command
*@argv: arguments to the command
*@var: var_t struct
*Return: Nothing
*/
int ksh_env(char **argv, var_t *var)
{
	if (!argv[1])
	{
		print_environ(environ);
	}
	else
	{
		char **commands = parse_command(argv[1]);

		execute_single_command(commands, var);
		free(commands);
	}

	return (0);
}
