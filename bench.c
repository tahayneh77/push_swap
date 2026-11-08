/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:49:00 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:49:02 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double d)
{
	long	whole;
	long	dec;

	whole = (long)(d * 100);
	dec = (long)(d * 10000 + 0.5) % 100;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (dec < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(dec, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_bench *bench)
{
	ft_putstr_fd("[bench] strategy:   ", 2);
	if (bench->strat == STRAT_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (bench->strat == STRAT_MEDIUM)
		ft_putstr_fd("Medium / O(n\\sqrt{n})\n", 2);
	else if (bench->strat == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (bench->chosen == STRAT_SIMPLE)
			ft_putstr_fd("O(n^2)\n", 2);
		else if (bench->chosen == STRAT_MEDIUM)
			ft_putstr_fd("O(n\\sqrt{n})\n", 2);
		else
			ft_putstr_fd("O(n log n)\n", 2);
	}
}

static void	print_counts_a(t_bench *bench)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_counts_b(t_bench *bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	bench_print(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	print_disorder(bench->disorder);
	print_strategy(bench);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_counts_a(bench);
	print_counts_b(bench);
}
