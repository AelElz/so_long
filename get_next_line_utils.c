/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:55:12 by ael-azha          #+#    #+#             */
/*   Updated: 2025/04/13 17:19:12 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strlcpy_(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strdup_(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_update_remaining_str(char **str, int i)
{
	char	*temp;

	if ((*str)[i] == '\0')
	{
		free(*str);
		*str = NULL;
		return ;
	}
	temp = ft_strdup_(&(*str)[i]);
	if (!temp)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	free(*str);
	*str = temp;
}

char	*ft_extract_line(char **str)
{
	int		i;
	char	*line;

	i = 0;
	if (!*str)
		return (NULL);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	ft_strlcpy_(line, *str, i + 1);
	ft_update_remaining_str(str, i);
	return (line);
}
