def check(A: list, B: list, start: (int, int)) -> bool:
    B_len = len(B)
    for b_pos_y, a_pos_y in enumerate(range(start[0], start[0]+B_len)):
        for b_pos_x, a_pos_x in enumerate(range(start[1], start[1]+B_len)):
            #print(f'{A[a_pos_y][a_pos_x]=} {B[b_pos_y][b_pos_x]=}')
            if A[a_pos_y][a_pos_x] != B[b_pos_y][b_pos_x]:
                return False
    return True



N, M = map(int, input().split())
A = [[[] for _ in range(N)] for _ in range(N)]
B = [[[] for _ in range(M)] for _ in range(M)]

for i in range(N):
    A[i] = list(input())

for i in range(M):
    B[i] = list(input())

scope = N - M + 1

possible = False
for i in range(scope):
    for j in range(scope):
        if check(A, B, (i, j)) == True:
            possible = True
            break

if possible:
    print('Yes')
else:
    print('No')
