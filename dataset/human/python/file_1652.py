def input_li():
    return list(map(int, input().split()))

def input_int():
    return int(input())

N, M = input_li()
A_LI = []
B_LI = []
for _ in range(N):
    A_LI.append(input())
for _ in range(M):
    B_LI.append(input())
for i in range(N - M + 1):
    for j in range(N - M + 1):
        is_ok = True
        for col in range(M):
            for row in range(M):
                if B_LI[col][row] != A_LI[i + col][j + row]:
                    is_ok = False
                    break
            if not is_ok:
                break
        if is_ok:
            print('Yes')
            exit()
print('No')
