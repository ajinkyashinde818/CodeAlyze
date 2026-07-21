#include <stdio.h>
#include <string.h>

int main(void){
    char s[101];
    char t[101];
    scanf("%s",s);
    scanf("%s",t);
    char min_s='z', max_t='a';
    int cnt_min_s = 0, cnt_max_t=0;
    
    for(int i = 0; i < strlen(s); i++){
        if(s[i] < min_s){
            min_s = s[i];
            cnt_min_s = 1;
        }else if(s[i] == min_s){
            cnt_min_s++;
        }
    }    
    
    for(int i = 0; i < strlen(t); i++){
        if(t[i] > max_t){
            max_t = t[i];
            cnt_max_t = 1;
        }else if(t[i] == max_t){
            cnt_max_t++;
        }
    }
    //printf("cnt_max_t=%d, cnt_min_s=%d",cnt_max_t,cnt_min_s);
    if(max_t < min_s || 
      (max_t == min_s && cnt_max_t <= cnt_min_s) ||
      (max_t == min_s && cnt_max_t > cnt_min_s && strlen(s) > cnt_min_s )) puts("No");
    else puts("Yes");
}
