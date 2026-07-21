#include <stdio.h>

int main(void){
	
	int a,b,ans;
	int i,j;
	
	scanf("%d %d",&a,&b);
	
	if(a==0){
		if(b<=1911){    //??????
			ans=b-1868+1;
			printf("M%d\n",ans);
			
		}else if(b<=1925){   //??§??£
			ans=b-1912+1;
			printf("T%d\n",ans);
			
		}else if(b<=1988){   //??????
			ans=b-1926+1;
			printf("S%d\n",ans);
			
		}else if(b<=2016){   //??????
			ans=b-1989+1;
			printf("H%d\n",ans);
		}
	}
	if(a==1){
		ans=1868+b-1;
		printf("%d\n",ans);
	}
	if(a==2){
		ans=1912+b-1;
		printf("%d\n",ans);
	}
	if(a==3){
		ans=1926+b-1;
		printf("%d\n",ans);
		
	}
	if(a==4){
		ans=1989+b-1;
		
		printf("%d\n",ans);
	}
		
	return 0;
}
