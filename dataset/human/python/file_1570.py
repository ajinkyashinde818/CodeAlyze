import sys
stdin = sys.stdin
def na():
    return map(int,stdin.readline().split())
def ns():
    return stdin.readline().strip()
N, M = na()
a = []
b = []

for i in range(N):
    a.append(ns())
for i in range(M):
    b.append(ns())

for i in range(N-M+1):
    for j in range(N-M+1):
        flag = True
        for k in range(M):
            if a[i+k][j:j+M] != b[k]:
                flag = False
                break
        if flag:
            print("Yes")
            sys.exit(0)
print("No")
