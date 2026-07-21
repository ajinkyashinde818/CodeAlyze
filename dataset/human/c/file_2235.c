#include<stdio.h>
#include<string.h>

char ss[510000];
int flip;
int main(){
	char*s1=ss+200010;
	scanf("%s",s1);
	char*s2=s1+strlen(s1);
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1)flip^=1;
		else{
			int f;
			char c;
			scanf("%d %c",&f,&c);
			f--;
			if(f^flip)*s2++=c;
			else *--s1=c;
		}
	}
	while(s1!=s2){
		if(flip)putchar(*--s2);
		else putchar(*s1++);
	}
}
