from collections import deque
S = deque(input())
Q = int(input())
flag = True
for i in range(Q):
    A = list(map(str, input().split()))
    if len(A)==1:
        flag = not flag
    else:
        if flag:
            if A[1]=="1":
                S.appendleft(A[2])
            else:
                S.append(A[2])
        else:
            if A[1]=="1":
                S.append(A[2])
            else:
                S.appendleft(A[2])
S = "".join(S)
if flag:
    print(S)
else:
    print(S[::-1])
