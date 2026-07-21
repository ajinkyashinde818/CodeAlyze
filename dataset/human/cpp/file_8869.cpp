#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <array>
#include <utility>
#include <valarray>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);
    vector<vector<char>> A(N, vector<char>(N));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j) A[i][j] = getchar();
        getchar();
    }
    vector<vector<char>> B(M, vector<char>(M));
    for (int i = 0; i < M; ++i){
        for (int j = 0; j < M; ++j) B[i][j] = getchar();
        getchar();
    }
    for (int i = 0; i <= N - M; ++i){
        for (int j = 0; j <= N - M; ++j){
            bool flag = true;
            for (int y = 0; y < M; ++y){
                for (int x = 0; x < M; ++x){
                    if (A[i + y][j + x] != B[y][x]){
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}
