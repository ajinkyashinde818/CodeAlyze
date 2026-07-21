#include<stdio.h>
int main(void)
{
	char zyuroku[17]={"0123456789abcdef"};
	int ni[16][4]={{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
					{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
					{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},	
					{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
	int suu[32];
	int i,j,k,l;
	char buf[9];
	int q;
	int keta, su;
	int ke2,su2,su3[9];
	int flg;
	
	scanf("%d",&q);
	for(i=0;i<q;i++)	{
		scanf("%s",buf);
		for(j=0;j<8;j++)	{
			for(k=0;k<16;k++)	{
//				printf("%c ",buf[j]);
				if(buf[j]==zyuroku[k])	{
					suu[j*4]=ni[k][0];
					suu[j*4+1]=ni[k][1];
					suu[j*4+2]=ni[k][2];
					suu[j*4+3]=ni[k][3];
//					printf("j=%d k=%d\n",j,k);
				}
//				break;
			}
		}
		if(suu[0]==1)	{
			printf("-");
		}
		keta=1;
		su=0;
		for(j=24;j>=1;j--)	{
			su=su+suu[j]*keta;
			keta=keta*2;
		}
		printf("%d.",su);
		keta=500000000;
		su=0;
		for(j=25;j<=31;j++)	{
			su=su+keta*suu[j];
			keta=keta/2;
		}
		if(su==0)	{
			printf("0\n");
		}
		else {
			for(j=8;j>=0;j--)	{
				su3[j]=su%10;
				su=su/10;
			}
			for(j=8;j>=0;j--)	{
				if(su3[j]==0)	{
					su3[j]=-1;
				}
				else {
					break;
				}
			}
			for(j=0;j<=8;j++)	{
				if(su3[j]>=0)	{
					printf("%d",su3[j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
