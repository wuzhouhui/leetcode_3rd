#include <string.h>

int lengthOfLastWord(char *s)
{
	int	left, right;
	int	i;

	for (right = strlen(s) - 1; right >= 0; right--)
		if (s[right] == ' ')
			continue;
		else
			break;
	if (right < 0)
		return(0);

	for (left = right - 1; left >= 0; left--)
		if (s[left] != ' ')
			continue;
		else
			break;
	return(right - left);
}

int main(void)
{
}
