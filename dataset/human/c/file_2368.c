#include<stdio.h>
int main(void){
	char f[3];
	int a=0,b=0,c=0;
for(int i=0;i<3;i++){
		scanf("%c",&f[i]);
	}
		for(int i=0;i<3;i++){
		if(f[i]=='a'){
		a++;
		}
		if(f[i]=='b'){
		b++;
		}
		if(f[i]=='c'){
		c++;
		}
	}
	if(a==1&&b==1&&c==1){
		printf("Yes");
	return 0;
	}
	printf("No");
	
	return 0;
}
