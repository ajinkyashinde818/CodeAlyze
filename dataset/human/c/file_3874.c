#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    if (*(int*)a > *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}

int ascending_compare(const void *a, const void *b){
    if (*(int*)a < *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}

// array pointer = *a, num of element = n, key key
int lower_bound(int *a, int n, int key){
    int ng, mid, ok;
    ng = -1, ok = n-1;
    while (abs(ok - ng) > 1){
        mid = (ok + ng) / 2;
        if (key <= a[mid]){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    if (a[ok] >= key)return ok;
    return n;
}

//greatest common divisor
unsigned long gcd(unsigned long x, unsigned long y){
    if (y == 0){ 
        return x;
    }else if (x > y){
        return gcd(y, x % y);
    }else{
        return gcd(x, y % x);
    }
}

unsigned long lcm(unsigned long x, unsigned long y){
    unsigned long g = gcd(x, y);
    return x*y/g;

}



long long factorial(int x){
    long long rtn = 1;
    int i;
    for (i = x; i > 1; i--){
        rtn = (rtn*i);
    }
    return rtn;
}




/*unsigned long long pascal[100][100] = {0};
void make_pascal(void){
    for (int i = 0; i < 100; i++){
        pascal[i][0] = 1;
    }
    pascal[1][1] = 1;
    for (int i = 2; i < 100; i++){
        for (int j = 1; j < 100; j++){
           pascal[i][j] = (pascal[i-1][j-1]+pascal[i-1][j]) % mod;
        }
    }
}*/
long long mod = 1000000007;

//x ^ n
long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

typedef struct{
    int uTrain;
    int uRoad;
    int town;
} vertex;

int n, k, l;
int head_train[200005];
int head_road[200005];
int to_train[200005];
int to_road[200005];
int next_train[200005];
int next_road[200005];
vertex v[200005];
int uT_num = 0;
int uR_num = 0;
int stack[200005];
int top;
int ans[200005];

int train_dfs(int crt){
    int edge = head_train[crt];
    while (edge != -1){
        if (v[to_train[edge]].uTrain == -1){
            v[to_train[edge]].uTrain = uT_num;
            train_dfs(to_train[edge]);
        }
        edge = next_train[edge];
    }
    return 0;
}

int road_dfs(int crt){
    int edge = head_road[crt];
    while (edge != -1){
        if (v[to_road[edge]].uRoad == -1){
            v[to_road[edge]].uRoad = uR_num;
            road_dfs(to_road[edge]);
        }
        edge = next_road[edge];
    }
    return 0;
}
int struct_ascending_compare(const void *p, const void *q) {
if (((vertex*)p)->uTrain - ((vertex*)q)->uTrain == 0){
    return ((vertex*)p)->uRoad - ((vertex*)q)->uRoad;
}
return ((vertex*)p)->uTrain - ((vertex*)q)->uTrain;
}


int main(void){
    scanf("%d %d %d", &n, &k, &l);
    int p, q;
    for (int i = 1; i <= n; i++){
        v[i].town = i;
        v[i].uTrain = -1;
        v[i].uRoad = -1;
        head_train[i] = -1;
        head_road[i] = -1;
    }
    for (int i = 0; i < k*2; i += 2){
        scanf("%d %d", &p, &q);
        next_road[i] = head_road[p];
        head_road[p] = i;
        to_road[i] = q;

        next_road[i+1] = head_road[q];
        head_road[q] = i+1;
        to_road[i+1] = p;
    }

    for (int i = 0; i < l*2; i += 2){
        scanf("%d %d", &p, &q);
        next_train[i] = head_train[p];
        head_train[p] = i;
        to_train[i] = q;

        next_train[i+1] = head_train[q];
        head_train[q] = i+1;
        to_train[i+1] = p;
    }

    for (int i = 1; i <= n; i++){
        if (v[i].uTrain == -1){
            uT_num++;
            v[i].uTrain = uT_num;
            train_dfs(i);
        }
        if (v[i].uRoad == -1){
            uR_num++;
            v[i].uRoad = uR_num;
            road_dfs(i);
        }
    }



    qsort(v, n+1, sizeof(vertex), struct_ascending_compare);


    int cnt = 0;
    v[n+1].uRoad = -1;
    for (int i = 1; i <= n+1; i++){
        if (i != 1 && (v[i].uTrain != v[i-1].uTrain || v[i].uRoad != v[i-1].uRoad)){
            for (int i = 0; i < top; i++){
                ans[stack[i]] = cnt;
            }
            cnt = 0;
            top = 0;
        }

        stack[top] = v[i].town;
        top++;
        cnt++;
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", ans[i]);
    }

}
