#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void get_intint(char *line, int size, int *a1, int *a2) {
  if(!fgets(line, size, stdin)) return;
  sscanf(line, "%d %d", a1, a2);
}

#define BUF_SIZE 20


struct problem {
  int point;
  int bonus;
  int cnt;
  int sum;
};

int solve_min(struct problem* probs, int grades, int goal) {
  int mincnt = INT_MAX;
  int i, j;
  for(i = 0; i < (1<<grades); i++) {
    int sum = 0;
    int tmpcnt = 0;
    // get bonus
    for(j = 0; j < grades; j++) {
      int flag = !!(i & (1<<j));
      tmpcnt += probs[j].cnt*flag;
      sum += probs[j].sum*flag;
    }
    if(tmpcnt > mincnt) continue; // skip
    if(sum >= goal) {
      mincnt = tmpcnt;
      continue;
    }
    // append reminder
    for(j = grades-1; j >= 0; j--) {
      int flag = !!(i & (1<<j));
      if(flag) continue; // it would get bonus twice
      int rem = (goal-sum+probs[j].point-1) / probs[j].point;
      if(rem >= probs[j].cnt) continue;
      tmpcnt += rem;
      if(mincnt > tmpcnt) mincnt = tmpcnt;
      break;
    }
  }
  return mincnt;
}

int main(void) {
  int grade, total_score;
  char line[BUF_SIZE];
  get_intint(line, BUF_SIZE, &grade, &total_score);

  struct problem probs[10];

  int i, j;
  int max_cnt = 0;
  for(i = 0; i < grade; i++) {
    int cnt, bonus;
    get_intint(line, BUF_SIZE, &cnt, &bonus);
    probs[i].cnt = cnt;
    probs[i].bonus = bonus;
    probs[i].point = (i+1)*100;
    probs[i].sum = probs[i].point * probs[i].cnt + bonus;
    max_cnt += probs[i].cnt;
  }

  int res = solve_min(probs, grade, total_score);
  printf("%d\n", res);
}
