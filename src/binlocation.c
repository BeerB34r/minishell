/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   binlocation.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: mde-beer <mde-beer@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/01/15 08:00:20 by mde-beer     #+#    #+#                  */
/*   Updated: 2025/01/15 11:03:08 by mde-beer     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

//	local headers
#include <minishell.h>
#include <ft_env.h>
#include <libft.h>
//	system headers
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

static int
	search_path(
		const char *path,
		const char *bin
		);
static char
	*find_embedded_command(
		const char *path,
		const char *bin
		);
static char
	*find_command(
		const char *bin
		);
void
	free_ar(
char **ar
);

//	exit specifically states that return values should be between 0-255
//	inclusive, i posit that this holds for _all_ builtins, and thus -1 can be
//	left for 'no builtin matched'
//	- Mats
int
	builtin(
char **argv
)
{
	const t_builtin	builtins[] = {
	{.name = "echo", .function = &builtin_echo},
	{.name = "cwd", .function = &builtin_pwd},
	{.name = "export", .function = &builtin_export},
	{.name = "unset", .function = &builtin_unset},
	{.name = "env", .function = &builtin_env},
	{.name = NULL, .function = NULL}};
	int				i;

	i = -1;
	while (builtins[++i].name != NULL)
	{
		if (ft_strncmp(builtins[i].name, argv[0], ft_strlen(argv[0]) + 1))
			continue ;
		return (builtins[i].function(argv));
	}
	return (-1);
}

int
	command(
const char **argv
)
{
	const char	*bin = find_command(argv[0]);

	if (!bin)
		return (1);
	return (mm_execve(bin, argv));
}

static char
	*find_command(
const char *bin
)
{
	const char	**paths = (const char **)ft_split(mm_getenv("PATH"), ':');
	const char	**temp = paths;
	char		*ret;

	if (!paths)
		return (NULL);
	while (*paths)
	{
		if (!ft_strchr(bin, '/') && !search_path(*paths, bin))
		{
			ret = ft_strjoin_all((const char *[]){*paths, bin, NULL}, "/");
			free_ar((char **)temp);
			return (ret);
		}
		else
		{
			ret = find_embedded_command(*paths, bin);
			if (ret)
				return (free_ar((char **)paths), ret);
		}
		paths++;
	}
	return (NULL);
}

static int
	search_path(
const char *path,
const char *bin
)
{
	DIR				*directory;
	struct dirent	*entry;

	directory = opendir(path);
	if (!directory)
		return (2);
	entry = readdir(directory);
	while (entry)
	{
		if (ft_strncmp(bin, entry->d_name, ft_strlen(bin) + 1))
		{
			entry = readdir(directory);
			continue ;
		}
		closedir(directory);
		return (0);
	}
	closedir(directory);
	return (1);
}

static char
	*find_embedded_command(
const char *path,
const char *bin
)
{
	const char	*bpath = ft_substr(bin, 0, ft_strrchr(bin, '/') - bin);
	const char	*bname = ft_strrchr(bin, '/') + 1;
	char		*spath;
	char		*ret;

	ret = NULL;
	if (!bpath)
		return (NULL);
	spath = ft_strjoin_all((const char *[]){path, bpath, NULL}, "/");
	if (spath && !search_path(spath, bname))
		ret = ft_strjoin_all((const char *[]){spath, bname, NULL}, "/");
	free((void *)bpath);
	free(spath);
	return (ret);
}
