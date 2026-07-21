def is_equal(i,j,m):
    d = 0
    for k in range(m):
        if a[i+k][0][j:j+m] == b[k][0][::]:
            d = 0
        else:
            return False
    if d == 0:
        return True

n,m = map(int,input().split())
a = [0]*n
b = [0]*m
for i in range(n):
    a[i] = list(input().split())
for i in range(m):
    b[i] = list(input().split())

for i in range(n-m+1):
    ans = 0
    for j in range(n-m+1):
        if is_equal(i,j,m):
            ans =1
            break
    if ans == 1:
        break
if ans == 1:
    print('Yes')
else:
    print('No')
