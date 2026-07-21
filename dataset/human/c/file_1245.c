#include<stdio.h>
 
int main()
{
  int i=0,j=0,s_max=0,t_max=0;
  int s_baketu[26]={0};
  int t_baketu[26]={0};
  char s[200]={0},t[200]={0};
/*
  for(i=0;i<100;i++)printf("%d ",s[i]);
  printf("\n");
  for(i=0;i<100;i++)printf("%d ",t[i]);
  printf("\n");
*/  
  scanf("%s",s);
  scanf("%s",t);
/*  
  for(i=0;i<100;i++)printf("%d ",s[i]);
  printf("\n");
  for(i=0;i<100;i++)printf("%d ",t[i]);
  printf("\n");
*/
  for(i=0;i<200;i++){
    if(s[i]!=0)s_baketu[s[i]-97]++;
  } 
  for(i=0;i<26;i++){
    while(s_baketu[i]>0){
      s[s_max]=i;
      s_baketu[i]--;
      s_max++;
    }      
  }
  
  for(i=0;i<200;i++){
    if(t[i]!=0)t_baketu[t[i]-97]++;
  }
    for(i=25;i>=0;i--){
    while(t_baketu[i]>0){
      t[t_max]=i;
      t_baketu[i]--;
      t_max++;
    }      
  }
/*  
  for(i=0;i<26;i++)printf("%d ",s[i]);
  printf("\n");
  for(i=0;i<26;i++)printf("%d ",t[i]);
  printf("\n");
*/ 
  for(i=0;i<200&&j==0;i++){
    if(s[i]<t[i])j=1;
    if(s[i]>t[i]&&j==0){
     printf("No");
     return 0;
   }
  }
  if (j==1)printf("Yes");
  else if(j==0)printf("No");
  return 0;
}
