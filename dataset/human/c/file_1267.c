#include <stdio.h>

#define CWALL '#'
#define CFLOOR '.'
#define CEXIT 'X'
#define CEAST 'E'
#define CNORTH 'N'
#define CWEST 'W'
#define CSOUTH 'S'

enum direction {
    EAST = 0,
    NORTH,
    WEST,
    SOUTH
};

typedef struct {
    int real;
    int imag;
} complex_t;

void complex_mul(const complex_t *s1, const complex_t *s2, complex_t *t) {
    t->real = s1->real * s2->real - s1->imag * s2->imag;
    t->imag = s1->real * s2->imag + s1->imag * s2->real;
}

void complex_mul_dest(complex_t *t, const complex_t *m) {
    int r = t->real, i = t->imag;
    t->real = r * m->real - i * m->imag;
    t->imag = r * m->imag + i * m->real;
}

const complex_t east = {1, 0};
const complex_t north = {0, -1};
const complex_t west = {-1, 0};
const complex_t south = {0, 1};
const complex_t front = {1, 0};
const complex_t back = {-1, 0};
const complex_t left = {0, -1};
const complex_t right = {0, 1};


// complex_t look_dir[] = {right, front, left, back};
complex_t look_dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const char dir_char[] = {CEAST, CNORTH, CWEST, CSOUTH};

typedef struct {
    char c;
    complex_t direction;
    int x;
    int y;
    int in_maze;
} player_t;

void print_table(char t[][31], int w, int h) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%c", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(void) {
    int W, H, i, j, pid, pcount, s;
    char maze[30][31], cell;
    player_t player[800], *p;

    while (scanf("%d%d\n", &W, &H) == 2 && W && H) {
        pid = 0;
        for (i = 0; i < H; i++) {
            scanf("%s", maze[i]);
            for (j = 0; j < W; j++) {
                cell = maze[i][j];
                if (cell == CEAST || cell == CNORTH || cell == CWEST || cell == CSOUTH) {
                    p = &player[pid++];
                    p->c = cell;
                    p->x = j;
                    p->y = i;
                    p->in_maze = 1;
                    switch (cell) {
                        case CEAST: p->direction = east; break;
                        case CNORTH: p->direction = north; break;
                        case CWEST: p->direction = west; break;
                        case CSOUTH: p->direction = south; break;
                        default: break;
                    }
                }
            }
        }

        pcount = pid;
        for (s = 0; s < 180; s++) {
            player_t *move_queue[4][200];
            player_t *exit_queue[200];
            complex_t dir;
            enum direction pdir;
            int qidx[4] = {};
            int qx;
            char *acell;
            
            // print_table(maze, W, H);
            // look around
            for (i = 0; i < pid; i++) {
                p = &player[i];
                if (!p->in_maze) continue;
                for (j = 0; j < 4; j++) {
                    complex_mul(&(p->direction), &(look_dir[j]), &dir);
                    acell = &maze[p->y + dir.imag][p->x + dir.real];
                    if (*acell == CFLOOR || *acell == CEXIT) {
                        p->direction = dir;
                        pdir = (enum direction)((dir.imag==-1)*1 + (dir.real==-1)*2 + (dir.imag==1)*3);
                        move_queue[(pdir+2)%4][qidx[(pdir+2)%4]++] = p;
                        maze[p->y][p->x] = dir_char[pdir];
                        break;
                    }
                }

            }

            qx = 0;
            for (i = 0; i < 4; i++) {
                for (j = 0; j < qidx[i]; j++) {
                    p = move_queue[i][j];
                    acell = &maze[p->y + p->direction.imag][p->x + p->direction.real];
                    if (*acell == CFLOOR) {
                        *acell = maze[p->y][p->x];
                        maze[p->y][p->x] = CFLOOR;
                        p->x += p->direction.real;
                        p->y += p->direction.imag;
                    }
                    else if (*acell == CEXIT) {
                        *acell = maze[p->y][p->x];
                        maze[p->y][p->x] = CFLOOR;
                        p->in_maze = 0;
                        pcount--;
                        exit_queue[qx++] = p;
                    }
                }
            }

            for (i = 0; i < qx; i++) {
                p = exit_queue[i];
                maze[p->y + p->direction.imag][p->x + p->direction.real] = CEXIT;
            }
            
            if (pcount == 0) break;
        }
        if (s == 180) {
            printf("NA\n");
        }
        else {
            printf("%d\n", s + 1);
        }

    }
    return 0;
}
