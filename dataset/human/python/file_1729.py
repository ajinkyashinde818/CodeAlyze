N,M=map(int,input().split())
A=[ list(input()) for i in range(N)]
B=[ list(input()) for i in range(M)]
def match(x,y):
    for i in range(M):
        for j in range(M):
            if A[x+i][y+j]!=B[i][j]:
                return False
    return True
found=False
for i in range(N-M+1):
    for j in range(N-M+1):
        if match(i,j):
            found=True
            break
if found:
    print('Yes')
else:
    print('No')
