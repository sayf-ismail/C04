/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stun-ism <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:34:38 by stun-ism          #+#    #+#             */
/*   Updated: 2021/03/10 23:40:45 by stun-ism         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char l)
{
	write(1, &l, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	transform(int num, char *base)
{
	return (base[num]);
}

int		valid_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (j == i)
			{
				j++;
				continue;
			}
			if ((base[i] == base[j]) || (base[i] > '-' && base[i] < '!'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	buf[100];
	int		rad;
	int		i;

	rad = 0;
	while (base[rad] && valid_base(base))
		rad++;
	i = 99;
	buf[99] = '\0';
	if (nbr > 0)
	{
		while (nbr)
		{
			buf[--i] = transform(nbr % rad, base);
			nbr /= rad;
		}
	}
			nbr /= rad;
		}
		buf[--i] = '-';
	}
	ft_putstr(buf + i);
}
