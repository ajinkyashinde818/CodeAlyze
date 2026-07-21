#include<stdio.h>
#include<string.h>
int main()
{
	char s[100],t[100];
	int a,i,j,x,y;
	scanf("%s %s",s,t);
	x=strlen(s);
	y=strlen(t);
	a=0;
	for(i=0;i<x-1;i++){
		for(j=i+1;j<x;j++){
			if(s[i]>s[j]){
				a=s[i];
				s[i]=s[j];
				s[j]=a;
			}
		}
	}
	for(i=0;i<y-1;i++){
		for(j=i+1;j<y;j++){
			if(t[i]<t[j]){
				a=t[i];
				t[i]=t[j];
				t[j]=a;
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
