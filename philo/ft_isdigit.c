/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:02:23 by lbuccher          #+#    #+#             */
/*   Updated: 2022/03/09 18:02:42 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' && str[i + 1])
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
