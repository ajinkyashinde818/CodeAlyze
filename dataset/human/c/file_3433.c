#include <stdio.h>
#include <string.h>
int main(){
  char s[100001];
  int f=0;
  scanf("%s",&s);
  for(int i=strlen(s)-1;i>0;i--){
    if(s[i]=='m'){//dream
      if(s[i--]=='m'&&s[i--]=='a'&&s[i--]=='e'&&s[i--]=='r'&&s[i]=='d')f=1;  
      else f=0;
     }
    else if(s[i]=='e'){//erase
      if(s[i--]=='e'&&s[i--]=='s'&&s[i--]=='a'&&s[i--]=='r'&&s[i]=='e')f=1; 
      else f=0;
     }
    else if(s[i]=='r'&&s[i-5]=='e'){//eraser 
      if(s[i--]=='r'&&s[i--]=='e'&&s[i--]=='s'&&s[i--]=='a'&&s[i--]=='r'&&s[i]=='e') f=1;
      else f=0;
      }
    else if(s[i]=='r'&&s[i-6]=='d'){//dreamer
      if(s[i--]=='r'&&s[i--]=='e'&&s[i--]=='m'&&s[i--]=='a'&&s[i--]=='e'&&s[i--]=='r'&&s[i]=='d') f=1;
      else f=0;
      }
    if(f==0) break;
  }
 if(f==1) printf("YES\n");
 else printf("NO\n");
 return 0;
}
