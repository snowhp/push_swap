/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:04:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/24 14:49:46 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	long			content;
	int			index;
	struct s_stack	*next;
}	t_stack;

/*	Moves		*/
void		ft_push(t_stack **head_o, t_stack **head_d, char c);
void		ft_swap(t_stack **head_1, char c);
void		ft_rotateup(t_stack **head_1, char c);
void		ft_rotatedown(t_stack **head_1, char c);

/*	Moves aux	*/
void		ft_autopush(t_stack *n, t_stack **head_o, t_stack **head_d, char c);
t_stack		*ft_findmax(t_stack **head);
t_stack		*ft_findmin(t_stack **head);
int			ft_listpos(t_stack *node, t_stack **head);
int			ft_listsize(t_stack **head);
void		ft_insertinsortlist(t_stack **head_a, t_stack **head_b);

/*	Sorting	*/
void		ft_sortlist(t_stack **head_a, t_stack **head_b);
void		ft_sort2(t_stack **head_a);
void		ft_sort3(t_stack **head);
void		ft_sort5(t_stack **head_a, t_stack **head_b, int size);
void		ft_sort500(t_stack **head_a, t_stack **head_b);

/*	Checking && Input	*/
void		check_arg(char **argv);
void		ft_checkdigit(char **argv);
void		ft_checkmax(char **argv);
void		ft_checkdups(t_stack **head_a);
int			ft_listsorted(t_stack **head);
void		ft_listindex(t_stack **head, int index);
int		ft_islistindex(t_stack **head);
void		ft_insertlist(t_stack **head_a, char **argv);
void		ft_listinput(char **argv, int argc, t_stack **head_a, int i);
void		printlist(t_stack **head_a, t_stack **head_b);
void		ft_addtail(t_stack **head, long content);

void		ft_exit(char *erromsg, int c, t_stack **head_a, t_stack **head_b);

#endif
