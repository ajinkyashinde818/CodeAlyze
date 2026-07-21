n, m = map(int, input().split())
A = [list(map(str,list(input()))) for i in range(n)] 
B = [list(map(str,list(input()))) for i in range(m)] 
def move(h,w):
    cnt = 0
    for i in range(m):
        for j in range(m):
            if B[i][j] == A[i+h][j+w]:
                cnt += 1
    return cnt
flg = 0
for i in range(n-m+1):
    for j in range(n-m+1):
        if move(i,j)==m*m:
            flg = 1
            break
if flg == 1:
    print('Yes')
else:
    print('No')
