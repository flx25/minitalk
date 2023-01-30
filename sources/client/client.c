/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:46:07 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/30 11:59:07 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	utf_len(const char *str)
{
	int	len;
	int	i;
	int	utf8_len;

	len = ft_strlen(str);
	i = 0;
	utf8_len = 0;
	while (i < len)
	{
		if (str[i] < 0x80)
			utf8_len++;
		else
			utf8_len += 2;
	}
	return (utf8_len);
}

unsigned char	*ascii_to_utf8(const char *str)
{
	int				j;
	int				i;
	unsigned char	*utf8_str;
	int				len;

	len = ft_strlen(str);
	utf8_str = malloc(utf_len(str) + 1);
	if (!utf8_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] < 0x80)
			utf8_str[j++] = str[i];
		else
		{
			utf8_str[j++] = 0xC0 | (str[i] >> 6);
			utf8_str[j++] = 0x80 | (str[i] & 0x3F);
		}
		i++;
	}
	utf8_str[j] = '\0';
	return (utf8_str);
}

int	sendstring(int PID, char *str)
{
	ascii_to_utf8();
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
}
