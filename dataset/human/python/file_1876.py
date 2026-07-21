def mtx2vec(mtx):
    tmp = ''
    for s in mtx:
        tmp += s
    return tmp
N, M = map(int, input().split())
A = []
B = []
for _ in range(N):
    A.append(input())
for _ in range(M):
    B.append(input())

b = ''
for s in B:
    b += s
ans = 'No'
for i in range(N-M+1):
    for j in range(N-M+1):
        tmp = ''
        for k in range(M):
            tmp += A[i+k][j:j+M]
        if tmp == b:
            ans =  'Yes'
            break
print(ans)
