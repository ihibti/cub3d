/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:33:57 by ihibti            #+#    #+#             */
/*   Updated: 2023/11/20 15:41:37 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// // int	words_in_str(char const *s, char c)
// // {
// // 	int	i;
// // 	int	flag;
// // 	int	ret;

// // 	flag = 1;
// // 	i = 0;
// // 	ret = 0;
// // 	while (s[i])
// // 	{
// // 		if (s[i] == c)
// // 			flag = 1;
// // 		else if (s[i] != c && flag == 1)
// // 		{
// // 			ret++;
// // 			flag = 0;
// // 		}
// // 		i++;
// // 	}
// // 	return (ret);
// // }

// // char	**malloc_dict(int j, char **ret)
// // {
// // 	ret = malloc((j + 1) * sizeof(char *));
// // 	if (!ret)
// // 		return (NULL);
// // 	return (ret);
// // }

// // char	*malloc_word(int j, char *ret)
// // {
// // 	ret = malloc((j + 1) * sizeof(char));
// // 	if (!ret)
// // 		return (NULL);
// // 	return (ret);
// // }

// // char	**ft_split(char const *str, char c)
// // {
// // 	char	**ret;
// // 	int		i;
// // 	int		index;
// // 	int		j;

// // 	index = 0;
// // 	j = 0;
// // 	i = 0;
// // 	ret = NULL;
// // 	if (!(malloc_dict(words_in_str(str, c), ret)))
// // 		return (NULL);
// // 	while (str[i])
// // 	{
// // 		while (str[i] == c)
// // 			i++;
// // 		while (str[i + j] && str[i + j] != c)
// // 			j++;
// // 		if (!(malloc_word(j, ret[index])))
// // 			return (NULL);
// // 		j = 0;
// // 		while (str[i] != c && str[i])
// // 			ret[index][j++] = str[i++];
// // 		ret[index][j] = '\0';
// // 		i++;
// // 		j = 0;
// // 		index++;
// // 	}
// // 	ret[index] = NULL;
// // 	return (ret);
// // }

// int		ft_count(char const *str, char c, int *j, int *k);
// int		ft_count_char(char const *str, char c, int i);
// void	remplissage(char const *str, char *ret, int nbr_char, int position);

// char	**clean(char **tableau, int i)
// {
// 	i--;
// 	while (i >= 0)
// 	{
// 		free(tableau[i]);
// 		i--;
// 	}
// 	return (NULL);
// }

// char	**ft_split(char const *str, char c)
// {
// 	int		i;
// 	char	**tableau;
// 	int		k;

// 	if (!str)
// 		return (NULL);
// 	tableau = malloc((ft_count(str, c, &i, &k) + 1) * sizeof(char *));
// 	if (!tableau)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			tableau[k] = malloc(ft_count_char(str, c, i) + 1);
// 			if (!tableau[k])
// 				return (clean(tableau, k));
// 			remplissage(str, tableau[k], ft_count_char(str, c, i), i);
// 			i += ft_count_char(str, c, i);
// 			k++;
// 		}
// 		i++;
// 	}
// 	tableau[k] = 0;
// 	return (tableau);
// }

// int	ft_count(char const *str, char c, int *j, int *k)
// {
// 	int	i;
// 	int	flag;
// 	int	nbr_mot;

// 	i = 0;
// 	*j = 0;
// 	*k = 0;
// 	flag = 1;
// 	nbr_mot = 0;
// 	while (str[i])
// 	{
// 		if ((str[i] != c) && flag == 1)
// 		{
// 			i++;
// 			nbr_mot++;
// 			flag = 0;
// 		}
// 		else if (str[i] == c)
// 			flag = 1;
// 		i++;
// 	}
// 	return (nbr_mot);
// }

// int	ft_count_char(char const *str, char c, int i)
// {
// 	int	nbr_mot;

// 	nbr_mot = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			i++;
// 			nbr_mot++;
// 		}
// 		else
// 			return (nbr_mot);
// 	}
// 	return (nbr_mot);
// }

// void	remplissage(char const *str, char *ret, int nbr_char, int position)
// {
// 	int	i;

// 	i = 0;
// 	while (str[position] && (i < nbr_char))
// 		ret[i++] = str[position++];
// 	ret[i] = '\0';
// }

// int	main(void)
// {
// 	char	mot[] = "lekilimadjarokestkcasse";
// 	char	**dict;
// 	int		i;

// 	dict = ft_split("", ' ');
// 	// dict = ft_split(mot, 'k');
// 	i = 0;
// 	while (dict[i] != NULL)
// 		printf("%s\n", dict[i++]);
// }

#include "libft.h"

char	**free_error(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_malloc(char **tab, const char *str, int words, char c)
{
	int	j;
	int	cur_word;
	int	i;

	i = 0;
	j = 0;
	cur_word = 0;
	while (str[i] && (cur_word < words))
	{
		while ((str[i] == c) && str[i])
			i++;
		j = 0;
		while (str[i] != c && str[i])
		{
			tab[cur_word][j] = str[i];
			i++;
			j++;
		}
		tab[cur_word][j] = '\0';
		cur_word++;
	}
	tab[cur_word] = 0;
	return (tab);
}

char	**ft_malloc_string(char **tab, const char *str, int words, char c)
{
	int	j;
	int	k;
	int	i;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] && k < words)
	{
		j = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			i++;
			j++;
		}
		tab[k] = malloc(sizeof(char) * (j + 1));
		if (!(tab[k]))
			return (free_error(tab));
		k++;
	}
	return (ft_malloc(tab, str, words, c));
}

void	init(int *i, int *n, int *words)
{
	*i = 0;
	*n = 0;
	*words = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n;
	int		words;
	char	**tab;

	init(&i, &n, &words);
	if (!s)
		return (NULL);
	while (s[i])
	{
		n = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			n++;
		}
		if (n > 0)
			words++;
	}
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	return (ft_malloc_string(tab, s, words, c));
}
