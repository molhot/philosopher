/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putserror2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:13:41 by user              #+#    #+#             */
/*   Updated: 2023/03/21 02:15:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	mutex_initmiss(void)
{
	printf("mutex init missed\n");
	return (false);
}
