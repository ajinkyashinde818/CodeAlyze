#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int i,j,k;
	int a,b;
	char c[101];
	int key[101];
	
	while(1){
		scanf("%d",&a);
		if(a==0){
			break;
		}
		for(i=0;i<a;i++){
			scanf("%d\n",&key[i]);
		}
		gets(c);
		i=0;
		int flag=0;
		while(c[i]){
			if(c[i]<='Z'&&c[i]>='A'){
				c[i]-='A'+26;
				flag=1;
			}else{
				c[i]-='a';
			}
			c[i]-=key[i%a];
			while(c[i]<0){
				c[i]+=52;
			}
			if(c[i]>=26){
				c[i]+='A'-26;
			}else{
				c[i]+='a';
			}
			i++;
		}
		printf("%s\n",c);
	}
	return 0;
}
