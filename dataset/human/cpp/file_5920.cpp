#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long N, C;
    scanf("%lld %lld", &N, &C);
    std::vector<long long> x(N), v(N);
    for(int i=0; i<N; i++) scanf(" %lld %lld", &x[i], &v[i]);

    std::vector<long long> left(N), right(N), left_back(N), right_back(N);
    left[0] = v[0] - x[0];
    right[0] = v[N-1] - (C - x[N-1]);
    left_back[0] = left[0] - x[0];
    right_back[0] = right[0] - (C - x[N-1]);
    for(int i=1; i<N; i++){
        left[i] = left[i-1] + v[i] - (x[i] - x[i-1]);
        right[i] = right[i-1] + v[N-1-i] - (x[N-i] - x[N-1-i]);
        left_back[i] = left[i] - x[i];
        right_back[i] = right[i] - (C - x[N-i-1]);
    }
    
    if(left[0] < 0) left[0] = 0;
    if(right[0] < 0) right[0] = 0;
    for(int i=1; i<N; i++){
        left[i] = std::max(left[i-1], left[i]);
        right[i] = std::max(right[i-1], right[i]);
        left_back[i] = std::max(left_back[i-1], left_back[i]);
        right_back[i] = std::max(right_back[i-1], right_back[i]);
    }

    long long max = 0;
    for(int i=0; i<N-1; i++){
        if(max < left[i] + right_back[N-i-2]) max = left[i] + right_back[N-i-2];
        if(max < right[i] + left_back[N-i-2]) max = right[i] + left_back[N-i-2];
    }
    if(max < left[N-1]) max = left[N-1];
    if(max < right[N-1]) max = right[N-1];
    
    printf("%lld\n", max);
}
