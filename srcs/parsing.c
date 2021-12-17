/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:43:56 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/17 11:11:14 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	ft_check(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] == to_find[i])
	{
		i++;
		if (to_find[i] == '\0')
			return (1);
	}
	return (0);
}

void	parsing_path(char **envp, char **argv, int n)
{
	t_pars	pars;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_check(envp[i], "PATH="))
			pars.path = ft_strdup(envp[i]);
	}
	pars.path = ft_substr(pars.path, 5, ft_strlen(pars.path));
	pars.paths = ft_split(pars.path, ':');
	pars.cmds = ft_split(argv[n], ' ');
	i = -1;
	while (pars.paths[++i])
	{
		pars.paths[i] = ft_strjoin(pars.paths[i], "/");
		pars.cmd = ft_strjoin(pars.paths[i], pars.cmds[0]);
		if (access(pars.cmd, F_OK) == 0)
			execve(pars.cmd, pars.cmds, envp);
		free(pars.cmd);
		free(pars.paths[i]);
	}
}
