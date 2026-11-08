/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:47:11 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:49:54 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i])
		{
			cnt++;
			while (s[i] && !ft_isspace(s[i]))
				i++;
		}
	}
	return (cnt);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	fill_tab(char **tab, const char *s)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && !ft_isspace(s[i]))
			i++;
		tab[k] = word_dup(s, start, i);
		if (!tab[k])
			return (0);
		k++;
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split_spaces(const char *s)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (!tab)
		return (NULL);
	if (!fill_tab(tab, s))
	{
		ft_free_split(tab);
		return (NULL);
	}
	return (tab);
}
