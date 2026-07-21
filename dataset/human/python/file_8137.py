from sys import stdin
K, S = map(int, stdin.readline().rstrip().split())
l = list(i for i in range(K+1))
count = 0
for i in range(K+1):
    for j in range(K+1):
        z = S - i - j
        if 0 <= z <= K:
            count += 1
print(count)
