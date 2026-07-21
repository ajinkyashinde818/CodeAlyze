import sys
n, m = map(int, input().split())
n_list = [list(input()) for i in range(n)]
m_list = [list(input()) for i in range(m)]

def bunkatu(x, y):
    global n_list
    lis = []
    for i in range(y, y + m):
        lis.append(n_list[i][x: x + m])
    return lis

for j in range(n - m + 1):
    for i in range(n - m + 1):
        tmp = bunkatu(i, j)
        if m_list == tmp:
            print('Yes')
            sys.exit(0)
print('No')
