n, m = map(int, input().split())
a = [list(input()) for i in range(n)]
b = [list(input()) for i in range(m)]

def chk(upper, left):
    for i in range(m):
        for j in range(m):
            if a[i+upper][j+left] != b[i][j]:
                return False
    return True

f = False
for upper in range(n-m+1):
    for left in range(n-m+1):
        if chk(upper, left):
            print('Yes')
            f = True
            break
    if f:
        break
if not f:
    print('No')
