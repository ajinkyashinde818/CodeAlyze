#include <stdio.h>

int main(void){
    static char str[100001];
    unsigned long long int count = 1;
    int len;//文字列の長さ
    int i;
    
    unsigned int bucket[26] = {0};
    
    scanf("%d", &len);
    scanf("%s", str);
    
    for(i = 0; i < len; i++){
        bucket[str[i] - 'a']++;
    }
    
    for(i = 0; i < 26; i++){
        if(bucket[i]){
            count *= (bucket[i] + 1);
        }
        
        if(count > 1000000007){
            count  %= 1000000007;
        }
    }
    
    printf("%llu\n", (count-1) % 1000000007);
    
    return 0;
}
