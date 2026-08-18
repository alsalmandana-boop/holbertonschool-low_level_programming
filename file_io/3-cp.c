#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void close_file(int fd);

/**
 * main - Copies the content of a file to another file.
 * @ac: The number of arguments passed to the program.
 * @av: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	int from_fd, to_fd, r_bytes, w_bytes;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open(av[1], O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	to_fd = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close_file(from_fd);
		exit(99);
	}

	while ((r_bytes = read(from_fd, buffer, 1024)) > 0)
	{
		w_bytes = write(to_fd, buffer, r_bytes);
		if (w_bytes == -1 || w_bytes != r_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close_file(from_fd);
			close_file(to_fd);
			exit(99);
		}
	}

	if (r_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close_file(from_fd);
		close_file(to_fd);
		exit(98);
	}

	close_file(from_fd);
	close_file(to_fd);

	return (0);
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

