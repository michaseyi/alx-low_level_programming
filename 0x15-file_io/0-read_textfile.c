#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standart output
 * @filename: The file to read from
 * @letters: The number of letters to read and print from @filename
 * Return: The actual number of the letters it could read and print
 *          0 if file cound not be opened or read
 *          0 if write fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	size_t len = 0;
	char temp;
	int read_ret;


	if (filename == NULL)
		return (len);

	fd = open(filename, O_RDONLY);
	if (!(fd > 0))
		return (len);
	while ((read_ret = (read(fd, &temp, 1)) == 1) && len < letters)
	{
		if (write(STDOUT_FILENO, &temp, 1) != 1)
			return (0);
		len++;
	}
	if (read_ret == -1)
		return (0);
	close(fd);
	return (len);
}
