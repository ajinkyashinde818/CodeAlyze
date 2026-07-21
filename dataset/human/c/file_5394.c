#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main (void)
{
    unsigned long n, m, x;
    unsigned long score[12] = {0};
    int book[12] = {0}, ibook[12];
    unsigned long cost[12], a[12][12];
    int i, j;
    unsigned long sum_cost = 0 , sum_score = 0, ans = 0, max;
    int flg_break;

    scanf("%lu %lu %lu", &n, &m, &x);

    for (i = 0; i < n; i++) {
        scanf("%lu", &(cost[i]));
        for (j = 0; j < m; j++) {
            scanf("%lu", &(a[i][j]));
        }
    }

    for (i = 0; i < 12; i++) {
        book[i] = 1;
        ans += cost[i];
    }

    max = ans;
    ans += 1;

    for (ibook[0] = 0; ibook[0] <= book[0]; ibook[0]++) {
        for (ibook[1] = 0; ibook[1] <= book[1]; ibook[1]++) {
            for (ibook[2] = 0; ibook[2] <= book[2]; ibook[2]++) {
                for (ibook[3] = 0; ibook[3] <= book[3]; ibook[3]++) {
                    for (ibook[4] = 0; ibook[4] <= book[4]; ibook[4]++) {
                        for (ibook[5] = 0; ibook[5] <= book[5]; ibook[5]++) {
                            for (ibook[6] = 0; ibook[6] <= book[6]; ibook[6]++) {
                                for (ibook[7] = 0; ibook[7] <= book[7]; ibook[7]++) {
                                    for (ibook[8] = 0; ibook[8] <= book[8]; ibook[8]++) {
                                        for (ibook[9] = 0; ibook[9] <= book[9]; ibook[9]++) {
                                            for (ibook[10] = 0; ibook[10] <= book[10]; ibook[10]++) {
                                                for (ibook[11] = 0; ibook[11] <= book[11]; ibook[11]++) {

                                                    for (i = 0; i < m; i++) {
                                                        sum_score = 0;
                                                        for (j = 0; j < n; j++) {
                                                            sum_score += a[j][i] * ibook[j];
                                                        }
                                                        if (sum_score < x) {
                                                            flg_break = 1;
                                                            break;
                                                        } else {
                                                            flg_break = 0;
                                                        }
                                                    }

                                                    if (flg_break) continue;

                                                    sum_cost = 0;
                                                    for (i = 0; i < n; i++) {
                                                        sum_cost += cost[i] * ibook[i];
                                                    }

                                                    if (sum_cost < ans) ans = sum_cost;

                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (ans == max + 1) {
        puts("-1");
    } else {
        printf("%lu", ans);
    }

    return 0;
}
