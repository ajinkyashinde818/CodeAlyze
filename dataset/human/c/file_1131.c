#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,m,i,j,flg;
	char s[100],t[100],x;
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);
	m=strlen(t);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(s[i]>s[j]){
				x=s[j];
				s[j]=s[i];
				s[i]=x;
			}
		}
	}
	for(i=0;i<m-1;i++){
		for(j=i+1;j<m;j++){
			if(t[i]<t[j]){
				x=t[j];
				t[j]=t[i];
				t[i]=x;
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
