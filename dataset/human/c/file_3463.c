#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int a[200001];
int rocker[200001];
int rocker_no[200001];
bool rocker_judge[200001];

int main()
{
    int n, d, c, j, r_num;
    long long k;
    
    scanf("%d %lld", &n, &k);

    for (int i = 1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        rocker_judge[i] = true;
    }

    c = 1;
    j = 1;

    for (;rocker_judge[c] == true; j++)
    {
        rocker_judge[c] = false;
        rocker_no[c] = j;
        rocker[j] = c;
        c = a[c];
    }

    r_num = j - rocker_no[c]; 

    if ((k+1) <= rocker_no[c]){
        d = rocker[k+1];
    } else {
        d = rocker[((k - (rocker_no[c] - 1))%r_num) + rocker_no[c]];
    }

    printf("%d", d);

    return 0;
}
