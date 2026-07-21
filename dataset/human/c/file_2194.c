#include <stdio.h>
#include <string.h>
 
void revstr(char* str){
  int size=strlen(str);
  int i,j;
  char tmp;
	
	for(i = 0,j = size - 1; i < size / 2; i++, j--){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}
 
int main()
{
  int rev=0;
  int posi_judge;
  int do_judge;
  char main[100000];
  char pre[300000];
  char suf[300000];
  char tmp[2];
  int Q;
  int suf_cnt=0;
  int pre_cnt=0;
  
  scanf("%s",main);
  scanf("%d",&Q);
  for(int i=0;i<Q;i++)
  {
    scanf("%d",&do_judge);
    if (do_judge==1)
    {
      rev++;
    }
    else
    {
      scanf("%d %s",&posi_judge,tmp);
      if ((posi_judge==1 && rev%2==1)||(posi_judge==2 && rev%2==0))
        suf[suf_cnt++]=tmp[0];
      else
        pre[pre_cnt++]=tmp[0];
        
    }
}
  if(rev%2==0)
  {
    revstr(pre);
    printf("%s%s%s",pre,main,suf);
  }
  else
  {
    revstr(main);
    revstr(suf);
    printf("%s%s%s",suf,main,pre);
  }
}
