/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:44:10 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/06 18:20:37 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	size_t	i;
	size_t	j;

	if (!str && n == 0)
		return (NULL);
	if (!*sub)
		return ((char *)str);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] != '\0' && sub[j] != '\0' && (i + j) < n)
		{
			if (str[i + j] != sub[j])
				break ;
			j++;
		}
		if (!sub[j])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
