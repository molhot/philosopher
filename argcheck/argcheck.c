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

static  bool	zeroch(char *arg)
{
	if (arg[0] == '0' && arg[1] == '\0')
		return (true);
	return (false);
}

bool	arg_check(int argnum, char **arg)
{
	size_t	arg_position;

    if (arg == NULL)
        return (argis_null());
	if (argnum != 5 && argnum != 6)
		return (argnum_error());
	arg_position = 1;
	while (arg[arg_position] != NULL)
	{
        if (arg_position == 1 && zeroch(arg[arg_position]) == true)
            return (argzero_error());
		if (argment_check(arg[arg_position]) == false)
			return (argval_error());
		arg_position++;
	}
	return (true);
}