/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:25:50 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/13 19:45:20 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puthexa_fd(unsigned long n, t_struct *data, int fd)
{
	char	*hxbase;

	if ((*data).type == UPHEXA)
		hxbase = ft_strdup("0123456789ABCDEF");
	else
		hxbase = ft_strdup("0123456789abcdef");
	if (n >= 16)
		ft_puthexa_fd(n / 16, data, fd);
	ft_putchar_fd(hxbase[n % 16], fd);
	free(hxbase);
}

void	ft_putunsint_fd(unsigned int n, t_struct *data, int fd)
{
	if (n >= 10)
		ft_putunsint_fd(n / 10, data, fd);
	ft_putchar_fd((n % 10) + 48, fd);
}


// if NULL avec %s print (null)
