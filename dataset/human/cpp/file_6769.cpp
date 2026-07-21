#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200005;

int n;
int a[N], b[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ) cin >> b[n - i]; // 读入并将 B 翻转
    
    bool success = true; // 标记是否有合法的 B 的重排
    
    // 找第一个 a[i] == b[i] 的 i
    // 如果找到之后 success 被更新成 false 了，直接跳出
    for (int i = 1; i <= n && success; i ++ )
        if (a[i] == b[i])
        {
            // 这里要试图将 B 和 A 中相等的一段，用 B 的其它元素替换掉
            // 如果 a[i] 和 b[i] 不相等了，说明是 B 中和 A 相等的部分替换完了，直接跳出
            for (int k = 1; k <= n && a[i] == b[i]; k ++ )
            // 如果找到了 B 中的一个元素 b[k], 满足将 b[k] 与 b[i] 交换之后， a[k] != b[k] 且 a[i] != b[i]，
                if (b[k] != b[i] && a[k] != b[i])
                    swap(b[i], b[k]), i ++ ; // 那么将 b[i] 与 b[k] 交换，并让 i 走到下一个要替换的位置

            // 如果试图替换后 b[i] 仍与 a[i] 相同，说明不存在一组合法答案，让 success = false
            if (a[i] == b[i]) success = false;
        }

    puts(success ? "Yes" : "No");
    if (success) for (int i = 1; i <= n; i ++ ) cout << b[i] << ' '; 

    return 0;
}
