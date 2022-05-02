#include "main.h"

/**
 * append_text_to_file - Appends a text at the end of a file
 * @filename: Name of the file to append to
 * @text_content: String to append to the file
 * Return: 1 if successful else -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_ret, len = 0;

	if (filename == NULL)
		return (-1);

	while (text_content && text_content[len])
		len++;

	fd = open(filename, O_APPEND | O_RDONLY);
	if (!(fd > 0))
		return (-1);
	write_ret = write(fd, text_content, len);
	if (write_ret != len)
		return (-1);
	close(fd);
	return (1);
}
