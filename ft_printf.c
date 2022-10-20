/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:38:56 by achansar          #+#    #+#             */
/*   Updated: 2022/10/20 12:08:20 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = ft_convert(str[i + 1], count, args);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int    main(void)
{
	//char *str = "def";
	//char letter = 'b';
	//int nb1 = 30345;
	//int nb2 = -10;
	char *ptr;
	
	ft_printf(" -> my = %d", ft_printf("NULL %p NULL", ptr));
	write(1, "\n\n", 2);
	printf(" -> true = %d\n", printf("NULL %p NULL", ptr));
	return (0);
}*/
