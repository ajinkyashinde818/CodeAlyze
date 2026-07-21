from sys import stdin
K, N = [int(x) for x in stdin.readline().rstrip().split()]
l = [int(x) for x in stdin.readline().rstrip().split()]

l.sort()

l2 = []

for i in range(N-1):
    l2.append(l[i+1] - l[i])

l2.append(l[0] + K - l[N-1])

ans = K - max(l2)

print(ans)
