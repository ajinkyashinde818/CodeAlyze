from collections import defaultdict

n, k = map(int, input().split())
*a, = map(int, input().split())
a = [a[i] - 1 for i in range(n)]
ans = 0

if k <= n:
    i = 0
    while(k > 0):
        ans = a[i]
        i = a[i]
        k -= 1
    ans += 1

else:
    # 周期と周期の場所をチェック
    start_period = 1
    period_i = -1
    # 街名に対する初めて訪れる順番の辞書
    d = defaultdict(int)
    d[0] = 1
    i = 0
    count = 1
    while(1):
        if a[i] in d.keys():
            period_i = count
            start_period = d[a[i]]
            break

        d[a[i]] = count + 1
        i = a[i]
        count += 1
        
    # 初めて訪れる順番に対する街名の逆引き辞書
    d_r = {i:k for k, i in d.items()}

    ans = d_r[start_period + ((k - (start_period - 1)) % (period_i - start_period + 1))] + 1
    
    
print(ans)
