/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:44:37 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/13 15:40:25 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pars
{
	char	*path;
	char	**paths;
	char	*cmd;
	char	**cmds;
}				t_pars;

/* utils.c
*/
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

/* ft_split.c
*/
char	**ft_split(char const *s, char c);

/* parsing.c
*/
void	parsing_path(char **envp, char **argv, int n);

/* pipex.c
*/
void	ft_fork1(int f1, int end[2], char **argv, char **envp);
void	ft_fork2(int f2, int end[2], char **argv, char **envp);
void	pipex(int f1, int f2, char **argv, char **envp);

#endif