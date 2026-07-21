#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,j,len,n,flg;
	char s[100],t[100],box;
	scanf("%s %s",s,t);
	len=strlen(s);
	n=strlen(t);
	for(i=0;i<len-1;i++){
		for(j=i+1;j<len;j++){
			if(s[i]>s[j]){
			     box=s[i];
				s[i]=s[j];
				s[j]=box;
			}
		}
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(t[i]<t[j]){
				box=t[i];
				t[i]=t[j];
				t[j]=box;
			}
		}
	}
	if(strcmp(s,t)<0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
