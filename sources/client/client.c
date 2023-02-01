/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:46:07 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/02/01 11:25:06 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../ft_printf/ft_printf.h"
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

void	sendstring(int pid, char *str)
{
	char	*convstr;
	int		i;

	convstr = ascii_to_binary(str);
	i = 0;
	ft_printf("the converted code is %s", convstr);
	while (convstr[i] != '\0')
	{
		if (convstr[i] == '0')
			kill(pid, SIGUSR1);
		if (convstr[i] == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(25);
	}
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
