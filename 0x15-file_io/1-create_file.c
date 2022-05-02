#include "main.h"

/**
 * create_file - Creates a new file and adds content to it
 * @filename: Name of the file to be created
 * @text_content: The string to add to the file
 * Return: 1 if it is successful or -1 if it fails
 */

int create_file(const char *filename, char *text_content)
{
	int fd, write_ret, len = 0;

	if (filename == NULL)
		return (-1);

	while (text_content && text_content[len])
		len++;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	if (!(fd > 0))
		return (-1);
	write_ret = write(fd, text_content, len);
	if (write_ret != len)
		return (-1);
	close(fd);
	return (1);
}
