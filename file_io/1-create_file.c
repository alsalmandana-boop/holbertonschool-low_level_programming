#include "main.h"

/**
 * create_file - creates a file and writes text_content to it
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t nwritten;

	if (filename == NULL)
		return (-1);

	/* O_CREAT: إنشاء الملف إذا لم يكن موجوداً */
	/* O_WRONLY: فتح الملف للكتابة فقط */
	/* O_TRUNC: تفريغ الملف إذا كان موجوداً من قبل */
	/* 0600: إعطاء صلاحيات rw------- (قراءة وكتابة للمالك فقط) */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;

		nwritten = write(fd, text_content, len);
		if (nwritten == -1 || nwritten != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
