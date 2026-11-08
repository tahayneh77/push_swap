/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:47:51 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:49:13 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dup(t_stack *a, int val)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->val == val)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static int	parse_flag(const char *arg, t_bench *bench)
{
	if (!bench)
		return (0);
	if (ft_strcmp(arg, "--bench") == 0)
		bench->enabled = 1;
	else if (ft_strcmp(arg, "--simple") == 0)
		bench->strat = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		bench->strat = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		bench->strat = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		bench->strat = STRAT_ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	push_token(t_stack *a, char *token)
{
	long	val;

	if (!ft_atol(token, &val))
		return (0);
	if (check_dup(a, (int)val))
		return (0);
	if (!stack_push_bottom(a, (int)val))
		return (0);
	return (1);
}

static int	parse_str(t_stack *a, char *str)
{
	char	**tokens;
	int		j;

	tokens = ft_split_spaces(str);
	if (!tokens || !tokens[0])
	{
		ft_free_split(tokens);
		return (0);
	}
	j = 0;
	while (tokens[j])
	{
		if (!push_token(a, tokens[j]))
		{
			ft_free_split(tokens);
			return (0);
		}
		j++;
	}
	ft_free_split(tokens);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a, t_bench *bench)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!parse_flag(argv[i], bench))
				return (0);
			i++;
			continue ;
		}
		if (argv[i][0] == '\0')
			return (0);
		if (!parse_str(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
