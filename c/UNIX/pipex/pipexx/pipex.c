/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:54:16 by sraccah           #+#    #+#             */
/*   Updated: 2013/12/31 21:32:29 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"

void				child(char **argv, int pipe_fd[])
{
	int				fd;
	char			**cmd;

	close(pipe_fd[0]);
	if ((dup2(pipe_fd[1], STDOUT_FILENO) < 0))
	{
		perror("Child: Dup2 error");
		exit(1);
	}
	close(pipe_fd[1]);
	if (((fd = open(argv[1], O_RDONLY)) < 0))
	{
		perror("Child: Open error");
		exit(1);
	}
	if ((dup2(fd, STDIN_FILENO) < 0))
	{
		perror("Child: Dup2 error");
		exit(1);
	}
	close(fd);	
	cmd = (char **)ft_strsplit(argv[2], ' ');
	execvp(cmd[0], cmd);
	perror(cmd[0]);
	exit(1);
}

void				master(char **argv, int pipe_fd[])
{
	int				fd;
	char			**cmd;

	close(pipe_fd[1]);
	if ((dup2(pipe_fd[0], STDIN_FILENO) < 0))
	{
		perror("Dup2 error");
		exit(1);
	}
	close(pipe_fd[0]);
	if (((fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0))
	{
		perror("Open error");
		exit(1);
	}
	if (!(dup2(fd, STDOUT_FILENO)))
	{
		perror("Dup2 error");
		exit(1);
	}
	close(fd);
	cmd = (char **)ft_strsplit(argv[3], ' ');
	execvp(cmd[0], cmd);
	perror(cmd[0]);
	exit(1);
}

int					main(int argc, char *argv[])
{
	pid_t			pid;
	int				pipe_fd[2];

	if (argc != 5)
		return (-1);
	if (pipe(pipe_fd) < 0)
		return (-1);
	if ((pid = fork()) == 0)
		child(argv, pipe_fd);
	else if ((pid > 0) && wait(NULL))
		master(argv, pipe_fd);
	else
		return (-1);
	return (0);
}
