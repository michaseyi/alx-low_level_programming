#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_error - Prints an error message to the standard err besed on the
 * error code
 * @type: Error type
 * @fd: File descriptor
 * @filename: Filename
 * @buffer: Buffer
 * Return: void
 */

void create_error(int type, int fd, char *filename, char *buffer)
{
	if (buffer)
		free(buffer);
	switch (type)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(type);
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(type);
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(type);
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(type);
	default:
		return;
	}
}

/**
 * main - Copies the content of a file to another file
 * @argc: Number of command line arguments
 * @argv: Array of command line aruguments
 * Return: 1 on success
 * 97 if @argc is not 3
 * 98 if unable to read from source
 * 99 if unable to write to destinatin
 * 100 if unable to close a file
 */

int main(int argc, char *argv[])
{
	int source, dest, write_ret, read_ret, close_ret;
	char *buffer;

	if (argc != 3)
		create_error(97, EMPTY, NULL, NULL);

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		create_error(99, EMPTY, argv[2], NULL);

	source = open(argv[1], O_RDONLY);
	if (source == -1)
		create_error(98, EMPTY, argv[1], buffer);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (dest == -1)
		create_error(99, EMPTY, argv[2], buffer);

	read_ret = read(source, buffer, BUFFER);
	while (read_ret)
	{
		if (read_ret == -1)
			create_error(98, EMPTY, argv[1], buffer);
		write_ret = write(dest, buffer, read_ret);
		if (write_ret == -1)
			create_error(99, EMPTY, argv[2], buffer);
		read_ret = read(source, buffer, BUFFER);
	}
	close_ret = close(source);
	if (close_ret == -1)
		create_error(100, source, NULL, buffer);
	close_ret = close(dest);
	if (close_ret == -1)
		create_error(100, dest, NULL, buffer);
	free(buffer);
	return (0);
}
