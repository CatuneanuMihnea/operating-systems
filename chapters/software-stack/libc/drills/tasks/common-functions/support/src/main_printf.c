// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

#include "./syscall.h"
#include "./os_string.h"
#include "./printf.h"

static const char src[] = "warhammer40k";
static char dest[128];
static char out_buffer[256];

static char putchar_buffer[1024];
static char putchar_buffer_len;

void flush(void)
{
	write(1, putchar_buffer, putchar_buffer_len);
	putchar_buffer_len = 0;
}

void _putchar(char character)
{

	putchar_buffer[putchar_buffer_len] = character;
	putchar_buffer_len++;
	if (character == '\n' || putchar_buffer_len == 1024)
		flush();


}

int main(void)
{
	/* TODO 5: Replace printf() with sprintf() and write(). */
	sprintf(out_buffer, "[before] src is at %p, len is %lu, content: \"%s\"\n", src, os_strlen(src), src);
	write(1, out_buffer, strlen(out_buffer));

	sprintf(out_buffer, "[before] dest is at %p, len is %lu, content: \"%s\"\n", dest, os_strlen(dest), dest);
	write(1, out_buffer, strlen(out_buffer));


	printf("copying src to dest\n");
	os_strcpy(dest, src);

	/* TODO 5: Replace printf() with sprintf() and write(). */
	sprintf(out_buffer, "[after] src is at %p, len is %lu, content: \"%s\"\n", src, os_strlen(src), src);
	write(1, out_buffer, strlen(out_buffer));

	sprintf(out_buffer, "[after] dest is at %p, len is %lu, content: \"%s\"\n", dest, os_strlen(dest), dest);
	write(1, out_buffer, strlen(out_buffer));

	exit(0);
	return 0;
}