#include<stdio.h>

int main(){
		char s[100005];
		scanf("%s",s);
		int length_s=0;
		while(s[length_s]!=0)length_s++;
		int i;
		for(i=length_s-1;i>=0;){
			if(s[i]=='m'&&s[i-1]=='a'&&s[i-2]=='e'&&s[i-3]=='r'&&s[i-4]=='d')i-=5;
			else if(s[i]=='e'&&s[i-1]=='s'&&s[i-2]=='a'&&s[i-3]=='r'&&s[i-4]=='e')i-=5;
			else if(s[i]=='r'&&s[i-1]=='e'&&s[i-2]=='m'&&s[i-3]=='a'&&s[i-4]=='e'&&s[i-5]=='r'&&s[i-6]=='d')i-=7;
			else if(s[i]=='r'&&s[i-1]=='e'&&s[i-2]=='s'&&s[i-3]=='a'&&s[i-4]=='r'&&s[i-5]=='e')i-=6;
			else break;
		}
		//printf("%d",length_s);
		if(i<=0)puts("YES");
		else puts("NO");

		return 0;
}
