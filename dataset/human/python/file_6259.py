import sys
input = sys.stdin.readline

a = ['0'] + list(input())
n = len(a)-1
for i in range(n):
    a[i] = int(a[i])

res = 0
for i in range(n-1,-1,-1):
    if a[i] <= 4:
        res += a[i]
    elif a[i] == 5:
        if a[i-1] >= 5:
            res += 5
            a[i-1] += 1
        else:
            res += 5

    else:
        res += 10-a[i]
        a[i-1] += 1
print(res)
