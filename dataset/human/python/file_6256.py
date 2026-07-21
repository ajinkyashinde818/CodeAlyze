import sys
readline = sys.stdin.readline

N = readline().rstrip()
N = list(map(int, N))
L = len(N)

total = 0

for i in range(L - 1, -1, -1):
    k = N[i]
    if k <= 4:
        total += k
    elif k >= 6:
        total += 10 - k
        if i == 0:
            total += 1
        else:
            N[i - 1] += 1
    else:
        if i == 0:
            total += k
        else:
            if N[i - 1] <= 4:
                total += k
            else:
                total += 10 - k
                N[i - 1] += 1

print(total)
