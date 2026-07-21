#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

int main()
{
    long long right[100010];
    long long left[100010];
    long long n,c;
    cin >> n >> c;
    long long x[100010];
    long long v[100010];
    for(int i = 1; i <= n; i++){
        cin >> x[i];
        cin >> v[i];
    }
    long long x_left[100010];
    long long v_left[100010];
    for(int i = 1; i <= n; i++){
        x_left[i] = c - x[n + 1- i];
        v_left[i] = v[n + 1- i];
    }
    right[0] = 0;
    left[0] = 0;
    x[0] = 0;
    x_left[0] = 0;
    long long answer = 0;
    long long right_zahyou[100010];
    long long left_zahyou[100010];
    long long right_plus[100010];
    long long left_plus[100010];
    right_zahyou[0] = 0;
    left_zahyou[0] = 0;
    right_plus[0] = 0;
    left_plus[0] = 0;
    for(int i = 1; i <= n; i++){
        right[i] = right[i - 1] + v[i] - (x[i] - x[i - 1]);
        left[i] = left[i - 1] + v_left[i] - (x_left[i] - x_left[i - 1]);
        right_zahyou[i] = x[i];
        left_zahyou[i] = x_left[i];
        right_plus[i] = max(right_plus[i - 1], right[i] - right_zahyou[i]);
        left_plus[i] = max(left_plus[i - 1], left[i] - left_zahyou[i]);
        //cout << left[i] << endl;
    }
    for(int i = 1; i <= n; i++){
        //cout << right[i] << " " << right_plus[i] << " " << right_zahyou[i] << endl;
    }
    for(int i = 1; i <= n; i++){
        right[i] += left_plus[n - i];
        left[i] += right_plus[n - i];
        //cout << right[i] << " " << left[i] << endl;
        answer = max(answer, left[i]);
        answer = max(answer, right[i]);
    }
    cout << answer << endl;
    return 0;
}
