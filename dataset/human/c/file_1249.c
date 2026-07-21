/*
strcmp(s, t)の戻り値は、s>tのときに正。
*/
/*s<tとなる確率が高いのはsを昇順、tを降順に
ソートしたときが忘れがち*/

#include<stdio.h>
#include<string.h>

void norSort(char *p);
void revSort(char *p);


int main(void)
{
  char s[100+1] = {0};
  char t[100+1] = {0};

  scanf("%s", s); scanf("%s", t);
  norSort(s);
  revSort(t);
  if(strcmp(s, t) < 0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  return 0;
}

void norSort(char *p)
{
  int i,j;
  char buffer = 0;
  for(i=0; i<strlen(p)-1; i++){
    for(j=i+1; j<strlen(p); j++){
      if(p[i] > p[j]){
        buffer = p[i];
        p[i] = p[j];
        p[j] = buffer;
      }
    }
  }
  return ;
}

void revSort(char *p)
{
  int i,j;
  char buffer = 0;
  for(i=0; i<strlen(p)-1; i++){
    for(j=i+1; j<strlen(p); j++){
      if(p[i] < p[j]){
        buffer = p[i];
        p[i] = p[j];
        p[j] = buffer;
      }
    }
  }
  return ;
}
