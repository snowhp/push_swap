/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:04:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/25 22:34:39 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
    long     content;
    struct s_stack	*next;
}	t_stack;

int	ft_charsize(char **str);
void    ft_listinput(char **argv, int argc, t_stack **head_a, int i);
void	ft_printlist(t_stack **head_a);
void	ft_addtail(t_stack **head, long content);
void	ft_exit(t_stack **head_a);

#endif
