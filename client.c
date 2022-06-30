/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <sneyt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:12:29 by sneyt             #+#    #+#             */
/*   Updated: 2022/06/29 12:37:05 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*char_to_binary(char c)
{
	int		ascii;
	char	*byte;
	int		x;

	ascii = c;
	byte = malloc(sizeof(char) * 9);
	if (!byte)
		return (0);
	byte[8] = '\0';
	if (ascii < 65)
	{
		byte[0] = '0';
		byte[1] = '0';
	}
	else
		byte[0] = '0';
	x = 7;
	while (ascii >= 2)
	{
		byte[x] = (ascii % 2 + '0');
		ascii /= 2;
		x--;
	}
	byte[x] = (ascii % 2 + '0');
	return (byte);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		x;
	char	*byte;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("EXPECTED 2 ARGUMENTS:[PID], [MESSAGE]\n", 1);
		return (1);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		byte = char_to_binary(argv[2][i]);
		x = 0;
		while (x <= 7)
		{
			if (byte[x++] == '1')
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(80);
		}
		i++;
		free(byte);
	}
}
