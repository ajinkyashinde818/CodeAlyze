#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int s,d=0,f,g,h,j,i;
	char a[100001];
	scanf("%s",a);
	s=strlen(a);
	f=-1;
	while(1){
		//printf("%d %c\n",f+1,a[f+1]);
		if(a[f+1]=='e'&&a[f+2]=='r'&&a[f+3]=='a'&&a[f+4]=='s'&&a[f+5]=='e'&&a[f+6]=='r'){
			f+=6;
			if(a[f+1]!='e'&&a[f+1]!='d'&&f<s-1)
				f-=2;
		}
		else if(a[f+1]=='e'&&a[f+2]=='r'&&a[f+3]=='a'&&a[f+4]=='s'&&a[f+5]=='e')
			f+=5;
		else if(a[f+1]=='d'&&a[f+2]=='r'&&a[f+3]=='e'&&a[f+4]=='a'&&a[f+5]=='m'&&a[f+6]=='e'&&a[f+7]=='r'){
			f+=7;
			if(a[f+1]!='e'&&a[f+1]!='d'&&f<s-1)
				f-=2;
		}
		else if(a[f+1]=='d'&&a[f+2]=='r'&&a[f+3]=='e'&&a[f+4]=='a'&&a[f+5]=='m')
			f+=5;
		else break;
		if(f>=s-1)	break;
	}
	//printf("%d %d\n",f,s-1);
	if(f>=s-1)	printf("YES\n");
	else printf("NO\n");
	return 0;
}
