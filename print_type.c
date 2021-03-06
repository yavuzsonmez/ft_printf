/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:25:50 by ysonmez           #+#    #+#             */
/*   Updated: 2021/07/19 10:30:17 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharr_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_puthexa_fd(unsigned int n, t_struct *data, int fd)
{
	char	*hxbase;

	if ((*data).argunsint == 0 && (*data).prec == 0)
		return ;
	if ((*data).type == UPHEXA)
		hxbase = ft_strdup("0123456789ABCDEF");
	else
		hxbase = ft_strdup("0123456789abcdef");
	if (n >= 16)
		ft_puthexa_fd(n / 16, data, fd);
	ft_putchar_fd(hxbase[n % 16], data, fd);
	free(hxbase);
}

void	ft_putunsint_fd(unsigned int n, t_struct *data, int fd)
{
	if ((*data).argunsint == 0 && (*data).prec == 0)
		return ;
	if (n >= 10)
		ft_putunsint_fd(n / 10, data, fd);
	ft_putchar_fd((n % 10) + 48, data, fd);
}

void	ft_putunslong_fd(unsigned long n, t_struct *data, int fd)
{
	char	*hxbase;

	if ((*data).argptr == 0 && (*data).prec == 0)
		return ;
	hxbase = ft_strdup("0123456789abcdef");
	if (n >= 16)
		ft_putunslong_fd(n / 16, data, fd);
	ft_putchar_fd(hxbase[n % 16], data, fd);
	free(hxbase);
}

int	ft_printf_atoi(const char *str)
{
	size_t	i;
	int		result;

	i = 1;
	result = 0;
	while (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + ((str[i] - 48) % 10);
		i++;
	}
	return (result);
}
