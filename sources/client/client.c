/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:46:07 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/30 13:48:19 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

char	*ascii_to_binary(const char *str)
{
	int		j;
	int		i;
	char	*out;
	int		len;

	len = ft_strlen(str);
	out = malloc((len * 8 + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] & (1 << j))
				*out++ = '1';
			else
				*out++ = '0';
			j--;
		}
		i++;
	}
	return (*out = '\0', out - len * 8);
}

int	sendstring(int pid, char *str)
{
	char	*convstr;

	convstr = ascii_to_binary(str);
	ft_printf("the converted code is %s", convstr);
	kill(pid, SIGUSR1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_printf("Please enter the server PID and a string to send!");
	else if (argv[1][0] == '\0')
		ft_printf("Please enter a correct PID!");
	else if (argv[2][0] == '\0')
		ft_printf("Please enter a string!");
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
			ft_printf("Please enter a correct PID!");
		else
			sendstring(pid, argv[2]);
	}
	return (0);
}
