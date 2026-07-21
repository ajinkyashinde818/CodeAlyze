import sys
k, n = [int(i) for i in sys.stdin.readline().split()]
a_ls = [int(i) for i in sys.stdin.readline().split()]
a_ls += [i + k for i in a_ls]
best = 10**18
for i in range(n):
    best = min(best, a_ls[i+n-1] - a_ls[i])
print(best)
