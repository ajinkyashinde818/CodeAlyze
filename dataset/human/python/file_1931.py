N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]
flg=False

def check(i, j):
    cnt=0
    for k in range(M):
        for l in range(M):
            if A[i+k][j+l] == B[k][l]:
                cnt += 1
    if cnt==M**2:
        return True
    
for i in range(N-M+1):
    for j in range(N-M+1):
        if A[i][j] == B[0][0]:
            flg = check(i, j)
            if flg:
                break
    if flg:
        break
            
ans='Yes' if flg else 'No'
print(ans)
