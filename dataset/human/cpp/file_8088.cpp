#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> num(n);

    long long total_sum = 0;
    long long sum = 0;

    for(int i = 0; i < n ; i++){
        scanf("%d", &num[i]);
        total_sum += num[i];
    }

    long long best_delta = 1000000000000;

    for(int i = 0; i < n - 1; i++){
        sum += num[i];

        if(abs(sum - (total_sum - sum)) < best_delta)
            best_delta = abs(sum - (total_sum - sum));
    }

    printf("%lld", best_delta);

    return 0;
}
