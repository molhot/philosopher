#include "../philo.h"

static	bool	argment_check(char *argline)
{
	size_t	argline_position;

	argline_position = 0;
	while (argline[argline_position] != '\0')
	{
		if (!('0' <= argline[argline_position] && \
		argline[argline_position] <= '9'))
			return (false);
		argline_position++;
	}
	return (true);
}

bool	arg_check(int argnum, char **arg)
{
	size_t	arg_position;

	if (argnum != 5 && argnum != 6)
	{
		argnum_error();
		return (false);
	}
	arg_position = 1;
	while (arg[arg_position] != NULL)
	{
		if (argment_check(arg[arg_position]) == false)
		{
			argminus_error();
			return (false);
		}
		arg_position++;
	}
	return (true);
}