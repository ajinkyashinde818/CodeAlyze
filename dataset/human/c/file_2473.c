#include<stdio.h>

int main(){
		char s[3];
		scanf("%s",s);
		int i,a=0,b=0,c=0;
		for(i=0;i<3;i++){
				if(s[i]=='a')a++;
				if(s[i]=='b')b++;
				if(s[i]=='c')c++;
		}
		if(a==1&&b==1&&c==1)puts("Yes");
		else puts("No");

		return 0;
}
