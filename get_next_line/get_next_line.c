/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:03 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/28 11:30:52 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	size_t nlen;
	char* c = (char*)calloc(100, sizeof(char));
	nlen = read(fd, c, 100);
	c[nlen] = '\0';
	return (c);
}

#include <stdio.h>
int main()
{
    // if file does not have in directory
    // then file foo.txt is created.
    int fd = open("test1.txt", O_RDONLY);
    printf("fd = %d\n", fd);
    int fd1 = open("test2.txt", O_RDONLY);
    printf("fd = %d\n", fd1);
    int fd2 = open("test3.txt", O_RDONLY);
    printf("fd = %d\n", fd2);
    int fd3 = open("test4.txt", O_RDONLY);
    printf("fd = %d\n", fd3);

    char *c = get_next_line(fd);
    printf("Those bytes are as follows: %s\n", c);
    return 0;
}