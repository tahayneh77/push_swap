/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:47:56 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:49:26 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static int	parse_digits(const char *str, int *i, int sign, long *out)
{
	long	res;

	res = 0;
	if (str[*i] < '0' || str[*i] > '9')
		return (0);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + (str[*i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
			return (0);
		(*i)++;
	}
	*out = res * sign;
	return (1);
}

int	ft_atol(const char *str, long *out)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!parse_digits(str, &i, sign, out))
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (str[i] == '\0');
}

void	ft_free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
