/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:48:52 by msloot            #+#    #+#             */
/*   Updated: 2024/04/17 16:45:52 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static ssize_t	ft_process(size_t mode, size_t value)
{
	size_t	*i;
	char	*c;
	char	ret;

	*i = 8;
	if (value == 1)
	{
		*c |= (1 << *i);
		i++;
	}
	if (mode == 1 && *i == 1)
	{
		ret = *c;
		*i = 8;
		*c = 0;
		return (ret);
	}
	return (-1);
}

static size_t	set_pid(size_t processing_pid, size_t pid, size_t byte)
{
	if (processing_pid == 0)
		return (pid = pid * 10 + byte - '0');
	else
		write(1, &byte, 1);
	return (0);
}

static size_t	ft_process_client(void)
{
	size_t	pid;
	ssize_t	byte;
	size_t	processing_pid;

	processing_pid = 1;
	pid = 0;
	while (1)
	{
		byte = ft_process(1, 0);
		if (byte == 0)
		{
			if (processing_pid)
				processing_pid = 0;
			else
			{
				write(1, "\n", 1);
				break ;
			}
		}
		if (byte != -1)
			pid = set_pid(processing_pid, pid, byte);
	}
	kill(pid, SIGUSR1);
	return (pid);
}

static void	ft_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_process(0, 0);
	else
		ft_process(0, 1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc > 1)
		return (ft_puterr("no arguments needed in the server"), 1);
	ft_putstr("server active, PID: [");
	ft_putstr(Y_B_MAG);
	ft_putnbr(getpid());
	ft_putstr(Y_RESET);
	ft_putstr("]\n");
	sa.sa_handler = &ft_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		ft_process_client();
	return (0);
}
