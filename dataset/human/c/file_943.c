#include<stdio.h>
int main()
{
	int e,y;
	scanf("%d %d",&e,&y);
	switch(e){
	case 0:
		if(y<1912){
			printf("M%d\n",y-1867);
		}else if(y<1926){
			printf("T%d\n",y-1911);
		}else if(y<1989){
			printf("S%d\n",y-1925);
		}else{
			printf("H%d\n",y-1988);
		}
		break;
	case 1:
		printf("%d\n",1867+y);
		break;
	case 2:
		printf("%d\n",1911+y);
		break;
	case 3:
		printf("%d\n",1925+y);
		break;
	default:
		printf("%d\n",1988+y);
	}
	return 0;
}
