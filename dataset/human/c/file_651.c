#include<stdio.h>
typedef unsigned u;
char A[55][55],B[55][55];
int main()
{
	u a,b,i,j,k,I,J;
	scanf("%u%u",&a,&b);
	for(i=-1;++i<a;)scanf("%s",A[i]);
	for(i=-1;++i<b;)scanf("%s",B[i]);
	k=a-b+1;
	for(I=-1;++I<k;)for(J=-1;++J<k;)
	{
		for(i=-1;++i<b;)for(j=-1;++j<b;)
		{
			if(A[I+i][J+j]!=B[i][j])
			goto tjan;
		}
		printf("Yes\n");
		return 0;
		tjan:;
	}
	printf("No\n");
	return 0;
}
