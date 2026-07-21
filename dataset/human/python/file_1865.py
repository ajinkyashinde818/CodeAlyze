N, M = [int(i) for i in input().split()]
A = [[i for i in list(input())] for _ in range(N)]
B = [[i for i in list(input())] for _ in range(M)]

k = (N-1)-(M-1)+1

def judge(x, y):
    for i in range(M):
        for j in range(M):
            if not(A[x+i][y+j]==B[i][j]):
                return False
    return True


for i in range(k):
    for j in range(k):
        if judge(i, j):
            print("Yes")
            quit()

print("No")
