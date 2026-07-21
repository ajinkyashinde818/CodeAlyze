#include<stdio.h>
int main()
{
  int	an;
  char s[3];
  
  scanf("%s", s);
  for(int i=0;i<3;i++){
  	if(s[i]=='a') an+=1;
  	if(s[i]=='b') an+=2;
  	if(s[i]=='c') an+=3;
  }
  
  if(an==6) printf("Yes");
  else printf("No");
  
  return 0;
}
