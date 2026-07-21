#include <stdio.h>          // printf(), fprintf(), getline()
#include <stdlib.h>         // exit(), free(), strtol()
#include <stdbool.h>
#include <errno.h>          // errno
#ifdef linux
 #include <error.h>         // error()
#endif

#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)

//const char NUL = '\0';
int lineno;
char* linebuff = NULL;
size_t linebuffsize = 0;

void
cleanup(int ecode)
{
	if (linebuff)
	{
		free(linebuff);
		linebuff = NULL;
		linebuffsize = 0;
	}

	exit(ecode);
}

bool
readline()
{
	errno = 0;
	if(getline(&linebuff, &linebuffsize, stdin) == -1) // read line
	{
		if(errno == 0)  // EOF?
			return false;

#ifdef linux
		error(0, errno, "Can't read line");
#else
		fprintf(stderr, "Can't read line\n");
#endif
		cleanup(1);
	}

	return true;
}

int
main(int argc, char** argv)
{
	char* nextp = NULL;
	int n, i;
	int r;
	
	int maxv = -1000000000;
	int minv = 0;

	lineno = 0;
	if (!readline())
		cleanup(1);

	n = strtol(linebuff, &nextp, 10);
	if (!readline())
		cleanup(1);

	minv = strtol(linebuff, &nextp, 10);
	for (i = 1; i < n; ++i) // process for each line
	{
		readline();
		r = strtol(linebuff, &nextp, 10);
		maxv = max(maxv, r - minv);
		minv = min(minv, r);
	}

	printf("%d\n", maxv);
	cleanup(0);
	return 0;
}
