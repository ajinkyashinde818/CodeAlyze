#include <stdio.h>
#include <string.h>

typedef struct {
    int tx, ty;
    int power;
    int time;
} CHEESE;

CHEESE queue[400000];
int head, tail;

void enq(CHEESE t)
{
    queue[tail % 400000] = t;
    tail++;
}

void deq(CHEESE *t)
{
    *t = queue[head % 400000];
    head++;
}

int main(void)
{
    CHEESE first, temp;
    int x, y, ch;
    int i, j;
    static char map[1001][10001];
    static char v[1001][1001];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    scanf("%d%d%d", &y, &x, &ch);
    getchar();
    
    for (i = 0; i < y; i++){
        for (j = 0; j < x; j++){
            scanf("%c", &map[i][j]);
            if (map[i][j] == 'S'){
                first.tx = j;
                first.ty = i;
            }
        }
        getchar();
    }
    
    first.time = 0;
    first.power = 1;
    v[first.ty][first.tx] = 1;
    memset(v, 0, sizeof(v));
    head = tail = 0;
    enq(first);
    
    while (head != tail){
        deq(&temp);
        
        if (temp.power == ch + 1){
            printf("%d\n", temp.time);
            break;
        }
        
        for (i = 0; i < 4; i++){
            first = temp;
            first.tx = temp.tx + dx[i];
            first.ty = temp.ty + dy[i];
            first.time = temp.time + 1;
            if (0 <= first.tx && first.tx < x && 0 <= first.ty && first.ty < y && !v[first.ty][first.tx] && map[first.ty][first.tx] != 'X'){
                v[first.ty][first.tx] = 1;
                if (map[first.ty][first.tx] == '.' || map[first.ty][first.tx] - '0' != temp.power){
                    enq(first);
                }
                else {
                    first.power = temp.power + 1;
                    memset(v, 0, sizeof(v));
                    v[first.ty][first.tx] = 1;
                    head = tail = 0;
                    enq(first);
                    break;
                }
            }
        }
    }
    
    return (0);
}
