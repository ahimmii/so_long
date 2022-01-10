/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:06:25 by ahimmi            #+#    #+#             */
/*   Updated: 2021/11/07 15:06:28 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char		*dest;
	const char	*src;
	char		*dest1;
	const char	*src1;

	dest = destination;
	src = source;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		while (size--)
			*dest++ = *src++;
	}
	else
	{
		dest1 = destination + (size - 1);
		src1 = source + (size - 1);
		while (size--)
			(*dest1--) = (*src1--);
	}
	return (destination);
}
