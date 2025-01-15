/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   signals.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/14 19:50:37 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/14 20:48:21 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>

//	sends a signal to all members of current group to chill the fuck out. proper
//	handlers should be initialised upon forking
void
	default_sigint(
int signo,
siginfo_t *siginfo,
void *context
)
{
	(void)context;
	(void)siginfo;
	(void)signo;
	kill(0, SIGQUIT);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void
	default_sigquit(
int signo,
siginfo_t *siginfo,
void *context
)
{
	(void)signo;
	(void)siginfo;
	(void)context;
}

void
	attach_handler(
struct sigaction *handler,
void (*function)(int, siginfo_t *, void *),
int signal
)
{
	sigemptyset(&(handler->sa_mask));
	sigaddset(&(handler->sa_mask), signal);
	handler->sa_flags = (SA_SIGINFO | SA_RESTART);
	handler->sa_sigaction = function;
	sigaction(signal, handler, NULL);
}
