def check(i,j):
    for y in range(M):
        for x in range(M):
            if A[i+y][j+x] != B[y][x]:
                return False
    return True
    
[N,M] = list(map(int,input().split()))
A = [input() for i in range(N)]
B = [input() for i in range(M)]
ans = "No"
for i in range(N-M+1):
    for j in range(N-M+1):
        if check(i,j):
            ans = "Yes"
print(ans)
