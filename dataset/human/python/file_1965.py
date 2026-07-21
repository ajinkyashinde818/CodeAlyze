n, m = map(int, input().split())
a = [[i for i in input()] for j in range(n)]
b = [[i for i in input()] for j in range(m)]

def match(y,x):
    result = True
    for i in range(m):
        for j in range(m):
            if a[y+i][x+j] != b[i][j]:
                result = False
    return result

flg = False
for i in range(n-m+1):
    for j in range(n-m+1):
        if match(i,j):
            flg = True

print('Yes' if flg else 'No')
