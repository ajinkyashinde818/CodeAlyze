#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[4];
	int a=0,b=0,c=0;
	int i=0;
	
	scanf("%s",str);
	
	for(i=0; i<3; i++){
		if(str[i] == 'a'){
			a++;
		}else if(str[i] == 'b'){
			b++;
		}else{
			c++;
		}
	}
	
	if(a==1 && b==1 && c==1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}
