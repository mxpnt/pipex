/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:51:59 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/15 10:34:24 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_fork1(int f1, int end[2], char **argv, char **envp)
{
	if (dup2(f1, STDIN_FILENO) < 0)
		return (perror("DUP2 "));
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return (perror("DUP2 "));
	close(end[0]);
	close(end[1]);
	close(f1);
	parsing_path(envp, argv, 2);
}

void	ft_fork2(int f2, int end[2], char **argv, char **envp)
{
	if (dup2(f2, STDOUT_FILENO) < 0)
		return (perror("DUP2 "));
	if (dup2(end[0], STDIN_FILENO) < 0)
		return (perror("DUP2 "));
	close(end[1]);
	close(end[0]);
	close(f2);
	parsing_path(envp, argv, 3);
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int	end[2];
	int	pid1;
	int	pid2;

	pipe(end);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("FORK "));
	if (pid1 == 0)
		ft_fork1(f1, end, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("FORK "));
	if (pid2 == 0)
		ft_fork2(f2, end, argv, envp);
	close(end[0]);
	close(end[1]);
	waitpid(pid1, 0, 0);
	waitpid(pid2, 0, 0);
}
