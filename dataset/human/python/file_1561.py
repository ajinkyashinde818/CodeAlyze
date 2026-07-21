def subImage(x,y,M,A):
    C = []
    for i in range(M):
        C.append(A[x+i][y:y+M])
    return C
    
def containIm(N,M,A,B):
    judge = 0    
    for x in range(N-M+1):
        for y in range(N-M+1):
            C = subImage(x,y,M,A)
            if C == B:
                judge = 1
                return judge
    return judge
    

# 入力
N,M = map(int,input().split())
A = []
B = []
for i in range(N):
    A.append(input())
for i in range(M):
    B.append(input())

judge = containIm(N,M,A,B)
if judge == 1:
    print('Yes')
else:
    print('No')
