#include<stdio.h>
int main(void){
  int i,ans=0;
	char s[4];
	scanf("%s",s);


	if(s[0]=='a'&&s[1]=='b'&&s[2]=='c'){
    ans=1;
  }
  else if(s[0]=='a'&&s[1]=='c'&&s[2]=='b'){
    ans=1;
  }
  else if(s[0]=='b'&&s[1]=='a'&&s[2]=='c'){
    ans=1;
  }
  else if(s[0]=='b'&&s[1]=='c'&&s[2]=='a'){
    ans=1;
  }
  else if(s[0]=='c'&&s[1]=='b'&&s[2]=='a'){
    ans=1;
  }
  else if(s[0]=='c'&&s[1]=='a'&&s[2]=='b'){
    ans=1;
  }

  if(ans==1){
    printf("Yes\n");
  }
	else {
    printf("No\n");
  }

	return 0;
}
