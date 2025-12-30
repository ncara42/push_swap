/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <ncaravac@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:08:10 by ncaravac          #+#    #+#             */
/*   Updated: 2025/12/30 01:35:49 by ncaravac         ###   ########.fr       */
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
	void				*content;
	struct s_list		*next;
}	t_list;

// Functions
int		check_num(char **argv);
int		check_minmax(char **argv);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
long	*ft_atol(char *argv_char);

// Simple
void	simple(t_list **stack_a, int n);

// Movements
void	rra(t_list **stack_a);
void	ra(t_list **stack_a);
#endif
