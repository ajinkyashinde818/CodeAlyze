import bisect


def factorization(n):
    arr = dict()
    temp = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr[i] = cnt

    if temp != 1:
        arr[temp] = 1

    if not arr and n != 1:
        arr[n] = 1

    return arr


N = int(input())

tri = [i * (i + 1) // 2 for i in range(1, 50)]
ans = 0
for v in factorization(N).values():
    ans += bisect.bisect_right(tri, v)
print(ans)
