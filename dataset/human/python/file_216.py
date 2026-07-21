import math

n = int(input())
k = round((1 + math.sqrt(1 + 8 * n)) / 2)

if k * (k - 1) == 2 * n:
    print("Yes")
    ss = [[0 for j in range(k - 1)] for i in range(k)]

    cnt = 1
    for i in range(1, k):
        for j in range(k - i):
            ss[i - 1][i + j - 1] = cnt
            ss[i + j][i - 1] = cnt
            cnt += 1

    print(k)
    for s in ss:
        print(k - 1, " ".join([str(i) for i in s]))
else:
    print("No")
