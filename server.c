/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <sneyt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:12:32 by sneyt             #+#    #+#             */
/*   Updated: 2022/06/29 14:06:06 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	handle_sigusr(int sig)
{
	static int	count = 0;
	static char	c;

	if (sig == 30)
	{
		c = c << 1;
		c++;
	}
	else
		c = c << 1;
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;

	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_handler = &handle_sigusr;
	ft_putstr_fd("Starting up server. Current PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa1, NULL);
	while (1)
		pause();
	return (0);
}
