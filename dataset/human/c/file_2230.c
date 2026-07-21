#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int compare_int(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main(void)
{
  int i, j;
  char aa[100000+2];
  char aar[200000+2];
  char aal[200000+2];
  memset(aa, '\0', sizeof(aa));
  memset(aar, '\0', sizeof(aar));
  memset(aal, '\0', sizeof(aal));
  int cntaa;
  int cntr=0;
  int cntl=0;
  int min, max;
  int len, flg;
  int cnt, maxcnt;
  char ee;
  int  bb,cc,dd;
  scanf("%s\n", aa);
  cntaa = strlen(aa);
//  printf("%d",cntaa);
  scanf("%d\n", &bb);
  cnt=0;
  for(i=0;i<bb;i++){
    scanf("%d", &cc);
    if(cc == 2){
      scanf("%d %c", &dd,&ee);
      if(dd ==2){
        if((cnt%2) ==0){
          aar[cntr]=ee;
          cntr++;
        }
        else{
          aal[cntl]=ee;
          cntl++;
        }
      }
      else{
        if((cnt%2) ==0){
          aal[cntl]=ee;
          cntl++;
        }
        else{
          aar[cntr]=ee;
          cntr++;
        }
      }
    }
    else{
      cnt++;      
    }
    //    printf("%s %d %d %d %c\n", aa,bb,cc,dd,ee);
  }
  //	printf("aar%s\n",aar);
  //	printf("aal%s\n",aal);
  if((cnt%2) ==0){
    for(i=cntl-1;i>=0;i--){
      printf("%c",aal[i]);
    }
    printf("%s",aa);
    printf("%s\n",aar);
  }
  else{
    for(i=cntr-1;i>=0;i--){
      printf("%c",aar[i]);
    }
    for(i=cntaa-1;i>=0;i--){
      printf("%c",aa[i]);
    }
    printf("%s\n",aal);
  }

  return 0;
}
