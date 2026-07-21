#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//abc158D
int main(void) {

  int q, i, ti, fi, inv=0, top=0, head=0, tail=0;
  //inv=1:反転、top=0:先頭追加
  char t, text[100000];
  scanf(" %s %d", text, &q);

  for(i=0; text[i] != '\0'; ++i)
    ; //textの文字数
  int txln=i;

  char str[2 * q + txln + 2];

  for(i=0; i < sizeof str / sizeof str[0]; i++){
    if(i > q && i <= q + txln) str[i]=text[i - q - 1];
    else str[i]=0;
  }
  head=q, tail=q + txln + 1;

  for(i=0; i < q; i++){
    scanf(" %d", &ti);
    if(ti == 1) inv=!inv;
    else{
      scanf(" %d", &fi);
      if(fi == 1) top=0;
      else top=1;

      scanf(" %c", &t);
      if(inv + top == 0 || inv + top == 2) str[head--]=t;
      else str[tail++]=t;
    }
  }
  if(inv == 0){
    for(i=head + 1; i < tail; i++)
      printf("%c", str[i]);
  }else{
    for(i=tail - 1; i > head; i--)
      printf("%c", str[i]);
  }
}
