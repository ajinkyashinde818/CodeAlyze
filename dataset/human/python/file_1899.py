import sys

N, M = map(int, input().split())
A = []
B = []

for i in range(0, N):
    Ai = input()
    A.append(Ai)

for i in range(0, M):
    Bi = input()
    B.append(Bi)

found = True
for i_offset in range(0, N-M+1):
    found = True
    j_offset = A[i_offset].find(B[0])
    if j_offset < 0:
        continue
    for i in range(0, M):
        if A[i+i_offset][j_offset:j_offset+M] != B[i][0:M]:
            found = False
            break
    if found:
        print("Yes")
        sys.exit()

print("No")
