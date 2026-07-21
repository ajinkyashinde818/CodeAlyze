import numpy as np
N, M = map(int, input().split())

A = []
for i in range(N):
    tmp = input()
    A.append([0 if s=="." else 1 for s in tmp])
B = []
for i in range(M):
    tmp = input()
    B.append([0 if s=="." else 1 for s in tmp])
    
A = np.array(A)
B = np.array(B)

def is_match(a, b):
    return (a==b).all()
flag = False
for i in range(N):
    for j in range(N):
        x_left = i
        x_right = i + M
        y_up = j
        y_under = j + M
        if x_right > N or y_under > N:
            continue
        if is_match(B, A[x_left:x_right, y_up:y_under]):
            flag = True
if flag:
    print("Yes")
else:
    print("No")
