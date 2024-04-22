/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:48:52 by msloot            #+#    #+#             */
/*   Updated: 2024/04/22 16:27:34 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_char(pid_t pid, char c)
{
	if (c != '\0')
	{
		ft_putchar(c);
		return ;
	}
	ft_putchar('\n');
	ft_putstr("whole message received from ");
	ft_putstr(Y_B_MAG);
	ft_putnbr(pid);
	ft_putstr(Y_RESET);
	ft_putchar('\n');
	kill(pid, SIGUSR1);	// BONUS: "The server acknowledges every message received by sending back a signal to the client."
}

#include <stdio.h>

static void	construct_char(bool bit, pid_t pid)
{
	static size_t	i = 0;	// index of bit in whole byte (byte == 8 bit == 1 char)
	static char		c = 0x00000000;  // (0x00000000 == 0 == byte 0000 0000)

	// fprintf(stderr, "%d: %d\n", pid, bit);

	if (bit)	// if bit is true (true == 0x00000001 == 1)
		c |= (1 << i);	// put bit at the right index, and merge it to c
	i++;
	if (i == 8)	// if whole 8 byte have been read (i++ before check, so 7 + 1)
	{
		handle_char(pid, c);	// go handle the created char
		c = 0x00000000;
		i = 0;
	}
}

// you don't need this function anymore
// you needed it to:
// - read the pid
//     now the `signinfo_t *info->si_pid` gives it to you
// - read the char and print it
//     now you have handle_char that just print it whenever 8 byte have been read

/*
SIGUSR1 => false
SIGUSR2 => true
*/

static void	ft_signal(int signum, siginfo_t *info, void *context)
{

	(void)context;
	construct_char(signum == SIGUSR2, info->si_pid);
}

static void	put_server_pid(void)
{
	ft_putstr("server active, PID: [");
	ft_putstr(Y_B_MAG);
	ft_putnbr(getpid());
	ft_putstr(Y_RESET);
	ft_putstr("]\n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc > 1)
		return (ft_puterr("no arguments needed in the server"), 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	put_server_pid();
	while (1)
		sleep(42);	// just waiting
					// whenever a signal is received, ft_signal si called
	return (0);
}
