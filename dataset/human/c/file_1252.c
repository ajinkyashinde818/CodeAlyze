#include<stdio.h>
void quicksort(char a[],int s,int t){
  if(s<t){
    int i=s,j=t;
    char p=a[(s+t)/2];
    while(1){
      while(a[i]<p)i++;
      while(p<a[j])j--;
      if(i>=j)break;
      a[i]^=a[j]^=a[i]^=a[j];
      i++;j--;
    }
    quicksort(a,s,i-1);quicksort(a,j+1,t);
  }
}

int main(){
  char s[101],t[101];
  int i,x,y;
  scanf("%s%s",s,t);
  for(x=0;s[x];x++);for(y=0;t[y];y++);
  quicksort(s,0,x-1);quicksort(t,0,y-1);
  for(i=0;i<y/2;i++)t[i]^=t[y-i-1]^=t[i]^=t[y-i-1];
  for(i=0;i<y;i++){if(s[i]<t[i]){printf("Yes");return 0;}if(s[i]>t[i]){printf("No");return 0;}}
  printf("No");
}
