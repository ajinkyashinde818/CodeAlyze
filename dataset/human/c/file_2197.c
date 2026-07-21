#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
  char str[300002];
  int q,x,total=0,f,r=0,l=0;
  scanf("%s",str);
  scanf("%d",&q);
  char left[q],right[q];
  for(int i=0;i<q;i++){
    scanf("%d",&x);
    if(x==1) total++;
    else if(x==2){
      char tmp,tmp1;
      scanf("%d",&f);
      scanf("%c",&tmp1);
      scanf("%c",&tmp);
      //scanf("%c",&tmp1);
      //printf("%c\n",tmp);
      if(total%2==0){
        if(f==1){
          left[l]=tmp;
          l++;
        }else if(f==2){
          right[r]=tmp;
          r++;
        }
      }else if(total%2==1){
        if(f==1){
          right[r]=tmp;
          r++;
        }else if(f==2){
          left[l]=tmp;
          l++;
        }
      }//iftotal
    }//ifx
    //printf("%d\n",total);
  }//for
  int len;
  len=strlen(str);
  
  if(total%2==0){
    for(int i=l-1;i>=0;i--) printf("%c",left[i]);
    for(int i=0;i<len;i++) printf("%c",str[i]);
    for(int i=0;i<r;i++) printf("%c",right[i]);
  }else if(total%2==1){
    for(int i=r-1;i>=0;i--) printf("%c",right[i]);
    for(int i=len-1;i>=0;i--) printf("%c",str[i]);
    for(int i=0;i<l;i++) printf("%c",left[i]);
  }
    
  //for(int i=0;i<q;i++) printf("%c",right[i]);
  //printf("%d",f);
  return 0;
}
