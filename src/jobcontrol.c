/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   jobcontrol.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/15 15:01:19 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/15 15:55:12 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <ft_env.h>
#include <libft.h>


int
	command(
char **argv
);
//	set up some proper redirection and stuff, currently it does NOTHING with
//	half of its god damned job
int
	run(
t_job job
)
{
	int	ret;

	ret = builtin(job.argv);
	if (ret != -1)
		return (ret);
	ret = command(job.argv);
	if (ret != -1)
		return (ret);
	return (-1);
}
