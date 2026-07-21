import sys
input = sys.stdin.readline
d, g = map(int, input().split())
pc = []
for i in range(d):
    p, c = map(int, input().split())
    pc.append([p, c // 100])
g = g // 100
ans = 1000
for i in range(2 ** d):
    rem = g
    cost = 0
    for j in reversed(range(d)):
        if ((i >> j) & 1):
            p, c = pc[j]
            rem -= c + p * (j + 1)
            cost += p
    for j in reversed(range(d)):
        if  not ((i >> j) & 1):
            p, c = pc[j]
            p -= 1
            if rem >= p * (j + 1):
                rem -= p * (j + 1)
                cost += p
            else:
                while rem > 0:
                    rem -= j +1
                    cost += 1
                break
    if rem <= 0:
        ans = min(cost, ans)
print(ans)
