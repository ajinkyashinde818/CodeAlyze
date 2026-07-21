#include<stdio.h>

#define N 10000

int main()
{
				int a[N] = {0};
				int i,j,k;
				int count = 0;
				i = 0;

				while(1){
								scanf("%d",&a[i]);
								count++;
								if(a[i] == 0)
												break;
								i++;
				}

				for(i=0;i<count-1;i++){
								printf("Case %d: %d\n",i+1,a[i]);
				}

				return 0;
}
