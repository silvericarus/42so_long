/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:00:28 by albgonza          #+#    #+#             */
/*   Updated: 2022/06/21 18:42:53 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*strjoined;
	char	*temp;
	size_t	len;
	size_t	temp_len;

	strjoined = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!strjoined || !s1 || !s2)
		return (NULL);
	temp = strjoined;
	len = ft_strlen_gnl(s1);
	temp_len = len;
	while (len--)
		*temp++ = *s1++;
	s1 -= temp_len;
	len = ft_strlen_gnl(s2);
	while (len--)
		*temp++ = *s2++;
	*temp = 0;
	free((void *)s1);
	return (strjoined);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*found;

	if (s)
	{
		while (*s != '\0')
		{
			if ((char)*s == (char)c)
			{
				found = (char *)s;
				return (found);
			}
			s++;
		}
		if (c == 0)
			return (found = (char *)s);
	}
	return (NULL);
}
