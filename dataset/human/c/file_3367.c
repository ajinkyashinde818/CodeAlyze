#include<stdio.h>
#include<string.h>
void rev(char s[]);
void daydream(int i,char str[],int end);

int main(void){
  int i;
  char str[100001];
  fgets(str,100001,stdin);
  int l = strlen(str);
  rev(str);
  
  daydream(0,str,l-1);
  return 0;
}
//make str in a converted way.
void rev(char s[]){
  int i,l=strlen(s);
  for(i=0;i<l/2;i++){
    char tmp = s[i];
    s[i] = s[l-i-1];
    s[l-i-1] = tmp;
  }

}
void daydream(int i,char str[],int end){
  int l,m;
  char T[4][8]={"dream","dreamer","erase","eraser"};
  for(l=0;l<4;l++)rev(T[l]);
  for(m=1;m<end+1;){
    if(strncmp(str+m,T[0],5)==0) m+=5;
    else if(strncmp(str+m,T[1],7)==0) m+=7;
    else if(strncmp(str+m,T[2],5)==0) m+=5;
    else if(strncmp(str+m,T[3],6)==0) m+=6;
    else {
      printf("NO\n");
      break;
    }
    if(m==end+1)printf("YES");
  }
}
