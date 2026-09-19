/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:20 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/19 17:53:09 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int			ft_is_error(t_list **list);
int			is_valid_number(char *str);
int			is_valid_int(long long nbr);
int			ft_verify_args(char *arg);
static void	*free_matrix(char **matrix);
int			ft_has_duplicate(t_list *list, int num);

#endif