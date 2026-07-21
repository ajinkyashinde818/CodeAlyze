#include <stdio.h>

void char_push(char *s, int *len, char inp)
{
   // printf("%d %c\n", *len, inp);
   s[*len] = inp;
   *len = *len + 1;
   s[*len] = '\0';
   return;
}

int main(void)
{
   int Q;
   char S[3 * 100000];
   char S_pre[2 * 100000];
   int T;
   int resF;
   char response;
   int Spre_i=0, Spost_i = 0, arrow = 0;

   scanf("%s", S);
   scanf("%d", &Q);

   for (Spost_i = 0; S[Spost_i] != '\0'; Spost_i++)
   {
   }

   // printf ("%d\n", Spost_i);
   for (int i = 0; i < Q; i++)
   {

      scanf("%d", &T);
      if (T == 1)
      {
         arrow = arrow ^ 1;
      }
      else
      {
         scanf("%d %c", &resF, &response);
         resF = 2 - resF;
         // resF = 0  -> 後ろに
         if ((resF ^ arrow) == 0)
         { char_push(S,&Spost_i, response );}
         else
         { char_push(S_pre, &Spre_i, response);}
         
      }
   }
   if (arrow == 0)
   {
      for (int i = 0; i < Spre_i; i++)
      {
         printf("%c", S_pre[Spre_i -1  - i]);
      }
      printf("%s\n", S);
   }
   else
   {
      for (int i = 0; i < Spost_i; i++)
      {
         printf("%c", S[Spost_i-1 - i]);
      }
      printf("%s\n", S_pre);
   }
   return 0;
}
