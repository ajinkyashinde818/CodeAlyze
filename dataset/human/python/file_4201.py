def CountTimesforT(N, T):
    t = T
    count = 0
    while N % t == 0:
        count += 1
        N //= t
        t *= T
    while N % T == 0:
        N //= T
    return [count, N]

N = int(input())
M = int(pow(N, 0.5)) + 2
ans = 0
if N != 1:
    for i in range(2, M):
        if N % i == 0:
            l = CountTimesforT(N, i)
            N = l[1]
            ans += l[0]
    if N != 1:
        ans += 1
print(ans)
