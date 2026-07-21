#include<stdio.h>
#include<string.h>
const char c[]={'m','c','x','i'};
const int v[]={1000,100,10,1};

int decode(char s[]){
	int x=0;
	int n;
	int tmp=1;
	int i,j;

	n=strlen(s);

	for(i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			tmp=s[i]-'0';
			continue;
		}
		for(j=0;j<4;j++){
			if(s[i]==c[j]){
				x=x+v[j]*tmp;
				tmp=1;
				break;
			}
		}
	}
	return x;
}
void encode(int sum){
	int i;
	int d;

	for(i=0;i<4;i++){
		d=0;
		while(sum>=v[i]){
			sum-=v[i];
			d++;
		}
		if(d>1){
			printf("%d",d);
		}
		if(d>0){
			printf("%c",c[i]);
		}
	}
		printf("\n");
	return;
}
int main(void){
	char s1[1024],s2[1024];
	int sum;
	int n;

	scanf("%d",&n);
	fflush(stdin);
	while(n--){
	scanf("%s %s",s1,s2);
	sum=decode(s1)+decode(s2);
	encode(sum);
	}
	return 0;
}
