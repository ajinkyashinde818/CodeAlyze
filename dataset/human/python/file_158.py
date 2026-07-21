import sys
r, g, b, n = [int(i) for i in sys.stdin.readline().split()]
memo_ls = [[0 for j in range(n+1)] for i in range(4)]
memo_ls[0][0] = 1
for i, color in enumerate(sorted([r, g, b]), 1):
    for j in range(n + 1):
        if j >= color:
            memo_ls[i][j] = memo_ls[i-1][j] + memo_ls[i][j-color]
        else:
            memo_ls[i][j] = memo_ls[i-1][j]
print(memo_ls[-1][-1])
