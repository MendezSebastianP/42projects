#include "minishell.h"

char	*get_path_command(char **paths, char *command)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;
	char	*path;

	i = 0;
	j = -1;
	if ((command == NULL) | (paths[0] == NULL))
		return (ft_calloc(1, 1));
	while (j != 0 && paths[i])
	{
		temp = ft_strjoin(paths[i++], "/");
		temp2 = ft_strjoin(temp, command);
		j = access(temp2, F_OK);
		if (j == 0)
			path = ft_strdup(temp2);
		free(temp);
		free(temp2);
	}
	if (j == 0)
		return (path);
	return (ft_calloc(1, 1));
}

char	*no_args_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*first_cmd;

	i = 0;
	j = 0;
	if (cmd == NULL)
		return (ft_strdup("Error"));
	while (cmd[i] && cmd[i] != ' ')
		i++;
	if (ft_strlen(cmd) == (size_t)i)
		return (ft_strdup(cmd));
	first_cmd = malloc((i + 1) * sizeof(char));
	if (!first_cmd)
		return (NULL);
	while (j < i)
	{
		first_cmd[j] = cmd[j];
		j++;
	}
	first_cmd[j] = '\0';
	return (first_cmd);
}


void type6(t_pipex *pip, int i)
{
        int		open_fd;

        if (access(pip->v[i + 1], R_OK) == -1)
        {
                write(2, "zsh: permission denied: test/no_read\n", 37);
                (free_pip(pip), exit(EXIT_FAILURE));
        }
        open_fd = open(pip->v[i + 1], O_RDONLY);
        if (dup2(open_fd, STDIN_FILENO) == -1)
                (perror("dup2"), exit(EXIT_FAILURE));
        close(open_fd);
        ft_printf_fd(2, "here\n");
}

void type5(t_pipex *pip, int i)
{
        i = lvl2_len(pip->fd);
	if (dup2(pip->fd[i - 1][0], STDIN_FILENO) == -1)
		(perror("dup2 2"), exit(EXIT_FAILURE));
}

void type1(t_pipex *pip, int *out)
{
        int		fd_out;

        if (access(pip->v[*out], F_OK) == 0 && access(pip->v[*out], W_OK) == -1)
	{
		write(2, "zsh: permission denied: test/no_write\n", 38);
		(free_pip(pip), exit(EXIT_FAILURE));
	}
        fd_out = open(pip->v[*out], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	(dup2(fd_out, STDOUT_FILENO), close(fd_out), ft_close_all(pip->fd));
        *out = *out - 2;
}

void type2(t_pipex *pip)
{
        if (dup2(pip->fd[0][1], STDOUT_FILENO) == -1)
		(perror("dup2 1"), exit(EXIT_FAILURE));
	ft_close_all(pip->fd);
}

void	exe_isolate(t_pipex *pip, int i, int t1, int t2)
{
	char	**temp2;
	char	*no_a;
	char	*get_p;
        int		open_fd;
        if (t1 == 6) 
                type6(pip, i++);
        else if (t1 == 5)
                type5(pip, i);
        if (t2 == 1)
                type1(pip, &i);
	if (t2 == 2)
                type2(pip);
	temp2 = ft_split_exe(pip->v[i + 1], ' ');
	no_a = no_args_cmd(pip->v[i + 1]);
	get_p = get_path_command(pip->path, no_a);
	execve(get_p, temp2, pip->envp);
	ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]);
	(cleanexit(temp2), free_pip(pip), free(no_a), free(get_p), exit(127));
}



void	pid1(t_pipex *pip, int out)
{
	int		fd_out;
	int		i;
	char	**t;
	char	*no_a;
	char	*get_p;

	if (access(pip->v[out], F_OK) == 0 && access(pip->v[out], W_OK) == -1)
	{
		write(2, "zsh: permission denied: test/no_write\n", 38);
		(free_pip(pip), exit(EXIT_FAILURE));
	}
	i = lvl2_len(pip->fd);
	if (dup2(pip->fd[i - 1][0], STDIN_FILENO) == -1)
		(perror("dup2 2"), exit(EXIT_FAILURE));
	fd_out = open(pip->v[out], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	(dup2(fd_out, STDOUT_FILENO), close(fd_out), ft_close_all(pip->fd));
	t = ft_split_exe(pip->v[out - 1], ' ');
	no_a = no_args_cmd(pip->v[out - 1]);
	get_p = get_path_command(pip->path, no_a);
	execve(get_p, t, pip->envp);
	(ft_printf_fd(2, "zsh: command not found: %s\n", t[0]), free(get_p));
	(cleanexit(t), free(no_a), free_pip(pip), exit(127));
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pip;
	int		i;

	i = 0;
	pip = init_pipex(envp, argv, argc);
        if (pipe(pip->fd[0]) == -1)
		return (perror("pipe1"), 1);
	pip->pid[i] = fork();
	if (pip->pid[0] == 0)
		(exe_isolate(pip, i, 4, 2));
        pip->pid[i + 1] = fork();
	if (pip->pid[1] == 0)
                exe_isolate(pip, argc - 1, 5, 1);
		//(pid1(pip, argc - 1));
        ft_close_all(pip->fd);
	i = wait_all(pip->pid, i + 1);
	return (free_pip(pip), i);
}