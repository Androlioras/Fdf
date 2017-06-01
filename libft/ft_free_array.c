/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:41:12 by pribault          #+#    #+#             */
/*   Updated: 2016/11/23 11:47:04 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void **array, size_t len)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < len)
		if (array[i])
			free(array[i++]);
	free(array);
}
