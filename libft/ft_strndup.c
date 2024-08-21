/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:06:36 by dodendaa          #+#    #+#             */
/*   Updated: 2020/05/21 22:36:35 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*new;

	i = ft_strlen(str);
	new = NULL;
	if (i == 0)
		return (NULL);
	else if (!(new = ft_strnew(n)))
		return (NULL);
	i = -1;
	while (str[++i] && i < n)
		new[i] = str[i];
	return (new);
}
