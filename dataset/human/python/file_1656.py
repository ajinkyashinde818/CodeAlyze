from sys import exit

N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]

def valid(i, j):
    for a, b in zip(A[i:i+M], B):
        if a[j:j+M] == b:
            continue
        else:
            return False
    return True
if N > M:
    for i in range(N-M):
        for j in range(N-M):
            if valid(i, j):
                print("Yes")
                exit()
else:
    if valid(0,0):
        print("Yes")
        exit()
print("No")
