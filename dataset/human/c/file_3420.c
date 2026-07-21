#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

int main(){
  char key1[6] = "maerd";
  char key2[8] = "remaerd";
  char key3[6] = "esare";
  char key4[7] = "resare";
  char s[100007];
  int n,i,j,flag;
  char t;

  scanf("%s", s);

  n = strlen(s);
  for(i = 0,j = n - 1;i < n/2;i++,j--){
    t = s[i]; s[i] = s[j]; s[j] = t;
  }

  i = 0; flag = 0;
  while(s[i] != '\0'){
    if(s[i] == 'm'){
      if(strncmp(s + i,key1,5) != 0){
        flag = 1;
        break;
      }

      else i = i + 5;
    }

    else if(s[i] == 'e'){
      if(strncmp(s + i,key3,5) != 0){
        flag = 1;
        break;
      }

      else i = i + 5;
    }

    else if(s[i] == 'r'){
      if(s[i + 2] == 'm'){
        if(strncmp(s + i,key2,7) != 0){
          flag = 1;
          break;
        }

        else i = i + 7;
      }

      else if(s[i + 2] == 's'){
        if(strncmp(s + i,key4,6) != 0){
          flag = 1;
          break;
        }

        else i = i + 6;
      }

      else{
        flag = 1;
        break;
      }
    }

    else{
      flag = 1;
      break;
    }
  }

  if(flag) printf("NO\n");

  else printf("YES\n");

  return 0;
}
