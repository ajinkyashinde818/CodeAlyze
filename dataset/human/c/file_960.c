#include <stdio.h>

int main(void){
	int E,Y,ans;
	scanf("%d %d",&E,&Y);
	if(E==0){
		if(1868<=Y&&Y<=1911){
			ans=Y-1867;
			printf("M%d\n",ans);
		}
		
		if(1912<=Y&&Y<=1925){
			ans=Y-1911;
			printf("T%d\n",ans);
		}
		
		if(1926<=Y&&Y<=1988){
			ans=Y-1925;
			printf("S%d\n",ans);
		}
		
		if(1989<=Y&&Y<=2016){
			ans=Y-1988;
			printf("H%d\n",ans);
		}
	}
	
	else switch(E){
	case 1:
		printf("%d\n",Y+1867);
		break;
	case 2:
		printf("%d\n",Y+1911);
		break;
	case 3:
		printf("%d\n",Y+1925);
		break;
	case 4:
		printf("%d\n",Y+1988);
		break;
	}
	
	return 0;
}
