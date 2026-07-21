#include <stdio.h>
#include <string.h>
char s[500100],in[100010],c[5];
int main(){
	int len,i,h,t,b,q,cmd,f;
	scanf("%s",in);
	len=strlen(in);
	for(i=200010;i<200010+len;i++)s[i]=in[i-200010];
	h=200010-1,t=200010+len;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&cmd);
		if(cmd==1)b=h,h=t,t=b;
		else if(cmd==2){
			scanf("%d%s",&f,c);
			if(f==1){//h
				if(h<t)s[h]=c[0],h--;
				else s[h]=c[0],h++;
			}else if(f==2){//t
				if(h<t)s[t]=c[0],t++;
				else s[t]=c[0],t--;
			}
		}
	}
	if(h>t)
		for(i=h-1;i>=t+1;i--)printf("%c",s[i]);
	else 
		for(i=h+1;i<=t-1;i++)printf("%c",s[i]);
	printf("\n");
	return 0;
}
