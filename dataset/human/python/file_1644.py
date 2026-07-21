from itertools import product


N,M=map(int,input().split())
A=[input() for _ in range(N)]
B=[input() for _ in range(M)]
for sx, sy in product(range(N-M+1), repeat=2):
    is_ok = 1
    for x in range(sx, sx+M):
        for y in range(sy, sy+M):
            if B[x-sx][y-sy] != A[x][y]:
                is_ok=0
                break
        if not is_ok:
            break
    if is_ok:
        print("Yes")
        exit()

print("No")
