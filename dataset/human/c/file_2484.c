#include<stdio.h>
int main(){
  	int count=0;
	char s[3];
  	scanf("%s",s);
  	if(s[0]=='a'||s[1]=='a'||s[2]=='a') count++;
  	if(s[0]=='b'||s[1]=='b'||s[2]=='b') count++;
  	if(s[0]=='c'||s[1]=='c'||s[2]=='c') count++;
  	if(count==3) printf("Yes\n");
  	else printf("No\n");
	return 0;
}
