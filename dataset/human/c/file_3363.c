#include <stdio.h>
#include <string.h>

#define MAX 100000 // キュー配列の最大サイズ

int qu[MAX]; // キューを表す配列
int tail = 0, head = 0; // キューの要素区間を表す変数

// キューを初期化する
void init() {
    head = tail = 0;
}

// キューが空かどうかを判定する
int isEmpty() {
    return (head == tail);
}

// スタックが満杯かどうかを判定する
int isFull() {
    return (head == (tail + 1) % MAX);
}

// enqueue (tail に要素を格納してインクリメント)
void enqueue(int v) {
    if (isFull()) {
        puts("error: queue is full.");
        return;
    }
    qu[tail++] = v;
    if (tail == MAX) tail = 0; // リングバッファの終端に来たら 0 に
}

// dequeue (head にある要素を返して head をインクリメント)
int dequeue() {
    if (isEmpty()) {
        puts("error: stack is empty.");
        return -1;
    }
    int res = qu[head];
    ++head;
    if (head == MAX) head = 0;
    return res;
}

int is_substr(char s[], char t[], int i){
    int flag = 1;

    if(s[i] == '\0') flag = 0;

    for(int j = 0; j < strlen(t); ++j, ++i){
        if(s[i] != t[j]){
            flag = 0;
            break;
        }
    }

    return flag;
}

int main(){
    char s[100010];
    char t[4][8]={"dream","dreamer","erase","eraser"};

    scanf("%s", s);

    enqueue(0);
    int flag = 0;
    while(!isEmpty()){
        int i = dequeue();
        if(i == strlen(s)){
            flag = 1;
            break;
        }
        for(int j = 0; j < 4; ++j){
            if(is_substr(s, t[j], i) == 1){
                enqueue(i + strlen(t[j]));
            }
        }
    }

    puts(flag ? "YES" : "NO");

    return 0;
}
