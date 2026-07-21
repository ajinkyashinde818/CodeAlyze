#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* string, int len) {
  int half = len/2;
  int i;
  for(i=0; i<half; i++) {
    char temp;
    temp = string[i];
    string[i] = string[len-1-i];
    string[len-1-i] = temp;
  }
}

void make_string(char* string, char* half_left, char* half_right, int len_left, int len_right, int flag) {
  if(flag == -1) {
    reverse(half_right, len_right);
    printf("%s%s", half_right, half_left);
  } else {
    reverse(half_left, len_left);
    printf("%s%s", half_left, half_right);
  }
}

int main(void) {
  char s[100001];
  char half_left[200001];
  char half_right[300001];
  char str_q[7];
  int q;
  int i, flag;
  int len_left, len_right;
  char str_query[6];
  char query;
  len_left = len_right = 0;
  
  scanf("%s", half_right);
  len_right += strlen(half_right);
  scanf("%s", str_q);
  q = atoi(str_q);
  flag=1;
  
  for(i=0; i<q; i++) {
    scanf("%s", str_query);
    if(str_query[0] == '1') {
      flag *= -1;
    } else {
      scanf("%s", str_query);
      if((str_query[0] == '1' && flag==1) || (str_query[0] == '2' && flag == -1)) {
        scanf("%s", str_query);
        half_left[len_left] = str_query[0];
        len_left += 1;
      } else {
        scanf("%s", str_query);
        half_right[len_right] = str_query[0];
        len_right += 1;
      }
    }
  }
  
  make_string(s, half_left, half_right, len_left, len_right, flag);
  return 0;
}
