#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define BUF_SIZE 510000+50

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

int get_int3(int *a1, int *a2, char *a3) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %c", a1, a2, a3);
#else
#error
#endif
  return 0;
}

#define OFFSET 210000

enum COMMAND {
    NONE,
    REVERSE,
    ADD,
};

enum {
    UNDEF,
    HEAD,
    TAIL
};

int main(void) {
    static char buf[BUF_SIZE];
    get_str(&buf[OFFSET], BUF_SIZE-OFFSET);
    char *s = &buf[OFFSET];
    size_t len = strlen(s) - 1;
    int pos[3];
    int inc[3] = {0, -1, +1};
    pos[1] = OFFSET-1;
    pos[2] = OFFSET+len;

    int queries = get_int();
    int i;
    int dist = 1;
    for(i = 0; i < queries; i++) {
        int type, where; char ch;
        int idx;
        get_int3(&type, &where, &ch);
        where = (where == 1) ? 1 : -1;
        switch(type) {
            case REVERSE:
                dist = -dist;
                break;
            case ADD:
                idx = (where*dist==1) ? HEAD : TAIL;
                buf[pos[idx]] = ch;
                len++;
                pos[idx] += inc[idx];
                break;
            default:
                break;
        }
#ifdef DEBUG
        printf("%s\n", &buf[pos[1]+1]);
        printf("[%d] dist:%d -> len: %lu (%d, %d)\n", type, dist, len, pos[1], pos[2]);
#endif
    }
//     int start = (dist==1) ? pos[1]+1 : pos[2]-1;
// #ifdef DEBUG
//     printf("start: %d\n", start);
// #endif
//     for(i = start; i > start-len && i < start+len; i=i+(dist)) {
//         putchar(buf[i]);
//     }
//     putchar('\n');
    if(dist==1) {
        int start = pos[1]+1;
        for(i = start; (i < (start+len)); i=i+dist) {
            putchar(buf[i]);
        }
    } else {
        int start = pos[2]-1;
        for(i = start; (i > (start-len)); i=i+dist) {
            putchar(buf[i]);
        }
    }
    putchar('\n');
    return 0;
}
