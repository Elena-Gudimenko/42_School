/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:48:56 by elvictor          #+#    #+#             */
/*   Updated: 2024/11/07 15:30:04 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char ***str_list, int allocated);

static int	count_words(const char *s, char c);

static void	fill_arr(int size, const char *s, char c, char ***str_list);

static int	count_words(const char *s, char c)
{
	int	count;
	int	index;
	int	len_s;

	len_s = ft_strlen(s);
	if (len_s == 0)
		return (0);
	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != (unsigned char)c)
		{
			while (s[index] != (unsigned char)c && s[index] != '\0')
				index++;
			count++;
		}
		if (s[index] != '\0')
			index++;
	}
	return (count);
}

static void	fill_arr(int size, const char *s, char c, char ***str_list)
{
	int		counter;
	int		index;
	int		pass;
	char	*test;

	index = 0;
	counter = 0;
	while (s[index] != '\0' && counter < size)
	{
		pass = 0;
		while (s[index] == (unsigned char)c)
			index++;
		while (s[index + pass] && s[index + pass] != c)
			pass++;
		test = ft_substr(&s[index], 0, pass);
		if (!test)
		{
			free_memory(str_list, counter);
			return ;
		}
		(*str_list)[counter] = test;
		counter++;
		index += pass;
	}
	(*str_list)[size] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**str_list;

	if (!s)
		return (ft_calloc(1, sizeof(char *)));
	size = count_words(s, c);
	if (size == 0)
		return (ft_calloc(1, sizeof(char *)));
	str_list = (char **) ft_calloc((size + 1), sizeof(char *));
	if (str_list == 0)
		return (0);
	fill_arr(size, s, c, &str_list);
	return (str_list);
}

static void	free_memory(char ***str_list, int allocated)
{
	int	index;

	if (!str_list || !*str_list)
		return ;
	index = 0;
	while (index < allocated)
	{
		free((*str_list)[index]);
		index++;
	}
	free(*str_list);
	*str_list = NULL;
}
