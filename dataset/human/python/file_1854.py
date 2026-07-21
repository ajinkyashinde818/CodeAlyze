N, M = map(int, input().split())
A = []
for _ in [0]*N:
    A.append(list(input().rstrip()))
B = []
for _ in [0]*M:
    B.append(list(input().rstrip()))

def check(x, y):
    for s in range(M):
        for t in range(M):
            if A[x+s][y+t] == B[s][t]:
                continue
            else:
                return False
    return True

def main():
    for x in range(N-M+1):
        for y in range(N-M+1):
            if check(x, y):
                print('Yes')
                return
    print('No')
    return

main()
