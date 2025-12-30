/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:08:10 by ncaravac          #+#    #+#             */
/*   Updated: 2025/12/30 15:17:16 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	long				content;
	struct s_list		*next;
}	t_list;

// Functions
int		check_num(char **argv);
int		check_minmax(char **argv);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(long value);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
long	ft_atol(char *argv_char);

// Simple
void	simple(t_list **stack_a, t_list **stack_b);

// Movements
void	rra(t_list **stack_a);
void	ra(t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);

#endif
