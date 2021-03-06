/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:26:05 by jebrocho          #+#    #+#             */
/*   Updated: 2018/11/13 21:06:59 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	size_t i;

	i = 0;
	if (ap)
	{
		if (*ap)
			free(*ap);
		*ap = NULL;
	}
}
