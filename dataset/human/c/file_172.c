#include<stdio.h>
char str[9];
int p[8];
int b[32];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%s",str);
		for(int j=0;j<8;j++){
			if(str[j]>='a'&&str[j]<='z'){
				p[j]=10+(str[j]-'a');
			}
			else p[j]=str[j]-'0';
		}
		for(int j=0;j<8;j++){
			for(int k=0;k<4;k++)if(p[7-j]&(1<<k))b[j*4+k]=1;
			else b[j*4+k]=0;
		}
		if(b[31])printf("-");
		long long ret=0;
		for(int j=0;j<31;j++){
			ret*=2;
			ret+=b[30-j];
		}
		int div=1024*1024*1024;
		if(!(ret%128)){
			printf("%lld",ret/128);
			printf(".0\n");
		}else{
			printf("%lld",ret/128);
			printf(".");
			ret%=128;
			while(ret){
				ret*=10;
				printf("%d",ret/128);
				ret%=128;
			}
			printf("\n");
		}
	}
}
