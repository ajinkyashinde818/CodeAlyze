#include <stdio.h>
#include <string.h>


void sortToBig(char str[], int left, int right)
{
	char sample = str[left];
	int lptr = left, rptr = right;
	if (lptr < rptr){
		while (lptr != rptr){
			while ((sample < str[rptr]) && (lptr != rptr)) rptr--;
			if (lptr != rptr) str[lptr++] = str[rptr];
			while ((str[lptr] < sample) && (lptr != rptr)) lptr++;
			if (lptr != rptr) str[rptr--] = str[lptr];
		}
		str[lptr] = sample;
		sortToBig(str, left, lptr - 1);
		sortToBig(str, rptr + 1, right);
	}
}

void sortToS(char str[], int left, int right)
{
	char sample = str[left];
	int lptr = left, rptr = right;
	if (lptr < rptr){
		while (lptr != rptr){
			while ((sample > str[rptr]) && (lptr != rptr)) rptr--;
			if (lptr != rptr) str[lptr++] = str[rptr];
			while ((str[lptr] > sample) && (lptr != rptr)) lptr++;
			if (lptr != rptr) str[rptr--] = str[lptr];
		}
		str[lptr] = sample;
		sortToS(str, left, lptr - 1);
		sortToS(str, rptr + 1, right);
	}
}

int main(void)
{
	char s[200], t[200];
	scanf("%s", s);
	scanf("%s", t);

	int N = strlen(s); int M = strlen(t);

	sortToBig(s, 0, N- 1);
	sortToS(t, 0, M- 1);

	int min = (N < M) ? N : M;

	if (strcmp(s,t)<0) printf("Yes\n");
	else printf("No\n");

	return 0;
}
