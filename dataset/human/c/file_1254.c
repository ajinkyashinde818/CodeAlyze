#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
const int inf = 1000000000; // 10^9
int com_desc_str(const void* a,const void* b){
   char *x=(char*)a,*y=(char*)b;
   return strcmp(y,x);
} 
int com_dic_str(const void* a,const void* b){
   char *x=(char*)a,*y=(char*)b;
   return strcmp(x,y);
} 
int main(){
   char s[101],t[101];scanf("%s %s",s,t);
   qsort(t,strlen(t),sizeof(char),com_desc_str);
   qsort(s,strlen(s),sizeof(char),com_dic_str);
   //printf("%s %s\n",s,t);
   if(strcmp(s,t)<0)printf("Yes");
   else printf("No");
   /*for(int i = 0;i < MAX(strlen(s),strlen(t));i++){
      if(s[i]<t[i]){
         printf("Yes");
         return 0;
      }else if(s[i]>t[i]){
         printf("No");
         return 0;
      }
      if(i >= strlen(s)&&strlen(s)<strlen(t)){
         printf("Yes");
         return 0;
      }
   }*/
}
