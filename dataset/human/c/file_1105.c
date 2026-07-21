#include<stdio.h>
#include<string.h>
int spow(int x ,int y){
	int i,ans=1;
	if(y==0)
		return 1;
	
	for(i=0;i<y;i++){
		ans*=x;
	}
	return ans;
}
void encode(int num,char* ans){
	char a=0,b;
	char digit[4];
	char digit_c[5]="mcxi";
	for(b=0;b<4;b++){
		digit[b]=num/spow(10,3-b);
		num-=digit[b]*spow(10,3-b);
	}
	for(b=0;b<4;b++){
		if(digit[b]!=0){
			if(digit[b]==1){
				ans[a]=digit_c[b];
				a++;
			}
			else{
				ans[a]='0'+digit[b];
				a++;
				ans[a]=digit_c[b];
				a++;
			}
		}
		
	}
	ans[a]='\0';
}
int decode(char* str){
	int ans=0;
	int a=0,b=0;
	char digit[5]="mcxi";
	while(1){
		if(str[a]=='\0')break;
		if('2'<=str[a]&&str[a]<='9'){
			int d=str[a]-'0';
			a++;
			ans+=d*spow(10,(3-(strchr(digit,str[a])-digit)));
			a++;
		}
		else{
			ans+=spow(10,(3-(strchr(digit,str[a])-digit)));
			a++;
		}
	}
	return ans;
}
int main(){
	char str1[10],str2[10],ans[10];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %s",str1,str2);
		encode(decode(str1)+decode(str2),ans);
		puts(ans);
	}
	return 0;
}
