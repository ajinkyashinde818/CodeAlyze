#include<stdio.h>
int readint(void)
{
	int x;
	scanf("%d",&x);
	return x;
}
int main(void)
{
	int k=readint(),s=readint(),cnt=0;
    for(int x=0;x<=k;++x)
        for(int y=0;y<=k;++y)
            if(s-x-y>=0&&s-x-y<=k)++cnt;
    printf("%d\n",cnt);
    return 0;
}
