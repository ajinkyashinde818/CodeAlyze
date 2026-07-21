import bisect

N = int(input())
if N==1:
    print(0)
    exit()

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5 // 1)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr


l = factorization(N)

a = [i * (i + 1) // 2 for i in range(2 * 10**6)]
ans = 0


for p in l:
    n = bisect.bisect_right(a, p[1]) - 1
    ans += n

print(ans)
