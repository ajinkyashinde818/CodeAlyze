#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    if (*(long long*)a > *(long long*)b){
        return -1;
    }else if (*(long long*)a == *(long long*)b){
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


int lower_bound(int *a, int n, int key){
    int left, mid, right;
    left = 0, right = n;
    mid = (left + right)/2;
    while ((left+1 != mid || mid+1 != right) && mid != left){
        if (key > a[mid]){
            left = mid;
        }else{
            right = mid+1;
        }
        mid = (left + right)/2;
    }
    if (a[left] >= key)return left;
    if (a[mid] >= key)return mid;
    if (a[right] >= key)return right;
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
typedef struct{
    int node;
    int Rv;
    int Tv;
} pair;


int struct_ascending_compare(const void *p, const void *q) {
    if (((pair*)q)->Rv - ((pair*)p)->Rv != 0){
        return ((pair*)q)->Rv - ((pair*)p)->Rv;
    }else{
        return ((pair*)q)->Tv - ((pair*)p)->Tv;
    }
}

/*unsigned long long pascal[100][100] = {0};
void make_pascal(void){
    for (int i = 0; i < 100; i++){
        pascal[i][0] = 1;
    }
    pascal[1][1] = 1;
    for (int i = 2; i < 100; i++){
        for (int j = 1; j < 100; j++){
           pascal[i][j] = (pascal[i-1][j-1]+pascal[i-1][j]);
        }
    }
}*/

pair v[200005];
int cnt1 = 1;
int cnt2 = 1;

int n, k, l;
int Rhead[200005];
int Thead[200005];
int Rto[200005];
int Tto[200005];
int Rnext[200005];
int Tnext[200005];
int Rv[200005] = {0};
int Tv[200005] = {0};
int ans[200005] = {0};
int i;
int stack[200005];
int head = 0;


int Rdfs(int crt){
    int edge = Rhead[crt];
    while (edge != -1){
        if (v[Rto[edge]].Rv == 0){
            v[Rto[edge]].Rv = cnt1;
            Rdfs(Rto[edge]);
        }
        edge = Rnext[edge];
    }
    return 0;
}

int Tdfs(int crt){
    int edge = Thead[crt];
    while (edge != -1){
        if (v[Tto[edge]].Tv == 0){
            v[Tto[edge]].Tv = cnt2;
            Tdfs(Tto[edge]);
        }
        edge = Tnext[edge];
    }
    return 0;
}


int main(void){
    for (int i = 1; i < 200005; i++){
        Rhead[i] = -1;
        Thead[i] = -1;
        v[i].Rv = 0;
        v[i].Tv = 0;
        v[i].node = i;
    }
    scanf("%d %d %d", &n, &k, &l);
    int p, q;
    for (int i = 0; i < k*2; i += 2){
        scanf("%d %d", &p, &q);
        Rnext[i] = Rhead[p];
        Rhead[p] = i;
        Rto[i] = q;

        Rnext[i+1] = Rhead[q];
        Rhead[q] = i+1;
        Rto[i+1] = p;
    }

    for (int i = 0; i < l*2; i += 2){
        scanf("%d %d", &p, &q);
        Tnext[i] = Thead[p];
        Thead[p] = i;
        Tto[i] = q;

        Tnext[i+1] = Thead[q];
        Thead[q] = i+1;
        Tto[i+1] = p;
    }

    for (int i = 1; i <= n; i++){
        if (v[i].Rv == 0){
            Rdfs(i);
            if (v[i].Rv == 0) v[i].Rv = cnt1;
            cnt1++;
        }
        if (v[i].Tv == 0){
            Tdfs(i);
            if (v[i].Tv == 0) v[i].Tv = cnt2;
            cnt2++;
        }
    }
    qsort(v, n+1, sizeof(pair), struct_ascending_compare);
    int rv = -1;
    int tv = -1;
    v[n].Rv = 1000000;
    v[n].Tv = 1000000;

    for (int i = 0; i <= n; i++){
        if (rv != v[i].Rv || tv != v[i].Tv){
            rv = v[i].Rv;
            tv = v[i].Tv;
            if (head > 0){
                for (int j = 0; j < head; j++){
                    ans[stack[j]] = head;
                }
                head = 0;
            }
            stack[head] = v[i].node;
            head++;
        }else{
            stack[head] = v[i].node;
            head++;
        }
    }

    for (int i = 1; i <= n; i++){
        printf("%d\n", ans[i]);
    }
    

    return 0;



}
