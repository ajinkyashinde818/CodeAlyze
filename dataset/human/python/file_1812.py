import sys
n, m = [int(i) for i in sys.stdin.readline().split()]
a_ls = []
b_ls = []
for i in range(n):
    a_ls.append(sys.stdin.readline().strip())
for i in range(m):
    b_ls.append(sys.stdin.readline().strip())

def matching(a, b, size, start):
    start_y, start_x = start
    flg = True
    for i in range(size):
        for j in range(size):
            flg &= a[start_y + i][start_x + j] == b[i][j]
            if not flg:
                return flg
    return flg

res = False
for i in range(n - m + 1):
    for j in range(n - m + 1):
        res |= matching(a_ls, b_ls, m, (i, j))
        if res:
            break
    if res:
        break
print("Yes" if res else "No")
