#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define rep(i, n) for(i=0;i<(int)(n);i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define bit(n) (1LL<<(n))
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void rev_string(char str[])
{
    int i;
    int len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main(void){
  char s[500001];
  int f[200001];
  char c[200001]={'\0'};
  int rev[200001];
  int q,i,j,revMode=0,start=250000,len=0;
  
  scanf("%s", &s[start]);
  scanf("%d", &q);
  len = strlen(&s[start]);
  for(i=0;i<q;i++){
    scanf("%d", &j);
    switch(j){
      case 1:
        revMode += 1;
        revMode %= 2;
        break;
      case 2:
        scanf("%d %c", &f[i], &c[i]);
        if(revMode == 1){
          f[i] %= 2;
          f[i] += 1;//hanten
        }
        if(f[i] == 1){
          //atama
          f[i] = start-1;
          start--;
        }else{
          //ketsu
          f[i] = start+len;
        }
        len++;
        
        break;
    }
  }
  for(i=0;i<q;i++){
    //create string
    s[f[i]] = c[i];
  }
  if(revMode == 0) printf("%s", &s[start]);
  else{
    //printf("%s", &s[start]);
    for(i=start+strlen(&s[start])-1;i>=start;i--){
      printf("%c", s[i]);
    }
  }
  
  return 0;
}
