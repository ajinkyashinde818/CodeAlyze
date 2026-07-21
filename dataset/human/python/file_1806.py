N, M = [int(x) for x in input().split()]

A = [None]*N
for i in range(N):
    A[i] = input()

B = [None]*M
for i in range(M):
    B[i] = input()

def check():
    for x in range(N-M+1):
        for y in range(N-M+1):
            match = True
            for r in range(M):
                if not all(A[r+x][c+y] == B[r][c] for c in range(M)):
                    match = False
                    break
            if match:
                return "Yes"

    return "No"
print(check())
