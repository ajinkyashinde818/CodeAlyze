#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
    char s[100000];
    int head = 0;
    int tail;
    int counter_left=0;
    int counter_right=0;
    int counter_operate=0;
    int length = 0;
    scanf("%s",&s);
    length = strlen(s);
    tail = length-1;
    if (tail==head){
        printf("%d\n",0);
        return 0;
    }
    while(tail!=head){

        while(s[head]=='x'){
            counter_left +=1;
            head+=1;
        }
        while(s[tail]=='x'){
            counter_right+=1;
            tail-=1;
        }
        if(head<=tail){
            counter_operate+=abs(counter_left-counter_right);
            counter_left=0;
            counter_right=0;
        }
        if (s[head]!=s[tail]){
            printf("%d\n",-1);
            return 0;
        }
        else{
            tail-=1;
            head+=1;
        }
        if (head>=tail){
            printf("%d\n",counter_operate);
            return 0;
        }
    }
    return 0;
}
