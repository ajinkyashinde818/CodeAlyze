#include<stdio.h>
#include<string.h>
int main(){
  char s[100000];
  int i,a;
  scanf("%s",s);
  a=strlen(s);
  if(s[0]!='d'&&s[0]!='e'){
    printf("NO\n");
    return 0;
  }
  for(i=1;i<a;i++){
    switch(s[i]){
      case 'd': if(s[i-1]=='m' || s[i-1]=='r'&& s[i-2]=='e' &&(s[i-3]=='m' ||s[i-3]=='s')
                  || s[i-1]=='e'){
                    // printf("d");
                    break;
                  }
                  else{
                     printf("NO\n"); return 0;
                  }
      case 'r': if(s[i-1]=='d' || s[i-1]=='e'){
                  // printf("r");
                  break;
                }
                else{
                  printf("NO\n"); return 0;
                }
      case 'e': if(s[i-1]=='m'||s[i-1]=='r'&&(s[i-2]=='d'||s[i-2]=='e'&&(s[i-3]=='m'||s[i-3]=='s'))
                  || (s[i-1]=='e'&&s[i-2]=='s') ||s[i-1]=='s'){
                    // printf("e");
                    break;

                  }
                  else{
                    printf("NO\n"); return 0;
                  }
      case 'a': if(s[i-1]=='e' &&s[i-2]=='r' ||s[i-1]=='r'&&s[i-2]=='e'){
                  // printf("a");
                  break;
                }
                else{
                  printf("NO\n"); return 0;
                }
      case 'm': if(s[i-1]=='a'&&s[i-2]=='e'){
                  // printf("m");
                  break;
                }
                else{
                  printf("NO\n"); return 0;
                }
      case 's':if(s[i-1]=='a' &&s[i-2]=='r'){
                // printf("s");
                break;
              }
              else{
                printf("NO\n"); return 0;
              }
      default: printf("*NO\n"); return 0;
    }
  }
  if(s[a-1]=='m' || s[a-1]=='r'&& s[a-2]=='e' &&(s[a-3]=='m' ||s[a-3]=='s')|| s[a-1]=='e'){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }
  return 0;
}
