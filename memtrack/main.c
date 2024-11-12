/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/12 16:19:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}

int	ft_addrcmp(void *data1, void *data2)
{
	if (data1 == data2)
		return (0);
	return (1);
}

void	freedom(void **data, t_mt **list)
{
	if (list && *list && data && *data)
		ft_mtremove(list, ft_mtfind_data(*list, *data));
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
}

void	*chaosmatrix(int count, size_t size, int flag)
{
	void		*ptr;
	t_mt		*tmp;
	static t_mt	*list;

	if (flag == -1)
	{
		ft_mtclear(&list, ft_mtdel_data);
		return (NULL);
	}
	if (flag)
		return (list);
    ptr = NULL;
	ptr = malloc(count * size);
	if (ptr)
	{
		ft_memset(ptr, 0, count * size);
		tmp = ft_mtnew(&ptr);
		tmp->size = size;
		ft_mtadd_front(&list, tmp);
		return (ptr);
	}
	return (NULL);
}

int	main(void)
{
	t_mt	*list;
	char	**array;
    char *str1;
    char *str2;

	array = chaosmatrix(2, sizeof(char *), 0);
    array[0] = ft_strdup("Hello");
    array[1] = ft_strdup("World");
	(void)array;
    (void)str1;
    (void)str2;
	list = chaosmatrix(0, 0, 1);
	ft_mtprint(list);
	/* ft_mtclear(&list, ft_mtdel_data); */
	chaosmatrix(0, 0, -1);
	return (0);
}
