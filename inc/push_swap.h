/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:04:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/28 14:54:48 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	long			content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		index;
	t_stack	*node;
	int		total;
}	t_moves;

/*	Moves		*/

void		ft_push(t_stack **head_o, t_stack **head_d, char c);
void		ft_swap(t_stack **head_1, char c);
/* ra/rb */
void		ft_rotateup(t_stack **head_1, char c);
/* rra/rrb */
void		ft_rotatedown(t_stack **head_1, char c);
void		ft_doublerevrotate(t_stack **head_a, t_stack **head_b, int checker);
void		ft_doublerotate(t_stack **head_a, t_stack **head_b, int checker);
/* ss */
void		ft_doubleswap(t_stack **head_a, t_stack **head_b, int checker);

/*	Moves aux	*/

void		ft_autopush(t_stack *n, t_stack **head_o, t_stack **head_d, char c);
t_stack		*ft_findmax(t_stack **head);
t_stack		*ft_findmin(t_stack **head);
int			ft_listpos(t_stack *node, t_stack **head);
int			ft_listsize(t_stack **head);
void		ft_insertinsortlist(t_stack **head_a, t_stack **head_b);
void		ft_crotates(t_stack *cu, t_stack **head_a, t_moves *moves, char c);
t_stack		*ft_matchb(t_stack **head_b, int index);
void		ft_bestmove(t_stack **head_a, t_stack **head_b);
void		ft_initstruct(t_moves *moves);
void		ft_otimizerotates(t_moves *moves);
void		ft_execrotates(t_stack **head_a, t_stack **head_b, t_moves moves);
void		ft_execrotates2(t_stack **head_a, t_stack **head_b, t_moves moves);

/*	Sorting	*/

void		ft_sortlist(t_stack **head_a, t_stack **head_b);
void		ft_sort2(t_stack **head_a);
void		ft_sort3(t_stack **head);
void		ft_sort5(t_stack **head_a, t_stack **head_b, int size);
void		ft_sort500(t_stack **head_a, t_stack **head_b);

/*	Checking && Input	*/

void		ft_checkdigit(char **argv, int x);
void		ft_checkmax(char **argv, int x);
void		ft_checkdups(t_stack **head_a, char **argv, int x);
int			ft_listsorted(t_stack **head);
void		ft_listindex(t_stack **head, int index);
int			ft_islistindex(t_stack **head);
void		ft_insertlist(t_stack **head_a, char **argv, int x);
void		ft_listinput(char **argv, int argc, t_stack **head_a, int i);
void		printlist(t_stack **head_a, t_stack **head_b);
void		ft_addtail(t_stack **head, long content);

void		ft_exit(int c, t_stack **head_a, t_stack **head_b);
void		ft_freearray(char **str);

/*	Checker		*/
/* Create a list without any verification */
void		ft_checkerverification(t_stack **head_a, t_stack **head_b);
/* Compare and execute moves on the stack*/
void		ft_execmove(t_stack **head_a, t_stack **head_b);
/* Execute specific commands return 0 on error*/
int			ft_moves(char *move, int size, t_stack **head_a, t_stack **head_b);

#endif
