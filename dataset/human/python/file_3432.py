from bisect import bisect_right
import sys

N = int(input())


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-(n ** 0.5) // 1)) + 1):
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


S = [0]
now = 0
for i in range(1, 60):
    S.append(i * (i + 1) // 2)
# print(S)

fact_list = factorization(N)
# fact_list = sorted(fact_list, reverse=True)
# print(fact_list)
if fact_list == [[1, 1]]:
    print(0)
    sys.exit()
ans = 0
while fact_list:
    now_fact = fact_list.pop()
    idx = bisect_right(S, now_fact[1])
    ans += idx - 1

print(ans)
