from bisect import bisect_left
import sys
input = sys.stdin.buffer.readline


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))


ans = 0
for keta in range(0, 29)[::-1]:
    MOD = 1 << (keta + 1)
    T = 1 << keta
    for i in range(n):
        a[i] %= MOD
        b[i] %= MOD
    a.sort(reverse=True)
    b.sort()

    # T <= a[i] + b[j] < 2T もしくは 3T <= a[i] + b[j] < 4T
    # を満たすi, jの組の個数を尺取り法で探す
    T1 = [0] * n
    l = 0
    for i in range(n):
        while l < n and a[i] + b[l] < T:
            l += 1
        T1[i] = l

    T2 = [0] * n
    l = 0
    for i in range(n):
        while l < n and a[i] + b[l] < 2 * T:
            l += 1
        T2[i] = l

    T3 = [0] * n
    l = 0
    for i in range(n):
        while l < n and a[i] + b[l] < 3 * T:
            l += 1
        T3[i] = l

    T4 = [0] * n
    l = 0
    for i in range(n):
        while l < n and a[i] + b[l] < 4 * T:
            l += 1
        T4[i] = l

    cnt = 0  
    for i in range(n):
        cnt += (T2[i] - T1[i]) + (T4[i] - T3[i])

    # i, jの組の個数が奇数だったら、xorしたときにTが残る
    if cnt % 2 == 1:
        ans += T

print(ans)
