/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_itoa_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:24:22 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/04 20:24:25 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_len(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	ft_tchar(int len, int l, char *dest, int n)
{
	while (len-- > l)
	{
		dest[len] = n % 10 + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		end;
	int		l;
	char	*dest;

	l = 0;
	len = ft_len(n);
	end = ft_len(n);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	ft_tchar(len, l, dest, n);
	dest[end] = 0;
	return (dest);
}
