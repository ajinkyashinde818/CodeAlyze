#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i, j, k, n, m, x;
    int **skills, *costs;
    int beki = 1;
    int mincost = 0;
    int cost, skill_lv, lv_shortage_flag, suc_flag=0;
    scanf("%d %d %d", &n, &m, &x);

    costs = (int*)malloc(sizeof(int) * n);
    skills = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        skills[i] = (int*)malloc(sizeof(int) * m);
    }

    for(i = 0; i < n; i++) {
        scanf("%d", &costs[i]);
        mincost += costs[i];
        for(j = 0; j < m; j++) {
            scanf("%d", &skills[i][j]);
        }
    }
    
    for(i = 0; i < n; i++) {
        beki *= 2;
        mincost += costs[i];
    }
    for(i = 0; i < beki; i++) {
        lv_shortage_flag = 0;
        cost = 0;
        for(k = 0; k < n; k++) {
            if((i >> k) % 2) cost += costs[k];
        }
        if(cost > mincost) continue;

        for(j = 0; j < m; j++) {
            skill_lv = 0;
            for(k = 0; k < n; k++) {
                if((i >> k) % 2) skill_lv += skills[k][j];
            }
            if(skill_lv < x) {
                lv_shortage_flag = 1;
                break;
            }
        }
        if(!lv_shortage_flag) {
            mincost = cost;
            suc_flag = 1;
        }
    }

    if(!suc_flag) printf("-1\n");
    else printf("%d\n", mincost);
    return 0;
}
