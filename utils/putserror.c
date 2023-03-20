/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putserror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:37:35 by user              #+#    #+#             */
/*   Updated: 2023/03/21 01:51:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	argis_null(void)
{
	printf("args is NULL");
	return (false);
}

bool	argnum_error(void)
{
	printf("argment num is not true mount");
	return (false);
}

bool	argval_error(void)
{
	printf("argment value is not correct");
	return (false);
}

bool	argzero_error(void)
{
	printf("philo num is zero");
	return (false);
}
