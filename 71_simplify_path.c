#include <string.h>

char *simplifyPath(char *path)
{
	char	*res;
	int	next;

	res = strdup(path);
	next = 0;
	while (*path) {
		switch (*path) {
		case '/':
			if (next == 0 || res[next - 1] != '/')
				res[next++] = '/';
			path++;
			break;
		case '.':
			if (*(path + 1) == 0) {
				path++;
				continue;
			}
			if (*(path + 1) == '/') {
				path += 2;
				continue;
			}
			if (*(path + 1) != '.') {
				while (*path && *path != '/')
					res[next++] = *path++;
				continue;
			}

			/* ..* */

			if (*(path + 2) == 0 || *(path + 2) == '/') {
				path += 2;
				if (next == 1)
					continue;
				next--;
				while(res[next - 1] != '/')
					next--;
				continue;
			}

			while (*path && *path != '/')
				res[next++] = *path++;
		default:
			while (*path && *path != '/')
				res[next++] = *path++;
			break;
		}
	}
	if (next != 1 && res[next - 1] == '/')
		next--;
	res[next] = 0;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", simplifyPath(argv[1]));
	return(0);
}
