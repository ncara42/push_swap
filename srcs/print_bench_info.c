/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:54:19 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/11 19:37:48 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_disorder(t_stats *s)
{
	int	whole;
	int	decimal;

	whole = (int)s->di;
	decimal = (int)(s->di * 100) % 100;
	if (decimal < 0)
		decimal *= -1;
	write(2, "[bench] disorder:  ", 19);
	ft_putnbr_fd(whole, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write(2, "%\n", 2);
}

void	print_bench_strategy(t_stats *s, t_optype opt)
{
	if (s->algo == SIMPLE)
		write(2, "[bench] strategy:  Simple / O(n^2)\n", 35);
	else if (s->algo == MEDIUM)
		write(2, "[bench] strategy:  Medium / O(n√n)\n", 37);
	else if (s->algo == COMPLEX)
		write(2, "[bench] strategy:  Complex / O(n log n)\n", 40);
	else if (s->algo == ADAPTIVE)
	{
		write(2, "[bench] strategy:  Adaptive / ", 30);
		if (opt == SIMPLE)
			write(2, "O(n^2)\n", 8);
		else if (opt == MEDIUM)
			write(2, "O(n√n)\n", 9);
		else if (opt == COMPLEX)
			write(2, "O(n log n)\n", 11);
	}
	write(2, "[bench] total_ops:  ", 20);
	ft_putnbr_fd(s->total_count, 2);
	write(2, "\n", 1);
}

void	print_each_amounts(t_stats *s)
{
	write(2, "[bench] sa:  ", 13);
	ft_putnbr_fd(s->sa_count, 2);
	write(2, "  sb:  ", 7);
	ft_putnbr_fd(s->sb_count, 2);
	write(2, "  ss:  ", 7);
	ft_putnbr_fd(s->ss_count, 2);
	write(2, "  pa:  ", 7);
	ft_putnbr_fd(s->pa_count, 2);
	write(2, "  pb:  ", 7);
	ft_putnbr_fd(s->pb_count, 2);
	write(2, "\n[bench] ra:  ", 14);
	ft_putnbr_fd(s->ra_count, 2);
	write(2, "  rb:  ", 7);
	ft_putnbr_fd(s->rb_count, 2);
	write(2, "  rr:  ", 7);
	ft_putnbr_fd(s->rr_count, 2);
	write(2, "  rra:  ", 8);
	ft_putnbr_fd(s->rra_count, 2);
	write(2, "  rrb:  ", 8);
	ft_putnbr_fd(s->rrb_count, 2);
	write(2, "  rrr:  ", 8);
	ft_putnbr_fd(s->rrr_count, 2);
	write(2, "\n", 1);
}

void	print_bench_info(t_stats **stats, t_optype opt)
{
	t_stats	*s;

	if (!stats || !*stats)
		return ;
	s = *stats;
	print_disorder(s);
	print_bench_strategy(s, opt);
	print_each_amounts(s);
}
