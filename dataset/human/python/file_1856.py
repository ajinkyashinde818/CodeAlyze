N, M = map(int, input().split())
A = []
B = []
for i in range(N):
    A.append(str(input()))
for i in range(M):
    B.append(str(input()))

def check(i, j, A, B, M):
    for k in range(M):
        if A[i+k][j:j+M] != B[k]:
            return False
    return True 

def Main(N, M, A, B):
    for i in range(N-M+1):
        for j in range(N-M+1):
            if A[i][j] == B[0][0]:
                if check(i, j, A, B, M):
                    return 'Yes'
    return "No"     
    
res = Main(N, M, A, B)
print(res)
