#include<stdio.h>
int main(){
  char s[2];
  int i,count,j;
  scanf("%s",&s);
  for(i=0;i<=2;i++){
  if(s[i]=='a' || s[i]=='b' || s[i]=='c'){
    for(j=i-1;j>=0;j--){
      if(s[j]!=s[i])
  count++;
    }} }
  if(count==3)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
