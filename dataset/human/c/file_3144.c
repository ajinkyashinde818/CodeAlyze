#include <stdio.h>
int main(void)
{
	int i, l, house;
	int nnum, bnum = 0, longest = 0;
	int first;

	scanf("%d", &l);
	scanf("%d", &house);
	for (i = 0; i < house; i++) {
		if (i == 0) {
			scanf("%d", &bnum);
			first = bnum;
		}
		else {
			scanf("%d", &nnum);
			if ((nnum - bnum) > longest)
				longest = nnum - bnum;
			bnum = nnum;
			if (i == house - 1) {
				if (longest < (l - bnum + first))
					longest = l - bnum + first;
			}
		}
	}

	printf("%d\n", l - longest);
	return 0;
}
