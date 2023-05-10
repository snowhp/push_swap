/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:04:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/10 17:08:28 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
    long     content;
    struct s_stack	*next;
}	t_stack;

int	ft_charsize(char **str);
void    ft_listinput(char **argv, int argc, t_stack **head_a, int i);
void	printlist(t_stack **head_a, t_stack **head_b);
void	ft_addtail(t_stack **head, long content);
void	ft_exit(t_stack **head_a, t_stack **head_b, char **error);
void check_arg(char **argv);
void ft_checkdigit(char **argv);
void ft_checkmax(char **argv);
void ft_insertlist(t_stack **head_a, char **argv);
void	ft_push(t_stack **head_o, t_stack **head_d, char c);
void	ft_swap(t_stack **head_1, char c);
void	ft_rotateup(t_stack **head_1, char c);
void	ft_rotatedown(t_stack **head_1, char c);

#endif
