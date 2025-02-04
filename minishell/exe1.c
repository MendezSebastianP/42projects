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

void	exe_isolate(t_pipex *pip, int i)
{
	char	**temp2;
	char	*no_a;
	char	*get_p;

	temp2 = ft_split_exe(pip->v[i + 1], ' ');
	no_a = no_args_cmd(pip->v[i + 1]);
	get_p = get_path_command(pip->path, no_a);
	execve(get_p, temp2, pip->envp);
	ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]);
	(cleanexit(temp2), free_pip(pip), free(no_a), free(get_p), exit(127));
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pip;
	int		i;

	i = 0;
	pip = init_pipex(envp, argv, argc);
	pip->pid[i] = fork();
	if (pip->pid[0] == 0)
		(exe_isolate(pip, i));
	i = wait_all(pip->pid, i + 1);
	return (free_pip(pip), i);
}