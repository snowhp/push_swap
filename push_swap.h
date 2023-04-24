/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:04:26 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/22 20:05:23 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
    long     content;
    struct s_stack	*next;
}				t_stack;

void    ft_listinput(char **argv, int argc, t_stack head_a);
int     ft_charsize(char **str);
void    ft_printlist(t_stack head_a);
void	ft_lstnewd(t_stack **head, long content);

#endif