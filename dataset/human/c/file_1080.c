#include <stdio.h>
#include <string.h>

int n;
char str[1001],str2[1001];

int main(void){
	scanf("%d",&n);
	int i,dd;
	for(dd=0;dd<n;dd++){
		scanf("%s%s",str,str2);
		int c=0;
		int f=1;
		int len=strlen(str);
		for(i=0;i<len;i++){
			if(str[i]>='2' && str[i]<='9'){
				f=str[i]-'0';
			}
			if(str[i]=='m'){
				c+=1000*f;
				f=1;
			}
			if(str[i]=='c'){
				c+=100*f;
				f=1;	
			}
			if(str[i]=='x'){
				c+=10*f;
				f=1;	
			}
			if(str[i]=='i'){
				c+=f;
				f=1;	
			}
		}
		f=1;
		len=strlen(str2);
		for(i=0;i<len;i++){
			if(str2[i]>='2' && str2[i]<='9'){
				f=str2[i]-'0';
			}
			if(str2[i]=='m'){
				c+=1000*f;
				f=1;
			}
			if(str2[i]=='c'){
				c+=100*f;
				f=1;	
			}
			if(str2[i]=='x'){
				c+=10*f;
				f=1;	
			}
			if(str2[i]=='i'){
				c+=f;
				f=1;
			}
		}
		int k=1000;
		while(k>0){
			int d=c/k;
			if(d>=1){
				if(d>=2)printf("%d",d);
				if(k==1000)printf("m");
				if(k==100)printf("c");
				if(k==10)printf("x");
				if(k==1)printf("i");
			}
			c%=k;
			k/=10;
		}
		printf("\n");
	}
	return 0;
}
