#include <stdio.h>

int main(){
   char s[300000],c,r[300001];
   int q,i,j,mp,ap,np,d,f,t,next[300000];
 
   scanf("%s",s);
   for (i=0;s[i]!='\0';i++) next[i]=i+1;
   mp=0;ap=i-1;np=i;
   scanf("%d",&q);
   d=1;
   for (i=0;i<q;i++) {
      scanf("%d",&t);
      if (t==1)
         d=3-d;
      else {
         scanf("%d %c",&f,&c);
         s[np]=c;
         if (f==1 && d==1) {
            next[np]=mp;
            mp=np;
         } else if (f==2 && d==1){
            next[ap]=np;
            ap=np;
         } else if (f==1 && d==2){
            next[ap]=np;
            ap=np;
         } else {
            next[np]=mp;
            mp=np;
         }
         np++;
      }
   }
   if (d==1) {
      for (i=mp;i!=ap;i=next[i]) printf("%c",s[i]);
      printf("%c",s[i]);
   } else {
      j=np-1;
      for (i=mp;i!=ap;i=next[i]) r[j--]=s[i];
      r[0]=s[i];
      r[np]='\0';
      printf("%s",r);
   }
   puts("");
   return 0;
}
